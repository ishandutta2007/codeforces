#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>

typedef long long i64;

const int N = 100000 + 10, M = 3 * N;

int n, m, k, u[M], v[M], x[M], s[N], y[N];

i64 dist[N];

std::vector< std::pair<int, int> > adj[N];

void dijkstra() {
  static std::pair<i64, int> heap[50 * M];
  int top = 0;
  memset(dist, 0x3f, sizeof dist);
  for (heap[top = 1] = std::make_pair(dist[1] = 0, 1); top;) {
    std::pop_heap(heap + 1, heap + top + 1);
    std::pair<i64, int> cur = heap[top--];
    int a = cur.second;
    if (-cur.first > dist[a]) continue;
    for (int i = 0; i < adj[a].size(); ++i) {
      int b = adj[a][i].first, c = adj[a][i].second;
      if (dist[a] + c < dist[b]) {
        heap[++top] = std::make_pair(-(dist[b] = dist[a] + c), b);
        std::push_heap(heap + 1, heap + top + 1);
      }
    }
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; ++i) scanf("%d%d%d", &u[i], &v[i], &x[i]);
  for (int i = 1; i <= m; ++i) adj[u[i]].push_back(std::make_pair(v[i], x[i]));
  for (int i = 1; i <= m; ++i) adj[v[i]].push_back(std::make_pair(u[i], x[i]));
  std::set< std::pair<int, int> > pool;
  for (int i = 1; i <= k; ++i) scanf("%d%d", &s[i], &y[i]), pool.insert(std::make_pair(s[i], y[i]));
  for (int i = 1; i <= k; ++i) adj[1].push_back(std::make_pair(s[i], y[i]));
  dijkstra();
  int ans = k - pool.size();
  for (std::set< std::pair<int, int> >::iterator it = pool.begin(); it != pool.end(); ++it) {
    int a = it->first, t = it->second;
    if (dist[a] < t) {
      ++ans;
    } else if (dist[a] == t) {
      for (int j = 0; j < adj[a].size(); ++j) {
        int b = adj[a][j].first, c = adj[a][j].second;
        if (dist[b] + c == dist[a]) {
          ++ans;
          break;
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}