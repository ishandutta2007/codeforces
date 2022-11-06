// Author:  HolyK
// Created: Mon Aug  8 09:00:41 2022
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
  std::string s, t;
  std::cin >> s >> t;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] == t[0] && i % 2 == 0 && (n - i - 1) % 2 == 0) {
      std::cout << "YES\n";
      return;
    }
  }
  std::cout << "NO\n";
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