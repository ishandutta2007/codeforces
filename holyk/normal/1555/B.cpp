// Author:  HolyK
// Created: Fri Jul 30 22:41:08 2021
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
    int n, m;
    std::cin >> n >> m;
    int x1, y1, x2, y2, a, b;
    std::cin >> x1 >> y1 >> x2 >> y2 >> a >> b;
    int ans = 1e9;
    if (x2 + a - n <= x1) smin(ans, x2 + a - n);
    if (0 - x1 + a <= n - x2) smin(ans, 0 - x1 + a);
    if (y2 + b - m <= y1) smin(ans, y2 + b - m);
    if (0 - y1 + b <= m - y2) smin(ans, 0 - y1 + b);
    smax(ans, 0);
    if (ans == 1e9) {
      puts("-1");
    } else {
      printf("%d\n", ans);
    }
    
  }
  return 0;
}