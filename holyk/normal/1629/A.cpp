// Author:  HolyK
// Created: Mon Aug  1 08:59:36 2022
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
  int n, k;
  std::cin >> n >> k;
  std::vector<PII> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i].first;
  }
  for (int i = 0; i < n; i++) {
    std::cin >> a[i].second;
  }
  std::sort(a.begin(), a.end());
  for (auto &[x, y] : a) {
    if (k >= x) {
      k += y;
    }
  }
  std::cout << k << "\n";
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