// Author:  HolyK
// Created: Mon Oct 18 16:30:19 2021
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

constexpr int N(3e5 + 5);
int n, m;
std::vector<int> g[N];
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

int fa[N], d[N];
void dfs(int x) {
  for (int y : g[x]) {
    if (y == fa[x]) continue;
    fa[y] = x;
    d[y] = d[x] + 1;
    dfs(y);
  }
}

int main() {
  // freopen("t.in", "r", stdin);
  // freopen(".out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> m;
  Dsu d(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    x--, y--;
    if (d.merge(x, y)) {
      g[x].push_back(y);
      g[y].push_back(x);
    }
  }
  
  std::cin >> m;
  std::vector<int> deg(n), a(m), b(m);
  for (int i = 0; i < m; i++) {
    std::cin >> a[i] >> b[i];
    a[i]--, b[i]--;
    deg[a[i]]++;
    deg[b[i]]++;
  }
  
  int c = 0;
  for (int i = 0; i < n; i++) {
    if (deg[i] & 1) {
      c++;
    }
  }

  if (c > 0) {
    std::cout << "NO\n" << c / 2 << "\n";
  } else {
    std::cout << "YES\n";
    for (int i = 0; i < m; i++) {
      std::swap(a[i], b[i]);
      fa[a[i]] = -1;
      ::d[a[i]] = 0;
      dfs(a[i]);
      std::cout << ::d[b[i]] - ::d[a[i]] + 1 << "\n";
      while (b[i] != a[i]) {
        std::cout << b[i] + 1 << " ";
        b[i] = fa[b[i]];
      }
      std::cout << a[i] + 1 << "\n";
    }
  }
  return 0;
}