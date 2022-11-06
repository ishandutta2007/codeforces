// Author:  HolyK
// Created: Wed Aug  3 08:59:52 2022
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
  int n, m;
  std::cin >> n >> m;
  if (n == 1 || m == 1) {
    if (std::max(n, m) <= 2) {
      std::cout << std::max(n, m) - 1 << "\n";
    } else {
      std::cout << "-1\n";
    }
  } else {
    int x = std::abs(n - m);
    std::cout << 2 * (std::min(n, m) - 1) + x % 2 + x / 2 * 4 << "\n"; 
  }
}

int main() {
  // freopen("t.in", "r", stdin);
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  
  std::cin >> t;
  
  while (t--) {
    solve();
  }
  return 0;
}