// Author:  HolyK
// Created: Mon Jul  4 22:51:21 2022
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

void solve() {
  int n;
  std::cin >> n;
  if (n & 1) {
    std::cout << "-1\n";
  } else {
    std::cout << n / 2 << " 0 0\n"; 
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t = 1;
  std::cin >> t;
 
  while (t--) {
    solve();
  }
  return 0;
}