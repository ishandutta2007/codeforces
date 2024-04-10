// Author:  HolyK
// Created: Sun Sep 12 23:09:09 2021
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

struct P {
  int x, y;
  bool operator<(const P &r) const {
    return x < r.x || x == r.x && y > r.y;
  }
};
template <class T>
struct FenwickTree {
  std::vector<T> c;
  FenwickTree(int n) : c(n + 1) {}
  void clear() const { std::fill(c.begin(), c.end(), 0); }
  void add(int p, T x) {
    for (p++; p < c.size(); p += p & -p) c[p] += x;
  }
  T ask(int p) const {
    T r = 0;
    for (p++; p; p -= p & -p) r += c[p];
    return r;
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n * m);
    std::vector<PII> b(n * m);
    for (int i = 0; i < n * m; i++) {
      std::cin >> a[i];
      b[i] = {a[i], i};
    }
    std::sort(b.begin(), b.end());
    std::vector<P> p(n * m), q = p;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        p[i * m + j] = {i, j};
      }
    }
    std::vector<FenwickTree<int>> t(n, m);
    // std::vector<std::vector<int>> v(n, std::vector<int>(m));
    LL ans = 0;
    for (int i = 0, j; i < n * m; i = j) {
      for (j = i + 1; j < n * m && b[i].first == b[j].first; j++) ;
      std::sort(p.begin() + i, p.begin() + j);
      for (int k = i; k < j; k++) {
        q[b[k].second] = p[k];
        // v[p[k].x][p[k].y] = b[k].second;
      }
    }
    for (int i = 0; i < n * m; i++) {
      auto [x, y] = q[i];
      ans += t[x].ask(y);
      t[x].add(y, 1);
    }
    // for (int i = 0; i < n; i++) {
    //   std::vector<int> p(m);
    //   std::iota(p.begin(), p.end(), 0);
    //   std::sort(p.begin(), p.end())
    // }
    std::cout << ans << "\n";
  }
  return 0;
}