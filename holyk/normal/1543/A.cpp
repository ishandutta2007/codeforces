// Author:  HolyK
// Created: Thu Jul  8 09:01:15 2021
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
    LL a, b;
    std::cin >> a >> b;
    if (a == b) {
      std::cout << "0 0\n";
      continue;
    }
    if (a > b) std::swap(a, b);
    LL c = b - a;
    LL ans = (a + c - 1) / c * c - a;
    smin(ans, (b + c - 1) / c * c - b);
    smin(ans, a - a / c * c);
    smin(ans, b - b / c * c);
    std::cout << c << " " << ans << "\n";
  }
  return 0;
}
/*
4
8 5
1 2
4 4
3 9

 */