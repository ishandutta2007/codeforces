// Author:  HolyK
// Created: Sun Aug  1 22:34:57 2021
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
  int n, m;
  std::cin >> n >> m;
  std::vector<int> d(n);
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    x--, y--;
    if (x < y) {
      d[x]++;
    } else {
      d[y]++;
    }
  }
  int ans = 0;
  for (auto &x : d) ans += !x;
  std::cin >> m;
  while (m--) {
    int opt, x, y;
    std::cin >> opt;
    if (opt == 3) {
      std::cout << ans << "\n";
    } else {
      std::cin >> x >> y;
      x--, y--;
      if (x > y) std::swap(x, y);
      if (opt == 1) {
        if (!d[x]++) ans--;
      } else {
        if (!--d[x]) ans++;
      }
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  solve();
  return 0;
}