#include <cstdio>
#include <algorithm>

typedef long long i64;

const int N = 300000 + 10, MOD = 1000000007;

int n, x[N];
int p[N];

int main() {
  p[0] = 1;
  for (int i = 1; i < N; ++i) p[i] = 2LL * p[i - 1] % MOD;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &x[i]);
  std::sort(x + 1, x + n + 1);
  int ans = 0;
  for (int i = 1; i < n; ++i) ans = (ans + (x[i + 1] - x[i]) * (p[i] - 1LL) % MOD * (p[n - i] - 1LL)) % MOD;
  printf("%d\n", (ans + MOD) % MOD);
  return 0;
}