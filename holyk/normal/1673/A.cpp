// Author:  HolyK
// Created: Mon Jul 18 09:03:10 2022
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
  std::string s;
  std::cin >> s;
  int n = s.length();
  std::vector<int> a(n + 1);
  for (int i = 0; i < n; i++) {
    a[i + 1] = a[i] + (s[i] - 'a' + 1);
  }
  int b;
  if (n & 1) {
    b = std::max(a[n] - a[1] - a[1], a[n - 1] - a[n] + a[n - 1]);
  } else {
    b = a[n];
  }
  if (b > 0) {
    std::cout << "Alice " << b << "\n";
  } else {
    std::cout << "Bob " << -b << "\n";
  }
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