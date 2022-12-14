#include <cstdio>
#include <cstring>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>

const int N = 500000 + 10, INF = 0x3f3f3f3f;

int n, m;

std::vector<std::tuple<int, int, int>> edge;
std::vector<int> adj[N][2];

void link(int a, int b, int l, int r, int c) {
  if ((l & 1) != c) ++l;
  --r;
  if ((r & 1) != c) --r;
  if (l > r) return;
  adj[a][c].push_back(edge.size());
  edge.emplace_back(b, l, r);
}

int dist[4 * N];

void init() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b, l, r;
    scanf("%d%d%d%d", &a, &b, &l, &r);
    int x = l, y = l + 1;
    if (x & 1) std::swap(x, y);
    link(a, b, l, r, 0);
    link(a, b, l, r, 1);
    link(b, a, l, r, 0);
    link(b, a, l, r, 1);
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < 2; ++j)
      std::sort(adj[i][j].begin(), adj[i][j].end(), [&] (int lhs, int rhs) { return std::get<1>(edge[lhs]) > std::get<1>(edge[rhs]); });
}

int main() {
  init();
  if (n == 1) return puts("0"), 0;
  memset(dist, 0x3f, sizeof dist);
  std::priority_queue<std::pair<int, int>> heap;
  for (auto i : adj[1][0]) if (!std::get<1>(edge[i])) heap.emplace(dist[i] = 0, i);
  while (!heap.empty()) {
    auto info = heap.top();
    heap.pop();
    int u = info.second;
    if (-info.first > dist[u]) continue;
    int a, b, c;
    std::tie(a, b, c) = edge[u];
    int w = dist[u] + 1;
    for (auto &cur = adj[a][w & 1]; !cur.empty(); cur.pop_back()) {
      int v = cur.back(), x, y, z;
      std::tie(x, y, z) = edge[v];
      if (z < w) continue;
      if (y > c + 1) break;
      int d = std::max(w, y);
      if (dist[v] > d) heap.emplace(-(dist[v] = d), v);
    }
  }
  int ans = INF;
  for (int i = 0; i < edge.size(); ++i) if (std::get<0>(edge[i]) == n) ans = std::min(ans, dist[i] + 1);
  printf("%d\n", ans == INF ? -1 : ans);
  return 0;
}