#include <cstdio>
#include <cstring>
#include <vector>

const int N = 300000 + 10;

int n, m;
std::vector<std::pair<int, int>> e[N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = m; i--;) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    e[w].push_back(std::pair<int, int>(u, v));
  }
  static int dp[N];
  for (int i = 0; i < N; ++i) {
    static int tmp[N];
    for (auto it = e[i].begin(); it != e[i].end(); ++it) {
      int u = it->first, v = it->second;
      tmp[v] = std::max(tmp[v], dp[u] + 1);
    }
    for (auto it = e[i].begin(); it != e[i].end(); ++it) {
      int u = it->first, v = it->second;
      dp[v] = std::max(dp[v], tmp[v]);
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) ans = std::max(ans, dp[i]);
  printf("%d\n", ans);
  return 0;
}