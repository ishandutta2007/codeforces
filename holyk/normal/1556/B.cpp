// Author:  HolyK
// Created: Sun Aug 29 22:38:22 2021
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
    std::vector<int> a(n);
    std::vector<int> p[2];
    int c = 0;
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      a[i] &= 1;
      c += a[i] ^ 1;
      p[a[i]].push_back(i);
    }
    if (std::abs(c - (n - c)) > 1) {
      std::cout << "-1\n";
      continue;
    }
   
    if (c == (n - c)) {
      LL cnt1 = 0, cnt2 = 0;
      for (int i = 0; i < c; i++) {
        cnt1 += std::abs(p[0][i] - 2 * i);
        cnt2 += std::abs(p[0][i] - 2 * i - 1);
      }
      std::cout << std::min(cnt1, cnt2) << "\n";
    } else {
      if (c > n - c) std::swap(p[0], p[1]), c = n - c;
      LL ans = 0;
      for (int i = 0; i < c; i++) {
        ans += std::abs(p[0][i] - 2 * i - 1);
      }
      std::cout << ans << "\n";
    }
  }
  return 0;
}