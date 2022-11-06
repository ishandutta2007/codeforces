// Author:  HolyK
// Created: Mon Aug  2 00:12:39 2021
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

int c[4], v[4] = {0, 1, 1, 1};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    x /= 2;
    y /= 2;
    x &= 1;
    y &= 1;
    c[x << 1 | y]++;
    // std::cin >> a[i].x >> a[i].y;
    // a[i].x /= 2;
    // a[i].y /= 2;
  }
  LL ans = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = i; j < 4; j++) {
      for (int k = j; k < 4; k++) {
        if (!(v[i ^ j] ^ v[i ^ k] ^ v[j ^ k])) {
          if (i == j && j == k) {
            ans += 1LL * c[i] * (c[i] - 1) * (c[i] - 2) / 6;
          } else if (i == j || j == k) {
            ans += 1LL * c[j] * (c[j] - 1) / 2 * c[i ^ j ^ k];
          } else {
            ans += 1LL * c[i] * c[j] * c[k];
          }
        }
      }
    }
  }
  std::cout << ans << "\n";
  return 0;
}