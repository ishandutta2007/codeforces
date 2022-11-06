// Author:  HolyK
// Created: Fri Jul 30 22:35:02 2021
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
    LL n;
    std::cin >> n;
    if (n <= 6) {
      std::cout << 15 << "\n";
    } else {
      std::cout << (n + 1) / 2 * 5 << "\n";
    }
    
  }
  return 0;
}