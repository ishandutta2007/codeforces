// Author:  HolyK
// Created: Fri Jun  4 22:34:56 2021
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
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    if (std::max(a, b) < std::min(c, d) || std::max(c, d) < std::min(a, b)) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
    }
  }
  return 0;
}
/*
4
3 7 9 5
4 5 6 9
5 3 8 1
6 5 3 2

 */