// Author:  HolyK
// Created: Wed Oct 27 14:11:32 2021
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
    int n;
    std::cin >> n;
    std::vector<int> c(30);
    for (int i = 0, x; i < n; i++) {
      std::cin >> x;
      for (int j = 0; j < 30; j++) {
        if (x >> j & 1) c[j]++;
      }
    }
    int tot = 0;
    std::vector<int> ans(n + 1);
    for (int x : c) {
      if (!x) continue;
      tot++;
      for (int i = 1; 1LL * i * i <= x; i++) {
        if (x % i == 0) {
          ans[i]++;
          if (i * i < x) ans[x / i]++;
        }
        
      }
    }
    for (int i = 1; i <= n; i++) {
      if (ans[i] == tot) {
        std::cout << i << " ";
      }
    }
    std::cout << "\n";
  }
  return 0;
}