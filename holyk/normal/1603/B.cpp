// Author:  HolyK
// Created: Sat Oct 30 22:45:39 2021
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

void solve() {
  LL x, y;
  std::cin >> x >> y;
  if (x < y) {
    std::cout << (y % x) / 2 + (y / x) * x << "\n";
  } else if (x == y) {
    std::cout << x << "\n";
  } else {
    std::cout << x + y << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) solve();
  return 0;
}