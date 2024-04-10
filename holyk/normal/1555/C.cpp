// Author:  HolyK
// Created: Fri Jul 30 22:54:33 2021
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
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) std::cin >> a[i], i && (a[i] += a[i - 1]);
    for (int i = 0; i < n; i++) std::cin >> b[i], i && (b[i] += b[i - 1]);
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
      smin(ans, std::max(i ? b[i - 1] : 0, a.back() - a[i]));
    }
    std::cout << ans << "\n";
  }
  return 0;
}