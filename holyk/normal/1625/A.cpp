// Author:  HolyK
// Created: Sat Aug  6 08:59:41 2022
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
  int n, l;
  std::cin >> n >> l;
  std::vector<int> c(l);
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    for (int j = 0; j < l; j++) {
      c[j] += x >> j & 1;
    }
  }

  int ans = 0;
  for (int j = 0; j < l; j++) {
    if (c[j] > n - c[j]) ans |= 1 << j;
  }
  std::cout << ans << "\n";
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