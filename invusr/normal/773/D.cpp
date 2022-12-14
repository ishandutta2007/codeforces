#include <bits/stdc++.h>
using namespace std;

using s64 = long long;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> edge(n, vector<int>(n));
  int min_edge = numeric_limits<int>::max();
  for (int u = 0; u < n; ++u) {
    for (int v = u + 1; v < n; ++v) {
      scanf("%d", &edge[u][v]);
      edge[v][u] = edge[u][v];
      min_edge = min(min_edge, edge[u][v]);
    }
  }

  vector<s64> dis(n);
  vector<bool> vis(n);
  for (int u = 0; u < n; ++u) {
    dis[u] = numeric_limits<s64>::max();
    vis[u] = false;
    for (int v = 0; v < n; ++v) {
      if (v != u) {
        edge[u][v] -= min_edge;
        dis[u] = min(dis[u], 2ll * edge[u][v]);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    int u = -1;
    for (int v = 0; v < n; ++v) {
      if (!vis[v] && (!~u || dis[v] < dis[u])) {
        u = v;
      }
    }
    vis[u] = true;
    for (int v = 0; v < n; ++v) {
      dis[v] = min(dis[v], dis[u] + edge[u][v]);
    }
  }

  for (int u = 0; u < n; ++u) {
    printf("%lld\n", dis[u] + (s64)min_edge * (n - 1));
  }

  return 0;
}