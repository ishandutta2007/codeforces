// Author:  HolyK
// Created: Sat Jul 31 00:15:53 2021
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

struct Dsu {
  std::vector<int> f;
  void clear() {
    std::iota(f.begin(), f.end(), 0);
  } 
  Dsu(int n) : f(n) { clear(); }
  int find(int x) {
    while (x != f[x]) {
      x = f[x] = f[f[x]];
    }
    return x;
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
  bool merge(int x, int y) {
    return !same(x, y) ? f[find(x)] = find(y), true : false;
  }
};
constexpr int N(3e5 + 5);
std::vector<PII> g[N];
int f[20][N], dep[N];
int d[N], in[N], out[N];
void dfs(int x) {
  in[x] = ++in[0];
  // std::cerr << x << " " << d[x] << " dfs\n";
  for (auto [y, z] : g[x]) {
    if (y == f[0][x]) continue;
    f[0][y] = x;
    dep[y] = dep[x] + 1;
    d[y] = d[x] ^ z;
    dfs(y);
  }
  out[x] = in[0];
}
int lca(int x, int y) {
  if (dep[x] < dep[y]) std::swap(x, y);
  for (int i = 0; dep[x] - dep[y]; i++) {
    if (dep[x] - dep[y] >> i & 1) {
      x = f[i][x];
    }
  }
  if (x == y) return x;
  for (int i = 18; i >= 0; i--) {
    if (f[i][x] != f[i][y]) {
      x = f[i][x];
      y = f[i][y];
    }
  }
  return f[0][x];
}
template <class T>
struct FenwickTree {
  std::vector<T> c;
  FenwickTree(int n) : c(n) {}
  void clear() const { std::fill(c.begin(), c.end(), 0); }
  void add(int p, T x) {
    for (; p < c.size(); p += p & -p) c[p] += x;
  }
  T ask(int p) const {
    T r = 0;
    for (; p; p -= p & -p) r += c[p];
    return r;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, q;
  std::cin >> n >> q;
  Dsu d(n + 1);
  std::vector<std::array<int, 3>> e(q);
  for (auto &[x, y, z] : e) std::cin >> x >> y >> z;
  for (auto [x, y, z] : e) {
    if (d.merge(x, y)) {
      g[x].push_back({y, z});
      g[y].push_back({x, z});
      // std::cerr << "link " <<  x << " " << y << "\n";
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!dep[i]) {
      dep[i] = 1;
      dfs(i);
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << i << " " << ::d[i] << "\n";
  // }
  for (int i = 1; i <= 18; i++) {
    for (int j = 1; j <= n; j++) {
      f[i][j] = f[i - 1][f[i - 1][j]];
    }
  }
  d.clear();
  FenwickTree<int> fen(n + 1);
  // Dsu dd;
  for (auto [x, y, z] : e) {
    if (d.merge(x, y)) {
      std::cout << "YES\n";
      continue;
    }
    // std::cerr << x << " " << y << " " << ::d[x] << " " << ::d[y] << "\n";
    if (!(::d[x] ^ ::d[y] ^ z)) {
      std::cout << "NO\n";
      continue;
    }
    int k = lca(x, y);
    if (fen.ask(in[x]) + fen.ask(in[y]) - 2 * fen.ask(in[k])) {
      std::cout << "NO\n";
      continue;
    }
    while (x != k) {
      fen.add(in[x], 1);
      fen.add(out[x] + 1, -1);
      x = f[0][x];
    }
    while (y != k) {
      fen.add(in[y], 1);
      fen.add(out[y] + 1, -1);
      y = f[0][y];
    }
    std::cout << "YES\n";
  }
  return 0;
}