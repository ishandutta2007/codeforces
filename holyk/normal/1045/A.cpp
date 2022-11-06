#include <bits/stdc++.h>
#define perr(a...) fprintf(stderr, a)
#define dbg(a...) perr("\033[32;1m"), perr(a), perr("\033[0m")
template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
} 
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}

using LL = long long;
using PII = std::pair<int, int>;

template<class F = int>
class Graph {
public:
  struct Edge {
    int v;
    F w;
  };
  Graph(int n) : e(), g(n) {}
  std::vector<Edge> e;
  std::vector<std::vector<int>> g;
  void AddEdge(int x, int y, F z) {
    g[x].push_back(e.size()), e.push_back({y, z});
    g[y].push_back(e.size()), e.push_back({x, 0});
  }
  F MaxFlow(int s_, int t_) {
    d.resize(g.size());
    cur.resize(g.size());
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
  int ls, rs, leaf;
} t[666666];
int n, m, cnt, id[5005];
void build(int &o, int l, int r) {
  g->g.emplace_back();
  t[o = ++cnt] = {0, 0, 0};
  // dbg("%d %d : %d\n", l, r, o);
  if (l == r) {
    id[l] = o;
    t[o].leaf = l;
    return;
  }
  int m = l + r >> 1;
  build(t[o].ls, l, m);
  build(t[o].rs, m + 1, r);
  g->AddEdge(o, t[o].ls, INT_MAX);
  g->AddEdge(o, t[o].rs, INT_MAX);
}
void link(int o, int l, int r, int x, int y, int s) {
  if (x <= l && r <= y) {
    g->AddEdge(s, o, INT_MAX);
    return;
  }
  int m = l + r >> 1;
  if (x <= m) link(t[o].ls, l, m, x, y, s);
  if (y > m) link(t[o].rs, m + 1, r, x, y, s);
}
int tp[5005], a[5005][3], bel[5005];
int f[5005];
void dfs(int x, int p) {
  if (!f[p]) return;
  // dbg("%d : %d\n", p, x);
  if (x <= cnt && t[x].leaf) {
    bel[t[x].leaf] = p;
    f[p]--;
    return;
  }
  for (int i : g->g[x]) {
    int y = g->e[i].v;
    if (!y || y > cnt || !g->e[i ^ 1].w) continue;
    g->e[i].w++;
    g->e[i ^ 1].w--;
    // dbg("w = %d, y = %d\n", g->e[i ^ 1].w, y);
    dfs(y, p);
    if (!f[p]) return;
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> m;
  g = new Graph<int>(1);
  int root;
  build(root, 1, m);
  g->g.resize(cnt + n + 2);
  int s = 0, t = cnt + n + 1;
  for (int i = 1; i <= m; i++) g->AddEdge(id[i], t, 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> tp[i];
    switch (tp[i]) {
    case 0:
      g->AddEdge(s, i + cnt, 1);
      int k, x;
      std::cin >> k;
      while (k--) {
        std::cin >> x;
        g->AddEdge(i + cnt, id[x], 1);
      }
      break;
    case 1:
      g->AddEdge(s, i + cnt, 1);
      int l, r;
      std::cin >> l >> r;
      link(root, 1, m, l, r, i + cnt);
      break;
    case 2:
      g->AddEdge(s, i + cnt, 2);
      std::cin >> a[i][0] >> a[i][1] >> a[i][2];
      for (int j = 0; j < 3; j++) g->AddEdge(i + cnt, id[a[i][j]], 1);
      break;
    }
  }
  int ans = g->MaxFlow(s, t);
  std::cout << ans << "\n";
  for (int i = 1; i <= n; i++) {
    int j = g->g[i + cnt][0];
    assert(g->e[j].v == s);
    if (!g->e[j].w) continue;
    f[i] = g->e[j].w;
    dfs(i + cnt, i);
    // assert(!f[i]);
  }
  for (int i = 1; i <= n; i++) {
    int j = g->g[i + cnt][0];
    if (tp[i] == 2 && g->e[j].w == 1) {
      bel[a[i][bel[a[i][0]] == i]] = i;
    }
  }
  
  for (int i = 1; i <= m; i++) {
    if (bel[i]) std::cout << bel[i] << " " << i << "\n";
  }
  return 0;
}