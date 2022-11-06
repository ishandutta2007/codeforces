// Author:  HolyK
// Created: Thu Jul 22 22:54:54 2021
#include <bits/stdc++.h>
#define dbg(a...) fprintf(stderr, a)
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
  int q;
  std::cin >> q;
  while (q--) [&]{
    std::string s, t;
    std::cin >> s >> t;
    int n = s.length(), m = t.length();
    for (int i = 0; i < n; i++) {
      for (int j = 0; i + j < n && j < m && s[i + j] == t[j]; j++) {
        if (i + j + 1 < m - 1 - j) continue;
        auto k = s.substr(0, i + j);
        std::reverse(k.begin(), k.end());
        auto c = t.substr(j + 1);
        k.resize(c.length());
        if (k == c) {
          std::cout << "YES\n";
          return;
        }
      }
    }
    std::cout << "NO\n";
    }();
  return 0;
}
/*

 */