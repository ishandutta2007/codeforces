// Author:  HolyK
// Created: Sun Sep 12 22:38:01 2021
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

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    std::string s;
    std::cin >> s;
    int n = s.length();
    int c = 0;
    for (int i = 0, j; i < n; i = j) {
      for (j = i + 1; j < n && s[i] == s[j]; j++) ;
      if (s[i] == '0') c++;
    }
    std::cout << std::min(2, c) << "\n";
  }
  return 0;
}