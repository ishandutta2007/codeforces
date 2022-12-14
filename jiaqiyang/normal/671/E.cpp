#include <cstdio>
#include <vector>
#include <algorithm>

typedef long long i64;

const int N = 100000 + 10;
const i64 INF = 1LL << 50;

int n, k, ans;

int w[N], g[N];

int succ[N];
i64 val[N];

std::vector<int> adj[N];

i64 suf[N];

void init() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n; ++i) scanf("%d", &w[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &g[i]);
  static i64 sum[N];
  for (int i = 1; i < n; ++i) sum[i + 1] = sum[i] + g[i] - w[i];
  static int stk[N];
  std::fill(succ + 1, succ + n + 1, n);
  for (int i = 1, top = 0; i <= n; ++i) {
    for (; top && sum[stk[top]] > sum[i]; --top) succ[stk[top]] = i;
    stk[++top] = i;
  }
  for (int i = 1; i <= n; ++i) val[i] = std::max(0LL, sum[i] - sum[succ[i]]);
  for (int i = 1; i < n; ++i) adj[succ[i]].push_back(i);
  for (int i = n; i > 1; --i) suf[i - 1] = suf[i] + g[i] - w[i - 1];
}

inline int pos(int l, int r) { return (l + r) | (l != r); }

struct Tag {
  i64 x, y;
  explicit Tag(i64 _x = 0, i64 _y = 0): x(_x), y(_y) {}
  inline bool any() const { return x || y; }
  inline Tag& operator+= (const Tag &rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }
} tag[2 * N];

struct Info {
  i64 x, y, z;
  // z = x + y
  inline Info& operator+= (const Tag &rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.x + rhs.y;
    return *this;
  }
} info[2 * N];

i64 mem[2 * N];

void apply(int l, int r, const Tag &t) {
  int id = pos(l, r);
  info[id] += t;
  tag[id] += t;
  mem[id] += t.x;
}

void release(int l, int r) {
  int id = pos(l, r);
  if (tag[id].any()) {
    int mid = (l + r) >> 1;
    apply(l, mid, tag[id]);
    apply(mid + 1, r, tag[id]);
    tag[id] = Tag();
  }
}

i64 query(int l, int r, i64 y) {
  int id = pos(l, r);
  if (info[id].y >= y || l == r) return info[id].z - y;
  release(l, r);
  int mid = (l + r) >> 1, lch = pos(l, mid);
  i64 res = query(l, mid, y);
  res = std::min(res, info[lch].y <= y ? mem[id] : query(mid + 1, r, y));
  return res;
}

void update(int l, int r) {
  int id = pos(l, r), mid = (l + r) >> 1, lch = pos(l, mid), rch = pos(mid + 1, r);
  info[id].x = std::max(info[lch].x, info[rch].x);
  info[id].y = std::min(info[lch].y, info[rch].y);
  info[id].z = std::min(info[lch].z, info[rch].z);
  mem[id] = query(mid + 1, r, info[lch].y);
}

void build(int l, int r) {
  if (l == r) {
    int id = pos(l, r);
    info[id].y = info[id].z = suf[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid);
  build(mid + 1, r);
  update(l, r);
}

void add(int l, int r, int p, int q, const Tag &t) {
  if (p <= l && r <= q) {
    apply(l, r, t);
    return;
  }
  release(l, r);
  int mid = (l + r) >> 1;
  if (p <= mid) add(l, mid, p, q, t);
  if (q > mid) add(mid + 1, r, p, q, t);
  update(l, r);
}

int queryX(int l, int r) {
  if (l == r) return l;
  release(l, r);
  int mid = (l + r) >> 1, lch = pos(l, mid);
  return info[lch].x <= k ? queryX(mid + 1, r) : queryX(l, mid);
}

i64 cur;

int query(int l, int r, int p, int q) {
  int id = pos(l, r);
  if (l == r) {
    int res = info[id].z - cur <= k ? l : 0;
    cur = std::min(cur, info[id].y);
    return res;
  }
  release(l, r);
  int mid = (l + r) >> 1;
  if (p <= l && r <= q) {
    i64 temp = std::min(cur, info[pos(l, mid)].y);
    int res = 0;
    if (query(mid + 1, r, temp) <= k) {
      cur = temp;
      res = query(mid + 1, r, p, q);
    } else {
      res = query(l, mid, p, q);
    }
    cur = std::min(cur, info[id].y);
    return res;
  }
  int res = 0;
  if (p <= mid) res = query(l, mid, p, q);
  if (q > mid) res = std::max(res, query(mid + 1, r, p, q));
  return res;
}

void dfs(int a) {
  if (succ[a] >= 3) add(1, n, 1, succ[a] - 2, Tag(0, val[a]));
  add(1, n, succ[a] - 1, n, Tag(val[a], 0));
  cur = INF;
  ans = std::max(ans, std::min(queryX(1, n), query(1, n, a, n)) - a + 1);
  for (auto b : adj[a]) dfs(b);
  if (succ[a] >= 3) add(1, n, 1, succ[a] - 2, Tag(0, -val[a]));
  add(1, n, succ[a] - 1, n, Tag(-val[a], 0));
}

int main() {
  init();
  build(1, n);
  dfs(n);
  printf("%d\n", ans);
  return 0;
}