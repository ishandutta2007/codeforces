// Author:  HolyK
// Created: Fri May 20 20:35:00 2022
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
  int k;
  std::cin >> k;
  int n = 1 << k;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) std::cin >> a[i];
  
  std::vector<std::array<LL, 2>> c(k);
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j += 1 << i + 1) {
      int m = j + (1 << i), r = j + (1 << i + 1), u = j, v = m;
      for (int k = j; k < r; k++) {
        if (v == r || u < m && a[u] < a[v]) {
          c[i][1] += r - v;
          b[k] = a[u++];
        } else {
          b[k] = a[v++];
        }
      }
      u = j, v = m;
      for (int k = j; k < r; k++) {
        if (v == r || u < m && a[u] <= a[v]) {
          b[k] = a[u++];
        } else {
          c[i][0] += m - u;
          b[k] = a[v++];
        }
      }
      for (int k = j; k < r; k++) a[k] = b[k];
    }
  }
  int q;
  std::cin >> q;
  while (q--) {
    int x;
    std::cin >> x;
    for (int i = 0; i < x; i++) std::swap(c[i][0], c[i][1]);
    LL ans = 0;
    for (int i = 0; i < k; i++) ans += c[i][0];
    std::cout << ans << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t = 1;
  // std::cin >> t;
  while (t--) solve();
  return 0;
}