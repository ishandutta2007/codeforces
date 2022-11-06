// Author:  HolyK
// Created: Wed Mar  9 10:21:01 2022
#include <bits/stdc++.h>
#include <numeric>

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
  std::vector<std::array<int, 3>> a(m);
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    a[i] = {y, x, i + 1};
  }
  std::sort(a.begin(), a.end());
  a.resize(n * 2);
  LL ans = 0;
  for (auto &[x, y, z] : a) std::swap(x, y), ans += y;
  std::sort(a.begin(), a.end());
  std::cout << ans << "\n";
  for (int i = 0; i < n; i++) {
    std::cout << a[i][2] << " " << a[2 * n - i - 1][2] << "\n";
  }
}

int main() {
  // freopen("t.in", "r", stdin);
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  
  std::cin >> t;
  
  while (t--) {
    solve();
  }
  return 0;
}