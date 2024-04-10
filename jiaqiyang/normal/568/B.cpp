#include <iostream>

typedef long long i64;

const int N = 4000 + 10, MOD = 1000000007;

int n;
int f[N][N], binom[N][N], b[N];

int main() {
  std::cin >> n;
  f[0][0] = binom[0][0] = b[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      f[i][j] = ((j ? f[i - 1][j - 1] : 0) + (i64)j * f[i - 1][j]) % MOD;
      binom[i][j] = (binom[i - 1][j] + (j ? binom[i - 1][j - 1] : 0)) % MOD;
      b[i] = (b[i] + f[i][j]) % MOD;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) ans = (ans + (i64)binom[n][i] * b[i]) % MOD;
  std::cout << ans << '\n';
  return 0;
}