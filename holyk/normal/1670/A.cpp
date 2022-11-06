// Author:  HolyK
// Created: Sun Jul 17 09:03:41 2022
#include <algorithm>
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
  std::vector<int> a(n);
  int c = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    if (a[i] < 0) c++;
    a[i] = std::abs(a[i]);
  }
  for (int i = 0; i < c; i++) a[i] = -a[i];
  std::cout << (std::is_sorted(a.begin(), a.end()) ? "YES" : "NO") << "\n";
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