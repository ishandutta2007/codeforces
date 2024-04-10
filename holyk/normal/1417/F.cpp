#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>

namespace FastIn {

template <class T>
inline void readInt(T &w) {
  char c, p = 0;
  while (!isdigit(c = getchar())) p = c == '-';
  for (w = c & 15; isdigit(c = getchar()); w = w * 10 + (c & 15));
  if (p) w = -w;
}
template <class T, class... Args>
inline void readInt(T &w, Args &... args) { readInt(w), readInt(args...); }
}  // namespace FastIn
using namespace FastIn;
template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}

constexpr int N(2e5 + 5), M(5e5 + 5);
int n, m, q, a[N];
std::pair<int, int> e[M], qry[M];

namespace UFS {
int fa[N];
inline int find(int x) {
  return fa[x] ? fa[x] = find(fa[x]) : x;
}
} // namespace UFS

bool deleted[M];

int in[N], out[N];
namespace NRTreap {
struct Node {
  int ls, rs, fa, r, w, m;
} t[N];
inline void pushup(int o) {
  t[o].m = o;
  if (t[t[t[o].ls].m].w > t[o].w) t[o].m = t[t[o].ls].m;
  if (t[t[t[o].rs].m].w > t[t[o].m].w) t[o].m = t[t[o].rs].m;
  t[t[o].ls].fa = t[t[o].rs].fa = o;
}
void split(int o, int k, int &x, int &y) {
  if (!o) {
    x = y = 0;
    return;
  }
  if (k < o) {
    split(t[o].ls, k, x, t[o].ls);
    y = o;
  } else {
    split(t[o].rs, k, t[o].rs, y);
    x = o;
  }
  t[x].fa = t[y].fa = 0;
  pushup(o);
}
int merge(int x, int y) {
  if (!x || !y) return x | y;
  return t[x].r < t[y].r ? (t[x].rs = merge(t[x].rs, y), pushup(x), x)
                         : (t[y].ls = merge(x, t[y].ls), pushup(y), y);
}

// void dfs(int x) {
//   if (!x) return;
//   dfs(t[x].ls);
//   printf("%d ", x);
//   dfs(t[x].rs);
// }
void solve() {
  for (int i = 1; i <= q; i++) {
    auto [z, x] = qry[i];
    if (z == 1) {
      x = in[x];
      while (t[x].fa) x = t[x].fa;
      x = t[x].m;
      printf("%d\n", t[x].w);
      t[x].w = 0;
      while (x) pushup(x), x = t[x].fa;
    } else {
      if (deleted[x]) continue;
      auto [u, v] = e[x];
      int l = in[u], r = out[u];
      u = l;
      while (t[u].fa) u = t[u].fa;
      int a, b, c;
      split(u, l - 1, a, b);
      split(b, r, b, c);
      merge(a, c);
    }
  }
}
} // namespace NRTreap

namespace Tree {
std::vector<int> g[N];
inline void addEdge(int x, int y) {
  g[x].push_back(y), g[y].push_back(x);
}
int idx, fa[N], rt;
void dfs(int x) {
  in[x] = ++idx;
  // printf("%d: %d\n", idx, x);
  NRTreap::t[idx] = { 0, 0, 0, rand(), a[x], idx };
  rt = NRTreap::merge(rt, idx);
  for (int y : g[x])
    if (!in[y])
      fa[y] = x, dfs(y);
  out[x] = idx;
}
void init() {
  for (int i = 1; i <= n; i++)
    if (!in[i]) rt = 0, dfs(i);
  for (int i = 1; i <= m; i++) {
    if (deleted[i]) continue;
    auto &[x, y] = e[i];
    if (fa[x] != y) std::swap(x, y);
  }
}
} // namespace Tree

int main() {
  readInt(n, m, q);
  for (int i = 1; i <= n; i++)
    readInt(a[i]);
  for (int i = 1; i <= m; i++)
    readInt(e[i].first, e[i].second);
  for (int i = 1; i <= q; i++) {
    readInt(qry[i].first, qry[i].second);
    if (qry[i].first == 2)
      deleted[qry[i].second] = 1;
  }
  using namespace UFS;
  for (int i = 1; i <= m; i++) {
    if (deleted[i]) continue;
    int x = find(e[i].first), y = find(e[i].second);
    if (x != y) {
      fa[x] = y;
      Tree::addEdge(e[i].first, e[i].second);
    }
  }
  for (int i = q; i; i--) {
    if (qry[i].first == 1) continue;
    auto &u = e[qry[i].second];
    int x = find(u.first), y = find(u.second);
    if (x != y) {
      deleted[qry[i].second] = 0;
      fa[x] = y;
      Tree::addEdge(u.first, u.second);
    }
  }
  Tree::init();
  NRTreap::solve();
  return 0;
}