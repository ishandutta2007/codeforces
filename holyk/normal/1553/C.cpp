// Author:  HolyK
// Created: Thu Jul 22 22:37:24 2021
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
    std::string s;
    std::cin >> s;
    std::vector<int> max(10, -1e9), min(10, 1e9);
    // max[0] = min[0] = 0;
    int ans = 10;
    for (int i = 0; i < 10; i++) {
      if (i) {
        max[i] = max[i - 1];
        min[i] = min[i - 1];
      } else {
        max[i] = min[i] = 0;
      }
      int d = i & 1 ? -1 : 1;
      if (s[i] == '1') {
        max[i] += d, min[i] += d;
      }
      if (s[i] == '?') {
        smax(max[i], max[i] + d);
        smin(min[i], min[i] + d);
      }
      // std::cerr << max[i] << " " << min[i] << "\n";
      if (min[i] + (9 - i) / 2 < 0 || max[i] - (10 - i) / 2 > 0) {
        ans = i + 1;
        // std::cout << i + 1 << "\n";
        break;
      }
    }
    std::cout << ans << "\n";
  }
  return 0;
}
/*

 */