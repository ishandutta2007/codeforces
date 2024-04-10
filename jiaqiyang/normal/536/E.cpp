#include <cstdio>
#include <vector>
#include <algorithm>

const int N = 100000 + 10;

int n, m, a[N];

struct Edge {
  int x, y, z, id;
  inline bool operator< (const Edge &rhs) const {
    return z < rhs.z;
  }
} edge[N], que[N];

std::vector<int> adj[N];

int fa[N], dep[N], size[N], son[N], top[N], map[N];

void bfs() {
  static int q[N];
  q[1] = dep[1] = 1;
  for (int i = 1, r = 1; i <= r; ++i) {
    int a = q[i];
    for (int j = 0; j < adj[a].size(); ++j) {
      int b = adj[a][j];
      if (b != fa[a]) fa[q[++r] = b] = a, dep[b] = dep[a] + 1;
    }
  }
  for (int i = 1; i <= n; ++i) size[i] = 1;
  for (int i = n; i > 1; --i) size[fa[q[i]]] += size[q[i]];
  for (int i = 2; i <= n; ++i) if (size[son[fa[i]]] < size[i]) son[fa[i]] = i;
  for (int i = 1, tot = 0; i <= n; ++i) {
    int a = q[i];
    if (map[a]) continue;
    for (int b = a; b; b = son[b]) top[b] = a, map[b] = ++tot;
  }
}

inline int pos(int l, int r) { return (l + r) | (l != r); }

struct Info {
  int ls, rs, size, sum;
  Info() { ls = rs = size = sum = 0; }
  explicit Info(int x) {
    ls = rs = x;
    size = 1;
    sum = 0;
  }
} info[2 * N];

inline Info operator+ (const Info &lhs, const Info &rhs) {
  Info res;
  res.size = lhs.size + rhs.size;
  res.sum = lhs.sum + rhs.sum;
  if (lhs.rs != lhs.size && rhs.ls != rhs.size) res.sum += a[lhs.rs + rhs.ls];
  res.ls = (lhs.ls == lhs.size ? (lhs.size + rhs.ls) : lhs.ls);
  res.rs = (rhs.rs == rhs.size ? (rhs.size + lhs.rs) : rhs.rs);
  return res;
}

void build(int l, int r) {
  int id = pos(l, r);
  if (l == r) {
    info[id] = Info(0);
    return;
  }
  int mid = (l + r) / 2, lch = pos(l, mid), rch = pos(mid + 1, r);
  build(l, mid);
  build(mid + 1, r);
  info[id] = info[lch] + info[rch];
}

void modify(int l, int r, int p) {
  int id = pos(l, r);
  if (l == r) {
    info[id] = Info(1);
    return;
  }
  int mid = (l + r) / 2, lch = pos(l, mid), rch = pos(mid + 1, r);
  if (p <= mid) modify(l, mid, p); else modify(mid + 1, r, p);
  info[id] = info[lch] + info[rch];
}

Info res;

void query(int l, int r, int p, int q) {
  if (p <= l && r <= q) {
    res = res + info[pos(l, r)];
    return;
  }
  int mid = (l + r) / 2;
  if (p <= mid) query(l, mid, p, q);
  if (q > mid) query(mid + 1, r, p, q);
}

int lca(int x, int y) {
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
    x = fa[top[x]];
  }
  return dep[x] < dep[y] ? x : y;
}

int query(int x, int y) {
  int z = lca(x, y);
  Info left(0), right(0);
  for (; top[x] != top[z]; x = fa[top[x]]) {
    res = Info();
    query(1, n, map[top[x]], map[x]);
    std::swap(res.ls, res.rs);
    left = left + res;
  }
  if (x != z) {
    res = Info();
    query(1, n, map[z] + 1, map[x]);
    std::swap(res.ls, res.rs);
    left = left + res;
  }
  for (; top[y] != top[z]; y = fa[top[y]]) {
    res = Info();
    query(1, n, map[top[y]], map[y]);
    right = res + right;
  }
  if (y != z) {
    res = Info();
    query(1, n, map[z] + 1, map[y]);
    right = res + right;
  }
  left = left + right;
  int cur = left.sum;
  cur += a[left.ls];
  if (left.rs != left.size) cur += a[left.rs];
  return cur;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i < n; ++i) {
    scanf("%d%d%d", &edge[i].x, &edge[i].y, &edge[i].z);
    adj[edge[i].x].push_back(edge[i].y);
    adj[edge[i].y].push_back(edge[i].x);
  }
  for (int i = 1; i <= m; ++i) scanf("%d%d%d", &que[i].x, &que[i].y, &que[i].z), que[i].id = i;
  bfs();
  build(1, n);
  std::sort(edge + 1, edge + n);
  for (int i = 1; i < n; ++i) if (fa[edge[i].x] == edge[i].y) std::swap(edge[i].x, edge[i].y);
  std::sort(que + 1, que + m + 1);
  static int ans[N];
  for (int i = m, j = n - 1; i > 0; --i) {
    for (; j && edge[j].z >= que[i].z; --j) modify(1, n, map[edge[j].y]);
    ans[que[i].id] = query(que[i].x, que[i].y);
  }
  for (int i = 1; i <= m; ++i) printf("%d\n", ans[i]);
  return 0;
}