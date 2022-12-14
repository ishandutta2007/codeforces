#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long i64;

const int N = 1000 + 10, E = 40000 + 10, INF = 0x3f3f3f3f;

int n, m, len, s, t;

int adj[N], to[E], next[E], cost[E], cnt;

void link(int a, int b, int c) {
  to[cnt] = b, next[cnt] = adj[a], cost[cnt] = c, adj[a] = cnt++;
  to[cnt] = a, next[cnt] = adj[b], cost[cnt] = c, adj[b] = cnt++;
}

struct {
  int u, v, w;
} e[E];

i64 dist[N];

i64 dijkstra(int p, int v) {
  memset(adj, 0, n * sizeof(int));
  cnt = 2;
  for (int i = 0; i < p; ++i) link(e[i].u, e[i].v, e[i].w ? e[i].w : 1);
  link(e[p].u, e[p].v, e[p].w ? e[p].w : v);
  for (int i = p + 1; i < m; ++i) link(e[i].u, e[i].v, e[i].w ? e[i].w : INF);
  static std::pair<i64, int> heap[N * N];
  int top = 1;
  memset(dist, 0x3f, n * sizeof(i64));
  for (heap[0] = std::make_pair(dist[s] = 0, s); top;) {
    std::pop_heap(heap, heap + top);
    std::pair<i64, int> cur = heap[--top];
    int a = cur.second;
    if (-cur.first > dist[a]) continue;
    for (int i = adj[a]; i; i = next[i]) {
      int b = to[i], c = cost[i];
      if (dist[a] + c < dist[b]) {
        heap[top++] = std::make_pair(-(dist[b] = dist[a] + c), b);
        std::push_heap(heap, heap + top);
      }
    }
  }
  return dist[t];
}

int main() {
  scanf("%d%d%d%d%d", &n, &m, &len, &s, &t);
  for (int i = 0; i < m; ++i) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
  if (dijkstra(0, INF) < len || dijkstra(m - 1, 1) > len) return puts("NO"), 0;
  puts("YES");
  int l = 0, r = m - 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (dijkstra(mid, 1) <= len) r = mid; else l = mid + 1;
  }
  int p = l;
  l = 1, r = len;
  while (l < r) {
    int mid = (l + r + 1) >> 1;
    if (dijkstra(p, mid) <= len) l = mid; else r = mid - 1;
  }
  for (int i = 0; i < p; ++i) if (!e[i].w) e[i].w = 1;
  if (!e[p].w) e[p].w = l;
  for (int i = p + 1; i < m; ++i) if (!e[i].w) e[i].w = INF;
  for (int i = 0; i < m; ++i) printf("%d %d %d\n", e[i].u, e[i].v, e[i].w);
  return 0;
}