// Author:  HolyK
// Created: Thu Jul 22 23:07:26 2021
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
    std::reverse(s.begin(), s.end());
    std::reverse(t.begin(), t.end());
    std::vector<std::array<int, 26>> next(n + 1);
    for (int &x : next.back()) x = n;
    for (int i = n - 1; i >= 0; i--) {
      next[i] = next[i + 1];
      next[i][s[i] - 'a'] = i;
    }
    int i = -1, j;
    for (char c : t) {
      int x = c - 'a';
      for (j = next[i + 1][x]; j < n && (j - i & 1 ^ 1); j = next[j + 1][x])
      ;
      if (j == n) {
        std::cout << "NO\n";
        return;
      }
           
      // std::cerr << i << " " << j << "\n";
      i = j;
    }
    std::cout << "YES\n";
    }();
  return 0;
}
/*

 */