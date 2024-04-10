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

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(m);
    int ans = 0;
    for (int i = 0; i < m; i++) {
      std::cin >> a[i];
      for (int j = 0; j < i; j++) {
        ans += a[j] < a[i];
      }
    }
    std::cout << ans << "\n";
  }
  return 0;
}