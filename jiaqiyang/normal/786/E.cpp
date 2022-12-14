#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

const int N = 50000 + 10, E = 400 * N, INF = 0x3f3f3f3f;

int det;

class Flow {
  int adj[N], to[E], next[E], cap[E], cnt;
  int h[N], gap[N], s, t;
  int dfs(int a, int df) {
    if (a == t) return df;
    int res = 0;
    for (int i = adj[a]; i; i = next[i]) {
      int b = to[i];
      if (cap[i] && h[a] == h[b] + 1) {
        int f = dfs(b, std::min(df - res, cap[i]));
        cap[i] -= f;
        cap[i ^ 1] += f;
        res += f;
      }
      if (res == df) return res;
    }
    if (--gap[h[a]] == 0) h[s] = t + 1;
    ++gap[++h[a]];
    return res;
  }
 public:
  inline void clear(int _s, int _t) {
    cnt = 2, s = _s, t = _t;
    memset(adj, 0, sizeof adj);
  }
  int link(int a, int b, int c) {
    to[cnt] = b, next[cnt] = adj[a], cap[cnt] = c, adj[a] = cnt++;
    to[cnt] = a, next[cnt] = adj[b], cap[cnt] = 0, adj[b] = cnt++;
    return cnt - 2;
  }
  int flow() {
    memset(h, 0, sizeof h);
    memset(gap, 0, sizeof gap);
    int res = 0;
    while (h[s] < t + 1) res += dfs(s, INF);
    return res;
  }
  bool flag[E];
  void solve() {
    static bool mark[N];
    memset(mark, 0, sizeof mark);
    memset(flag, 0, sizeof flag);
    std::vector<int> q;
    q.push_back(s);
    mark[s] = true;
    for (int i = 0; i < q.size(); ++i) {
      int a = q[i];
      for (int j = adj[a]; j; j = next[j]) {
        int b = to[j];
        if (!mark[b] && cap[j]) mark[b] = true, q.push_back(b);
      }
    }
    for (auto a : q)
      for (int i = adj[a]; i; i = next[i])
        if (!(i & 1) && !mark[to[i]] && !cap[i])
          flag[i] = true;
  }
} g;

int s, t;

inline int pos(int l, int r) { return (l + r) | (l != r); }

void build(int l, int r) {
  if (l == r) return;
  int id = pos(l, r), mid = (l + r) >> 1;
  int lch = pos(l, mid), rch = pos(mid + 1, r);
  g.link(id, lch, INF);
  g.link(id, rch, INF);
  build(l, mid);
  build(mid + 1, r);
}

void modify(int l, int r, int p, int q, int v) {
  if (p <= l && r <= q) {
    g.link(v, pos(l, r), INF);
    return;
  }
  int mid = (l + r) >> 1;
  if (p <= mid) modify(l, mid, p, q, v);
  if (q > mid) modify(mid + 1, r, p, q, v);
}

int n, m, tag[N];
std::vector<std::pair<int, int>> adj[N];

int fa[N], dep[N], size[N], son[N], top[N], map[N], tot;

void dfs(int a) {
  size[a] = 1;
  for (auto it : adj[a]) {
    int b = it.first;
    if (b == fa[a]) continue;
    fa[b] = a;
    dep[b] = dep[a] + 1;
    tag[it.second] = b;
    dfs(b);
    size[a] += size[b];
    if (size[b] > size[son[a]]) son[a] = b;
  }
}

void split(int a, int t) {
  map[a] = ++tot;
  top[a] = t;
  if (son[a]) split(son[a], t);
  for (auto it : adj[a]) {
    int b = it.first;
    if (b != fa[a] && b != son[a]) split(b, b);
  }
}

void query(int x, int y, int z) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
    modify(1, n, map[top[x]], map[x], z);
    x = fa[top[x]];
  }
  if (dep[x] > dep[y]) std::swap(x, y);
  if (x != y) modify(1, n, map[x] + 1, map[y], z);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].emplace_back(b, i);
    adj[b].emplace_back(a, i);
  }
  dep[1] = 1;
  dfs(1);
  split(1, 1);
  det = 2 * n + 2;
  int s = det + m + 1, t = s + 1;
  g.clear(s, t);
  build(1, n);
  static int x[N], y[N];
  for (int i = 1; i <= m; ++i) {
    x[i] = g.link(s, det + i, 1);
    int u, v;
    scanf("%d%d", &u, &v);
    query(u, v, det + i);
  }
  for (int i = 2; i <= n; ++i) y[i] = g.link(pos(map[i], map[i]), t, 1);
  g.flow();
  g.solve();
  std::vector<int> a, b;
  for (int i = 1; i <= m; ++i) if (g.flag[x[i]]) a.push_back(i);
  for (int i = 1; i < n; ++i) if (g.flag[y[tag[i]]]) b.push_back(i);
  printf("%d\n%d", a.size() + b.size(), a.size());
  for (auto i : a) printf(" %d", i);
  printf("\n%d", b.size());
  for (auto i : b) printf(" %d", i);
  putchar('\n');
  return 0;
}