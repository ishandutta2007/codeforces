#include <cstdio>

typedef long long i64;

const int N = 60;

i64 s, x;

i64 count() {
  i64 t = s;
  i64 res = 1;
  int flag = 2;
  for (int i = N - 1; i >= 0; --i)
    if (x >> i & 1)
      t -= (1LL << i), res *= 2;
    else if (t >= (1LL << (i + 1)))
      t -= (1LL << (i + 1)), flag = 0;
  if (t) return 0;
  return res - flag;
}

int main() {
  scanf("%I64d%I64d", &s, &x);
  printf("%I64d\n", count());
  return 0;
}