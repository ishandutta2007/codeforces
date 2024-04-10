#include <cstdio>
#include <numeric>
#include <algorithm>

const int N = 100 + 10, INF = 1 << 20;

int n, m, g[N][N];

int solve(int x, bool flag = false) {
  static int row[N], col[N];
  row[1] = x;
  for (int i = 1; i <= m; ++i) if ((col[i] = g[1][i] - x) < 0) return INF;
  for (int i = 2; i <= n; ++i) {
    static int temp[N];
    for (int j = 1; j <= m; ++j) temp[j] = g[i][j] - col[j];
    for (int j = 2; j <= m; ++j) if (temp[j] != temp[j - 1]) return INF;
    if (temp[1] < 0) return INF;
    row[i] = temp[1];
  }
  int ans = std::accumulate(row + 1, row + n + 1, std::accumulate(col + 1, col + m + 1, 0));
  if (flag) {
    printf("%d\n", ans);
    for (int i = 1; i <= n; ++i) for (int j = row[i]; j--;) printf("row %d\n", i);
    for (int i = 1; i <= m; ++i) for (int j = col[i]; j--;) printf("col %d\n", i);
  }
  return ans;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      scanf("%d", &g[i][j]);
  std::pair<int, int> ans(INF, -1);
  for (int i = 0; i <= 500; ++i) ans = std::min(ans, {solve(i), i});
  if (ans.second != -1) solve(ans.second, true); else puts("-1");
  return 0;
}