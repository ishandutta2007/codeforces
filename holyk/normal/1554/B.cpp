// Author:  HolyK
// Created: Thu Jul 29 22:38:04 2021
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
  int t;
  std::cin >> t;
  while (t--) {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    LL ans = -1e18;
    for (int i = std::max(0, n - 200); i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        smax(ans, 1LL * (i + 1) * (j + 1) - 1LL * k * (a[i] | a[j]));
      }
    }
    std::cout << ans << "\n";
  }
  return 0;
}
/*

 */