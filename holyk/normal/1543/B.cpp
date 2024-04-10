// Author:  HolyK
// Created: Thu Jul  8 09:12:40 2021
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
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    LL sum = 0;
    for (int &x : a) std::cin >> x, sum += x;
    int r = sum % n;
    std::cout << 1LL * r * (n - r) << "\n";
  }
  return 0;
}
/*
3
3
1 2 3
4
0 1 1 0
10
8 3 6 11 5 2 1 7 10 4

 */