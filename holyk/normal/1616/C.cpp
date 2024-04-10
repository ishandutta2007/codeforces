// Author:  HolyK
// Created: Thu Dec 30 00:04:51 2021
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
  int n;
  std::cin >> n;
  
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  if (n == 1) {
    std::cout << "0\n";
    return;
  }
  int ans = n;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int c = 0;
      for (int k = 0; k < n; k++) {
        if ((a[k] - a[i]) * (j - i) != (a[j] - a[i]) * (k - i)) {
          c++;
        }
      }
      smin(ans, c);
    }
  }
  std::cout << ans << "\n";
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