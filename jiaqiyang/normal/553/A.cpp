#include <cstdio>

typedef long long i64;

const int N = 1000 + 10, MOD = 1000000007;

int n, c[N], sum[N];

int f[N], binom[N][N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &c[i]), sum[i] = sum[i - 1] + c[i];
  f[0] = binom[0][0] = 1;
  for (int i = 1; i < N; ++i)
    for (int j = 0; j < N; ++j)
      binom[i][j] = (binom[i - 1][j] + (j ? binom[i - 1][j - 1] : 0)) % MOD;
  for (int i = 1; i <= n; ++i) f[i] = (i64)f[i - 1] * binom[sum[i] - 1][c[i] - 1] % MOD;
  printf("%d\n", f[n]);
  return 0;
}