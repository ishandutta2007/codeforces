// Author:  HolyK
// Created: Mon Feb 21 16:09:25 2022
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

void solve() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> x(n), w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> x[i] >> w[i];
  }

  std::vector<int> s;
  std::vector<std::vector<int>> g(n);
  for (int i = 0; i < n; i++) {
    while (!s.empty() && w[i] < w[s.back()]) {
      s.pop_back();
    }
    if (!s.empty()) {
      g[s.back()].push_back(i);
    }
    s.push_back(i);
  }

  s.clear();
  for (int i = n - 1; i >= 0; i--) {
    while (!s.empty() && w[i] < w[s.back()]) {
      s.pop_back();
    }
    if (!s.empty()) {
      g[i].push_back(s.back());
    }
    s.push_back(i);
  }

  std::vector<std::vector<PII>> q(n);
  for (int i = 0; i < m; i++) {
    int l, r;
    std::cin >> l >> r;
    l--;
    q[l].push_back({r, i});
  }

  std::vector<LL> ans(m, LLONG_MAX), c(n, LLONG_MAX);
  
  for (int i = n - 1; i >= 0; i--) {
    for (int j : g[i]) {
      LL v = 1LL * (x[j] - x[i]) * (w[i] + w[j]);
      for (int p = j + 1; p <= n; p += p & -p) {
        smin(c[p - 1], v);
      }
    }
    for (auto &[j, id] : q[i]) {
      for (int p = j; p; p -= p & -p) {
        smin(ans[id], c[p - 1]);
      }
    }
  }

  for (auto x : ans) std::cout << x << "\n";
}

int main() { 
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}