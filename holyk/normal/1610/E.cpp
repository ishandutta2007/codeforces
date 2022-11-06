// Author:  HolyK
// Created: Tue Nov 23 23:48:59 2021
#include <bits/stdc++.h>
template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}
template <int S>
using AI = std::array<int, S>;
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
    static int a[200005];
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    int ans = 2;
    for (int s = 0; s < n; s++) {
      int i = std::upper_bound(a + s + 1, a + n, a[s]) - a;
      int c = i - s;
      for (; i < n; c++) {
        i = std::lower_bound(a + i + 1, a + n, a[i] + a[i] - a[s]) - a;
      }
      smax(ans, c);
    }
    std::cout << n - ans << "\n";
  }
  return 0;
}