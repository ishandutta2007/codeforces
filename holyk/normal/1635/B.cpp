// Author:  HolyK
// Created: Sun Feb 20 22:38:38 2022
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
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  int ans = 0;
  for (int i = 2; i < n; i++) {
    if (a[i] < a[i - 1] && a[i - 2] < a[i - 1]) {
      a[i] = a[i - 1];
      if (i + 1 < n) smax(a[i], a[i + 1]);
      ans++;
    }
  }
  std::cout << ans << "\n";
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << " \n"[i + 1 == n];
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