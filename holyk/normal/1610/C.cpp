// Author:  HolyK
// Created: Tue Nov 23 22:50:06 2021
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
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i] >> b[i];
  }
  
  auto check = [&](int x) {
    int c = 0;
    for (int i = 0, o = 1; i < n; i++) {
      if (x - a[i] <= o && o <= b[i] + 1) {
        c++;
        o++;
      }
    }
    return c >= x;
  };
  
  int l = 0, r = n;
  while (l < r) {
    int m = l + r + 1 >> 1;
    if (check(m)) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  std::cout << l << "\n";
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