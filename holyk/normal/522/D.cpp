// Author:  HolyK
// Created: Tue Jul 13 21:00:06 2021
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

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n), pre(n);
  for (int i = 0; i < n; i++) std::cin >> a[i];
  std::map<int, int> pos;
  for (int i = 0; i < n; i++) {
    pre[i] = pos[a[i]] - 1;
    pos[a[i]] = i + 1;
  }
  std::vector<std::vector<PII>> g(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    x--, y--;
    g[y].push_back({x, i});
  }
  std::vector<int> c(n + 1, 1e9), ans(m);
  for (int i = 0; i < n; i++) {
    if (pre[i] >= 0) {
      for (int j = pre[i] + 1; j; j -= j & -j) {
        smin(c[j], i - pre[i]);
      }
    }
    for (auto [l, id] : g[i]) {
      int x = 1e9;
      for (int j = l + 1; j <= i; j += j & -j) smin(x, c[j]);
      ans[id] = x == 1e9 ? -1 : x;
    }
  }
  for (int x : ans) std::cout << x << "\n";
  return 0;
}
/*

 */