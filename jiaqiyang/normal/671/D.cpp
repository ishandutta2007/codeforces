#include <cctype>
#include <cstdio>
#include <vector>
#include <numeric>
#include <iostream>

const int N = 300000 + 10;

typedef long long i64;

const i64 INF = 1LL << 60;

inline int nextInt() {
  char ch;
  while (!isdigit(ch = getchar())) {}
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return res;
}

int n, m;
std::vector<int> adj[N], link[N];

int u[N], v[N], c[N];

int dep[N];

i64 f[N];
int root[N];

namespace Seg {

const int S = 30 * N;

int lch[S], rch[S], tot;
i64 min[S], tag[S];

inline void apply(int id, i64 v) {
  min[id] += v;
  tag[id] += v;
}

inline void release(int id) {
  if (tag[id]) {
    if (lch[id]) apply(lch[id], tag[id]);
    if (rch[id]) apply(rch[id], tag[id]);
    tag[id] = 0;
  }
}

int merge(int lt, int rt, int l, int r) {
  if (!lt) return rt;
  if (!rt) return lt;
  int res = ++tot;
  min[res] = std::min(min[lt], min[rt]);
  if (l == r) return res;
  release(lt);
  release(rt);
  int mid = (l + r) / 2;
  lch[res] = merge(lch[lt], lch[rt], l, mid);
  rch[res] = merge(rch[lt], rch[rt], mid + 1, r);
  return res;
}

i64 query(int id, int l, int r, int p, int q) {
  if (!id) return INF;
  if (p <= l && r <= q) return min[id];
  int mid = (l + r) / 2;
  i64 res = INF;
  release(id);
  if (p <= mid) res = std::min(res, query(lch[id], l, mid, p, q));
  if (q > mid) res = std::min(res, query(rch[id], mid + 1, r, p, q));
  return res;
}

void add(int id, int l, int r, int p, int q, i64 v) {
  if (!id) return;
  if (p <= l && r <= q) {
    apply(id, v);
    return;
  }
  int mid = (l + r) / 2;
  if (p <= mid) add(lch[id], l, mid, p, q, v);
  if (q > mid) add(rch[id], mid + 1, r, p, q, v);
}

void modify(int &id, int l, int r, int p, i64 v) {
  if (!id) min[id = ++tot] = v; else min[id] = std::min(min[id], v);
  if (l == r) return;
  release(id);
  int mid = (l + r) / 2;
  if (p <= mid) modify(lch[id], l, mid, p, v); else modify(rch[id], mid + 1, r, p, v);
}

}

void dfs(int a, int fa = -1) {
  i64 sum = 0;
  for (int i = 0; i < adj[a].size(); ++i) {
    int b = adj[a][i];
    if (b == fa) continue;
    dep[b] = dep[a] + 1;
    dfs(b, a);
    sum = std::min(sum + f[b], INF);
  }
  for (int i = 0; i < adj[a].size(); ++i) {
    int b = adj[a][i];
    if (b == fa) continue;
    Seg::add(root[b], 1, n, 1, n, sum - f[b]);
    root[a] = Seg::merge(root[a], root[b], 1, n);
  }
  for (int i = 0; i < link[a].size(); ++i) {
    int j = link[a][i];
    int p = dep[v[j]];
    i64 q = c[j] + sum;
    Seg::modify(root[a], 1, n, p, q);
  }
  if (a > 1) f[a] = std::min(Seg::query(root[a], 1, n, 1, std::max(dep[a] - 1, 1)), INF); else f[a] = sum;
}

int main() {
  n = nextInt();
  m = nextInt();
  for (int i = n - 1; i--;) {
    int x = nextInt(), y = nextInt();
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (int i = 1; i <= m; ++i) u[i] = nextInt(), v[i] = nextInt(), c[i] = nextInt();
  for (int i = 1; i <= m; ++i) link[u[i]].push_back(i);
  dep[1] = 1;
  dfs(1);
  std::cout << (f[1] <= std::accumulate(c + 1, c + m + 1, 0LL) ? f[1] : -1) << '\n';
  return 0;
}