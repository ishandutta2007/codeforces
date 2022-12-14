#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

typedef long long i64;

const int N = 200000 + 10;
const i64 INF = 0x3f3f3f3f3f3f3f3fLL;

int n, s;

i64 dist[2 * N];
std::vector<std::pair<int, int>> adj[2 * N];

inline int pos(int l, int r) { return (l + r) | (l != r); }

void build(int l, int r) {
  int id = pos(l, r);
  if (l == r) {
    adj[id].emplace_back(id + N, 0);
    adj[id + N].emplace_back(id, 0);
    return;
  }
  int mid = (l + r) >> 1, lch = pos(l, mid), rch = pos(mid + 1, r);
  adj[id].emplace_back(lch, 0);
  adj[id].emplace_back(rch, 0);
  adj[lch + N].emplace_back(id + N, 0);
  adj[rch + N].emplace_back(id + N, 0);
  build(l, mid);
  build(mid + 1, r);
}

void modify(int l, int r, int p, int q, int x, int y, int z) {
  if (p <= l && r <= q) {
    int id = pos(l, r);
    if (z == 2) adj[x].emplace_back(id, y); else adj[id + N].emplace_back(x, y);
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid) modify(l, mid, p, q, x, y, z);
  if (q > mid) modify(mid + 1, r, p, q, x, y, z);
}

void init() {
  int q;
  scanf("%d%d%d", &n, &q, &s);
  build(1, n);
  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int v, u, w;
      scanf("%d%d%d", &v, &u, &w);
      adj[pos(v, v)].emplace_back(pos(u, u), w);
    } else {
      int v, l, r, w;
      scanf("%d%d%d%d", &v, &l, &r, &w);
      modify(1, n, l, r, pos(v, v), w, t);
    }
  }
}

int main() {
  init();
  std::priority_queue<std::pair<i64, int>> heap;
  memset(dist, 0x3f, sizeof dist);
  int t = pos(s, s);
  for (heap.emplace(dist[t] = 0, t); !heap.empty();) {
    auto info = heap.top();
    heap.pop();
    int a = info.second;
    if (-info.first > dist[a]) continue;
    for (auto it : adj[a]) {
      int b = it.first;
      i64 c = dist[a] + it.second;
      if (c < dist[b]) heap.emplace(-(dist[b] = c), b);
    }
  }
  for (int i = 1; i <= n; ++i) printf("%lld ", dist[pos(i, i)] == INF ? -1 : dist[pos(i, i)]);
  return 0;
}