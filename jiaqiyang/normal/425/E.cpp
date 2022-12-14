#include <cstdio>
#include <cstring>

typedef long long i64;

const int N = 500 + 10, MOD = 1000000007;

int n, m, f[N][N], power[N];

int main() {
  scanf("%d%d", &n, &m);
  power[0] = 1;
  for (int i = 1; i < N; ++i) power[i] = (power[i - 1] << 1) % MOD;
  f[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < i; ++j) {
      for (int k = 0; k <= m; ++k) {
        f[j][k] = (i64)f[j][k] * power[j] % MOD;
        (f[i][k + 1] += (i64)f[j][k] * (power[i - j] - 1) % MOD) %= MOD;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= n; ++i) (ans += f[i][m]) %= MOD;
  printf("%d\n", ans);
  return 0;
}