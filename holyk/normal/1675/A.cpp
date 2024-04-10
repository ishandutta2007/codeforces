// Author:  HolyK
// Created: Thu May  5 23:15:16 2022
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
  int a, b, c, x, y;
  std::cin >> a >> b >> c >> x >> y;
  x -= a, y -= b;
  smax(x, 0), smax(y, 0);
  if (x + y > c) {
    std::cout << "NO\n";
  } else {
    std::cout << "YES\n";
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