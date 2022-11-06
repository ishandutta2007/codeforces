// Author:  HolyK
// Created: Sun Aug 29 23:03:21 2021
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
  int n;
  std::cin >> n;
  std::vector<LL> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    // if (i & 1) {
    //   a[i] *= -1;
    // }
    // if (i) {
    //   a[i] += a[i - 1];
    // }
  }
  LL ans = 0;
  for (int i = 0; i < n; i++) {
    if (i & 1) continue;
    LL sum = 0, min = 0;
    for (int j = i + 1; j < n; j++) {
      smin(min, sum);
      if (j & 1) {
        LL l = std::max(1LL, -min), r = std::min(a[i], a[j] - sum);
        
        if (l <= r) {
          ans += r - l + 1;
          // std::cerr << i + 1 << " " << j + 1 << " " << r - l + 1 << "\n";
        }
        sum -= a[j];
      } else {
        sum += a[j];
      }
    }

  }
  std::cout << ans << "\n";
  return 0;
}