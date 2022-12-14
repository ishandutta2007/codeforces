#include <cstdio>

typedef long long i64;

i64 a, b;

int main() {
  scanf("%I64d%I64d", &a, &b);
  int ans = 0;
  for (int len = 1; len <= 63; ++len) {
    i64 s = (1LL << len) - 1;
    for (int i = 0; i + 1 < len; ++i) {
      i64 t = s ^ (1LL << i);
      if (a <= t && t <= b) ++ans;
    }
  }
  printf("%d\n", ans);
  return 0;
}