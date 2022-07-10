#include <stdio.h>
#include <immintrin.h>
#include <stdint.h>

void pa(void *pointer) {
  printf("%d ", (uint64_t)pointer % 32);
}

int main()
{
  float _tt[8];
  float a[8] __attribute__ ((aligned (32)));
  float b[8] __attribute__ ((aligned (32)));
  float na_a[8];
  float na_b[8];
  float _t[4];
  float t[8];

  pa(_tt); pa(a); pa(b); pa(na_a); pa(na_b); pa(t);
  printf("\n");

  printf("%d %d\n", (uint64_t)&na_a[7], (uint64_t)&na_b[0]);

  for (int i = 0; i < 8; i++)
    b[i] = 7 - (a[i] = i);

  __m256 _a = _mm256_load_ps(a);
  __m256 _b = _mm256_load_ps(b);

  __m256 c = _mm256_add_ps(_a, _b);

  for (int i = 0; i < 8; i++)
    printf("%f ", c[i]);
  printf("\n");

  printf("Hello, world!\n");
}
