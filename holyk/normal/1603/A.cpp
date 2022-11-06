// Author:  HolyK
// Created: Sat Oct 30 22:34:49 2021
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
  bool ok = true;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    bool s = false;
    for (int j = i + 2; j >= 1 && j >= i - 30; j--) {
      if (a[i] % j) {
        s = true;
        break;
      }
    }
    if (!s) {
      ok = false;
    }
  }
  std::cout << (ok ? "YES\n" : "NO\n");
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