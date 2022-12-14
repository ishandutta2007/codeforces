#include <cstdio>
#include <cstdlib>
#include <algorithm>

typedef long long i64;

const int N = 5000 + 10, MOD = 1000000007;

int n, a, b, k;

int f[N][N];

int main() {
  scanf("%d%d%d%d", &n, &a, &b, &k);
  f[0][a] = 1;
  for (int i = 0; i < k; ++i) {
    for (int x = 1; x <= n; ++x) {
      int t = abs(x - b), cur = f[i][x];
      //|x - y| < t
      //x - y < t, y - x < t
      //x - t < y < x + t
      int l = std::max(x - t + 1, 1), r = std::min(x + t - 1, n);
      if (l <= r) (f[i + 1][l] += cur) %= MOD, (f[i + 1][r + 1] -= cur) %= MOD;
      if (l <= x && x <= r) (f[i + 1][x] -= cur) %= MOD, (f[i + 1][x + 1] += cur) %= MOD;
    }
    for (int j = 1; j <= n; ++j) (f[i + 1][j] += f[i + 1][j - 1]) %= MOD;
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) (ans += f[k][i]) %= MOD;
  printf("%d\n", (ans + MOD) % MOD);
  return 0;
}