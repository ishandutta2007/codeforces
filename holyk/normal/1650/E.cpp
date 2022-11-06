// Author:  HolyK
// Created: Wed Mar  9 10:45:16 2022
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
  std::vector<int> a(n + 2), premax(n + 2), premin(n + 2, 1e9), sufmax(n + 2), sufmin(n + 2, 1e9);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i + 1];
  }
  
  for (int i = 1; i <= n; i++) {
    premax[i] = premin[i] = a[i] - a[i - 1];
    if (i < n) {
      sufmax[i] = sufmin[i] = a[i + 1] - a[i];
    }
    smax(premax[i], premax[i - 1]);
    smin(premin[i], premin[i - 1]);
  }
  for (int i = n; i; i--) {
    smax(sufmax[i], sufmax[i + 1]);
    smin(sufmin[i], sufmin[i + 1]);
  }

  int ans = std::min(premin[n], sufmin[n]);
  for (int i = 1; i <= n; i++) {
    smax(ans, std::min({
          premin[i - 1], sufmin[i + 1], i < n ? (a[i + 1] - a[i - 1]) / 2 : m - a[i - 1]
        }));
    smax(ans, std::min({
          premin[i - 1], sufmin[i + 1], i < n ? a[i + 1] - a[i - 1] : 1000000000, std::max({m - a[n], premax[i - 1] / 2, sufmax[i + 1] / 2})
        }));
  }
  std::cout << ans - 1 << "\n";
}

int main() {
//  freopen("t.in", "r", stdin);
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  
  std::cin >> t;
  
  while (t--) {
    solve();
  }
  return 0;
}