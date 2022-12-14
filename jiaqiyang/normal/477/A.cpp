#include <cstdio>

typedef long long i64;

const int MOD = 1000000007;

int a, b;

int solve(int x) {
  int res = a * (a + 1LL) / 2 % MOD * x % MOD * b % MOD;
  res = (res + (i64)a * x) % MOD;
  return res;
}

int main() {
  scanf("%d%d", &a, &b);
  int ans = 0;
  for (int i = 1; i < b; ++i) (ans += solve(i)) %= MOD;
  printf("%d\n", ans);
  return 0;
}