// Author:  HolyK
// Created: Sun Aug 29 22:36:12 2021
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
    int c, d;
    std::cin >> c >> d;
    if (c + d & 1) {
      std::cout << "-1\n";
      continue;
    }
    std::cout << (c == d ? c ? "1\n" : "0\n" : "2\n");
  }
  return 0;
}