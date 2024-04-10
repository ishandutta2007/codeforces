#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long i64;

const int N = 100000 + 10;
const i64 INF = 0x3f3f3f3f3f3f3f3fLL;

int n, m, q;

std::vector<int> adj[N], pool[N];

int fa[N], dep[N], size[N], son[N], top[N], dfn[N], left[N], right[N];

void dfs(int a) {
  size[a] = 1;
  for (int i = 0; i < adj[a].size(); ++i) {
    int b = adj[a][i];
    if (b != fa[a]) {
      fa[b] = a;
      dep[b] = dep[a] + 1;
      dfs(b);
      size[a] += size[b];
      if (size[b] > size[son[a]]) son[a] = b;
    }
  }
}

void split(int a, int t) {
  static int tot = 0;
  dfn[left[a] = ++tot] = a;
  top[a] = t;
  if (son[a]) split(son[a], t);
  for (int i = 0; i < adj[a].size(); ++i) {
    int b = adj[a][i];
    if (b != fa[a] && b != son[a]) split(b, b);
  }
  right[a] = tot;
}

inline int pos(int l, int r) { return (l + r) | (l != r); }

struct Info {
  i64 x;
  int y, z;
  Info() {}
  Info(i64 _x, int _y, int _z): x(_x), y(_y), z(_z) {}
  inline bool operator< (const Info &rhs) const {
    return x < rhs.x || (x == rhs.x && y < rhs.y);
  }
} info[2 * N];

i64 tag[2 * N];

inline void apply(int id, i64 det) {
  tag[id] += det;
  info[id].x += det;
}

void release(int l, int r) {
  int id = pos(l, r), mid = (l + r) >> 1;
  if (tag[id]) {
    apply(pos(l, mid), tag[id]);
    apply(pos(mid + 1, r), tag[id]);
    tag[id] = 0;
  }
}

inline void update(int l, int r) {
  int mid = (l + r) >> 1;
  info[pos(l, r)] = std::min(info[pos(l, mid)], info[pos(mid + 1, r)]);
}

void build(int l, int r) {
  if (l == r) {
    int id = pos(l, r), t = dfn[l];
    if (!pool[t].empty()) info[id] = Info(pool[t].back() + tag[id], t, pool[t].back()); else info[id] = Info(INF, 0, 0);
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid);
  build(mid + 1, r);
  update(l, r);
}

void add(int l, int r, int p, int q, int v) {
  if (p <= l && r <= q) {
    apply(pos(l, r), v);
    return;
  }
  release(l, r);
  int mid = (l + r) >> 1;
  if (p <= mid) add(l, mid, p, q, v);
  if (q > mid) add(mid + 1, r, p, q, v);
  update(l, r);
}

Info query(int l, int r, int p, int q) {
  if (p <= l && r <= q) return info[pos(l, r)];
  release(l, r);
  int mid = (l + r) >> 1;
  Info res(INF, 0, 0);
  if (p <= mid) res = std::min(res, query(l, mid, p, q));
  if (q > mid) res = std::min(res, query(mid + 1, r, p, q));
  return res;
}

void pop(int l, int r, int p) {
  if (l == r) {
    int id = pos(l, r), t = dfn[l];
    pool[t].pop_back();
    if (!pool[t].empty()) info[id] = Info(pool[t].back() + tag[id], t, pool[t].back()); else info[id] = Info(INF, 0, 0);
    return;
  }
  release(l, r);
  int mid = (l + r) >> 1;
  if (p <= mid) pop(l, mid, p); else pop(mid + 1, r, p);
  update(l, r);
}

Info get(int x, int y) {
  Info res(INF, 0, 0);
  while (top[x] != top[y]) {
    if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
    res = std::min(res, query(1, n, left[top[x]], left[x]));
    x = fa[top[x]];
  }
  if (dep[x] > dep[y]) std::swap(x, y);
  res = std::min(res, query(1, n, left[x], left[y]));
  return res;
}

void query(int x, int y, int z) {
  std::vector<int> ans;
  while (z--) {
    Info cur = get(x, y);
    if (!cur.z) break;
    ans.push_back(cur.z);
    pop(1, n, left[cur.y]);
  }
  printf("%d", ans.size());
  for (int i = 0; i < ans.size(); ++i) printf(" %d", ans[i]);
  putchar('\n');
}

int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = n - 1; i--;) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= m; ++i) {
    int c;
    scanf("%d", &c);
    pool[c].push_back(i);
  }
  for (int i = 1; i <= n; ++i) std::reverse(pool[i].begin(), pool[i].end());
  dep[1] = 1;
  dfs(1);
  split(1, 1);
  build(1, n);
  while (q--) {
    int op, x, y;
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1) {
      int z;
      scanf("%d", &z);
      query(x, y, z);
    } else {
      add(1, n, left[x], right[x], y);
    }
  }
  return 0;
}