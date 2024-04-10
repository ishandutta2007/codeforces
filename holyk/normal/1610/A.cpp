// Author:  HolyK
// Created: Tue Nov 23 22:33:03 2021
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
  int n, m;
  std::cin >> n >> m;
  if (n == 1 && m == 1) {
    std::cout << "0\n";
  } else {
    std::cout << std::min(2, std::min(n, m)) << "\n";
  }
  
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}