// Author:  HolyK
// Created: Tue Aug 24 22:34:34 2021
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
    int a, b;
    std::cin >> a >> b;
    int n = a + b, p = n / 2;
    std::set<int> s;
    auto add = [&](int x) {
      if (x <= a && p - x <= b) {
        s.insert(p + a - x * 2);
      }
      if (x <= b && p - x <= a) {
        s.insert(p + b - x * 2);
      }
    };
    int r = std::min(p, std::max({a, b}));
    for (int i = 0; i <= r; i++) add(i);
    std::cout << s.size() << "\n";
    for (int x : s) std::cout << x << " ";
    std::cout << "\n";
  }
  return 0;
}