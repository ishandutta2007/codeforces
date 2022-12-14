#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long i64;

const int N = 100 + 10, MOD = 1000000007;

int n, m, p;

int mem[2][N][N][N], C[N][N];

int main() {
  scanf("%d%d%d", &n, &m, &p);
  C[0][0] = 1;
  for (int i = 1; i < N; ++i)
    for (int j = 0; j <= i; ++j)
      C[i][j] = std::min(C[i - 1][j] + (j ? C[i - 1][j - 1] : 0), N) % MOD;
  mem[1][1][0][1] = 1;
  int ans = 0;
  for (int mx = 1; mx <= m; ++mx) {
    const int c = mx & 1;
    memset(mem[!c], 0, sizeof mem[!c]);
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        for (int k = 1; k <= p; ++k) {
          int val = mem[c][i][j][k];
          if (!val) continue;
          mem[c][i][j][k] = 0;
          if (j)
            (ans += (i64)val * (m - mx + 1) % MOD) %= MOD;
          for (int x = 1; j + x * 2 <= n; ++x) {
            int tot = k * C[i + x - 1][x];
            if (tot > p) break;
            (mem[!c][x][j + x * 2][tot] += val) %= MOD;
          }
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}