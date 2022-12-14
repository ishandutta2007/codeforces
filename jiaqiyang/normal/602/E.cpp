#include <cstdio>

const int N = 100 + 10, M = 1000 + 10;

int n, m, x[N];
double f[2][N * M];

int main() {
  scanf("%d%d", &n, &m);
  if (m == 1) {
    puts("1.0");
    return 0;
  }
  int tot = 0;
  for (int i = 1; i <= n; ++i) scanf("%d", x + i), tot += x[i];
  f[0][0] = 1.0;
  for (int i = 1; i <= n; ++i) {
    int c = i & 1;
    static double g[N * M];
    for (int j = 0; j <= i * m; ++j) g[j] = f[!c][j];
    for (int j = 1; j <= i * m; ++j) g[j] += g[j - 1];
    for (int j = 0; j <= i * m; ++j)
      f[c][j] = ((j - 1 >= 0 ? g[j - 1] : 0.0) - (j - m - 1 >= 0 ? g[j - m - 1] : 0.0) - (j - x[i] >= 0 ? f[!c][j - x[i]] : 0.0)) / (m - 1.0);
  }
  double ans = 0.0;
  for (int i = 0; i < tot; ++i) ans += f[n & 1][i] * (m - 1.0);
  printf("%.16f\n", ans + 1.0);
  return 0;
}