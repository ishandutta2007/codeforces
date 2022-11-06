// Author:  HolyK
// Created: Thu Jul 29 23:22:21 2021
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
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    if (n <= 26) {
      for (int i = 0; i < n; i++) std::cout << char(i + 'a');
      std::cout << "\n";
    } else {
      std::string ans = std::string(n / 2, 'a') + 'b' + std::string(n / 2 - 1, 'a') + 'c';
      ans.resize(n);
      std::cout << ans << "\n";
    }
    
    

  }
  return 0;
}
/*

 */