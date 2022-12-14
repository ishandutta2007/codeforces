#include <cstdio>
#include <algorithm>

typedef long long i64;

int main() {
  int tcase;
  for (scanf("%d", &tcase); tcase--;) {
    i64 l, r;
    scanf("%lld%lld", &l, &r);
    if (l == r) {
      printf("%lld\n", r);
      continue;
    }
    int p = 63 - __builtin_clzll(l ^ r);
    i64 temp = 0;
    for (int i = 63; i > p; --i) if (l >> i & 1) temp |= 1LL << i;
    i64 a = (1LL << p) - 1, b = (1LL << (p + 1)) - 1;
    a |= temp, b |= temp;
    if (l <= b && b <= r) a = b;
    printf("%lld\n", a);
  }
  return 0;
}