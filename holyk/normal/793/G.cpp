#include <bits/stdc++.h>

using PII = std::pair<int, int>;

template<class F = int>
class Graph {
public:
  struct Edge {
    int v;
    F w;
  };
  Graph(int n) : e(), g(n), d(n), cur(n) {}
  std::vector<Edge> e;
  std::vector<std::vector<int>> g;
  void AddEdge(int x, int y, F z) {
    g[x].push_back(e.size()), e.push_back({y, z});
    g[y].push_back(e.size()), e.push_back({x, 0});
  }
  F MaxFlow(int s_, int t_) {
    s = s_, t = t_;
    F f = 0;
    while (bfs()) {
      std::fill(cur.begin(), cur.end(), 0);
      f += dfs(s, std::numeric_limits<F>().max());
    }
    return f;
  }

private:
  std::vector<int> d, cur;
  int s, t;
  int bfs() {
    static int q[1000005], l, r;
    std::fill(d.begin(), d.end(), -1);
    q[l = r = 1] = s, d[s] = 0;
    while (l <= r) {
      int x = q[l++];
      for (int i : g[x]) {
        if (e[i].w && !~d[e[i].v]) {
          d[q[++r] = e[i].v] = d[x] + 1;
        }
      }
    }
    return ~d[t];
  }
  F dfs(int x, F flow) {
    if (x == t || !flow) return flow;
    F used = 0;
    for (; cur[x] < g[x].size(); cur[x]++) {
      int i = g[x][cur[x]], y = e[i].v;
      if (!e[i].w || d[y] != d[x] + 1) continue;
      F f = dfs(y, std::min(flow - used, e[i].w));
      e[i].w -= f, e[i ^ 1].w += f, used += f;
      if (flow == used) return used;
    }
    if (!used) d[x] = -1;
    return used;
  }
};
Graph<int> *g;
struct Node {
  int ls, rs;
} t[666666];
int cnt;

std::map<PII, int> id;
void build(int &o, int l, int r) {
  id[PII(l, r)] = o = ++cnt;
  t[o].ls = t[o].rs = 0;
  if (l == r) return;
  int m = l + r >> 1;
  build(t[o].ls, l, m), build(t[o].rs, m + 1, r);
}
bool vis[666666];
void link(int o) {
  if (vis[o]) return;
  vis[o] = true;
  if (t[o].ls) {
    g->AddEdge(o, t[o].ls, INT_MAX);
    link(t[o].ls);
  }
  if (t[o].rs) {
    g->AddEdge(o, t[o].rs, INT_MAX);
    link(t[o].rs);
  }
}
void update(int &o, int l, int r, int x, int y, int z) {
  if (x <= l && r <= y) {
    if (z) {
      o = 0;
    } else {
      assert(!o);
      o = id[PII(l, r)];
    }
    return;
  }
  t[++cnt] = t[o], o = cnt;
  int m = l + r >> 1;
  if (x <= m) update(t[o].ls, l, m, x, y, z);
  if (y > m) update(t[o].rs, m + 1, r, x, y, z);
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<PII>> add(n + 1), del(n + 1);
  while (m--) {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    x1--;
    add[x1].emplace_back(y1, y2);
    del[x2].emplace_back(y1, y2);
  }
  std::vector<PII> root(1);
  build(root[0].first, 1, n);
  for (int i = 0; i < n; i++) {
    if (add[i].empty() && del[i].empty()) {
      root.back().second++;
      continue;
    }
    root.emplace_back(root.back().first, 1);
    for (auto [l, r] : del[i]) {
      update(root.back().first, 1, n, l, r, 0);
    }
    for (auto [l, r] : add[i]) {
      update(root.back().first, 1, n, l, r, 1);
    }
    
  }
  int s = 0, t = cnt + 1;
  g = new Graph<int>(cnt + 2);
  for (auto [r, x] : root) {
    g->AddEdge(s, r, x);
    link(r);
  }
  for (int i = 1; i <= n; i++) g->AddEdge(id[PII(i, i)], t, 1);
  std::cout << g->MaxFlow(s, t) << "\n";
  return 0;
}