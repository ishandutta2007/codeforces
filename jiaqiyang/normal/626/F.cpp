#include <cstdio>
#include <algorithm>

typedef long long i64;

const int N = 200 + 10, M = 1000 + 10, MOD = 1000000007;

inline void add(int &lhs, int rhs) {
  lhs += rhs;
  if (lhs > MOD) lhs -= MOD;
}

int n, m, a[N];
int f[N][N][M];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  std::sort(a + 1, a + n + 1);
  f[0][0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < i; ++j) {
      for (int k = 0; k <= m; ++k) {
        int cur = f[i - 1][j][k];
        if (!cur) continue;
        int t = k + j * (a[i] - a[i - 1]);
        if (t > m) continue;
        add(f[i][j][t], cur);
        add(f[i][j + 1][t], cur);
        add(f[i][j][t], (i64)cur * j % MOD);
        if (j) add(f[i][j - 1][t], (i64)cur * j % MOD);
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= m; ++i) add(ans, f[n][0][i]);
  printf("%d\n", ans);
  return 0;
}