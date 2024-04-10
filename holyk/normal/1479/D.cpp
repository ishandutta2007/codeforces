// Author:  HolyK
// Created: Tue Jul 13 10:51:13 2021
#include <bits/stdc++.h>
#define dbg(a...) fprintf(stderr, a)
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

constexpr int N(3e5 + 5);
int n, m, a[N];
std::vector<int> g[N];
struct Node {
  Node *ls, *rs;
  uint64_t w;
} *null;
uint64_t pw[N];
void ins(Node *&o, int l, int r, int x) {
  o = new Node(*o);
  if (l == r) {
    o->w ^= pw[x];
    return;
  }
  int m = l + r >> 1;
  x <= m ? ins(o->ls, l, m, x) : ins(o->rs, m + 1, r, x);
  o->w = o->ls->w + o->rs->w;
}
Node *root[N];
int f[20][N], dep[N];
void dfs(int x) {
  ins(root[x] = root[f[0][x]], 1, n, a[x]);
  for (int y : g[x]) {
    if (y == f[0][x]) continue;
    f[0][y] = x;
    dep[y] = dep[x] + 1;
    dfs(y);
  }
}
int lca(int x, int y) {
  if (dep[x] < dep[y]) std::swap(x, y);
  for (int i = 0; dep[x] - dep[y]; i++) if (dep[x] - dep[y] >> i & 1) x = f[i][x];
  if (x == y) return x;
  for (int i = 19; i >= 0; i--) if (f[i][x] != f[i][y]) x = f[i][x], y = f[i][y];
  return f[0][x];
}
int ask(Node *u, Node *v, int l, int r, int x, int y, int z) {
  if (y < l || r < x) return -1;
  auto k = u->w ^ v->w;
  if (!k && (z < l || z > r)) return -1;
  if (l == r) {
    if (l != z || !k) return l;
    return -1;
  }
  int m = l + r >> 1;
  int res = ask(u->ls, v->ls, l, m, x, y, z);
  return res != -1 ? res : ask(u->rs, v->rs, m + 1, r, x, y, z);
}
int main() {
  null = new Node;
  null->ls = null->rs = null;
  null->w = 0;
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  pw[0] = 1;
  for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * 31;
  for (int i = 1, x, y; i < n; i++) {
    std::cin >> x >> y;
    g[x].push_back(y), g[y].push_back(x);
  }
  root[0] = null;
  dfs(1);
  for (int i = 1; i < 20; i++) {
    for (int j = 1; j <= n; j++) {
      f[i][j] = f[i - 1][f[i - 1][j]];
    }
  }
  while (m--) {
    int x, y, l, r;
    std::cin >> x >> y >> l >> r;
    int z = lca(x, y);
    std::cout << ask(root[x], root[y], 1, n, l, r, a[z]) << "\n";
  }
  return 0;
}
/*

 */