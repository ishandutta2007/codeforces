// Author:  HolyK
// Created: Fri May 20 18:21:17 2022
#include <bits/stdc++.h>

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

constexpr int N(4e5 + 5);
std::vector<int> g[N];

#define ls o << 1
#define rs o << 1 | 1
uint64_t val[N << 2], cov[N << 2];
void apply(int o, uint64_t x) {
  val[o] = cov[o] = x; 
}
void pushdown(int o) {
  if (cov[o]) {
    apply(ls, cov[o]), apply(rs, cov[o]);
    cov[o] = 0;
  }
}
void update(int o, int l, int r, int x, int y, uint64_t z) {
  if (x <= l && r <= y) return apply(o, z);
  pushdown(o);
  int m = l + r >> 1;
  if (x <= m) update(ls, l, m, x, y, z);
  if (y > m) update(rs, m + 1, r, x, y, z);
  val[o] = val[ls] | val[rs];
}
uint64_t ask(int o, int l, int r, int x, int y) {
  if (r < x || y < l) return 0;
  if (x <= l && r <= y) return val[o];
  pushdown(o);
  int m = l + r >> 1;
  return ask(ls, l, m, x, y) | ask(rs, m + 1, r, x, y);
}

int n, m, in[N], out[N], dfn, a[N];
void dfs(int x, int p) {
  in[x] = ++dfn;
  update(1, 1, n, dfn, dfn, 1ULL << a[x]);
  for (int y : g[x]) {
    if (y == p) continue;
    dfs(y, x);
  }
  out[x] = dfn;
}

void solve() {
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> a[i], a[i]--;
  for (int i = 1, x, y; i < n; i++) {
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);

  while (m--) {
    int opt, x;
    std::cin >> opt >> x;
    if (opt == 1) {
      std::cin >> a[x];
      a[x]--;
      update(1, 1, n, in[x], out[x], 1ULL << a[x]);
    } else {
      std::cout << __builtin_popcountll(ask(1, 1, n, in[x], out[x])) << "\n";
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t = 1;
  // std::cin >> t;
  while (t--) solve();
  return 0;
}