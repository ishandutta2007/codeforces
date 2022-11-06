// Author:  HolyK
// Created: Thu Mar 10 22:38:31 2022
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
  std::vector<LL> a(n);
  a[0] = 1;
  for (int i = 1; i < n; i++) {
    a[i] = a[i - 1] * 3;
    if (a[i] > 1e9) {
      std::cout << "NO\n";
      return;
    }
  }
  std::cout << "YES\n";
  for (int x : a) std::cout << x << ' ';
  std::cout << "\n";
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