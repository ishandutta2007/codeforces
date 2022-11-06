// Author:  HolyK
// Created: Thu Mar 10 22:42:43 2022
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
  int n;
  std::cin >> n;
  std::vector<LL> a(n), b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  
  LL ans = 1e18;
  LL val[4] = {a[0], b[0], a[n - 1], b[n - 1]};
  
  for (int i = 0; i < 3 * 3 * 3 * 3; i++) {
    bool v[4] = {};
    LL sum = 0;
    for (int x = i, j = 0; j < 4; j++) {
      int u = x % 3;
      x /= 3;
      if (v[j]) continue;
      v[j] = true;
      if (u == 0) {
        int k = j ^ 1;
        sum += std::abs(val[j] - val[k]);
        v[k] = true;
      } else if (u == 1) {
        int k = j ^ 3;
        sum += std::abs(val[j] - val[k]);
        v[k] = true;
      } else {
        LL min = 1e18;
        for (int i = 1; i + 1 < n; i++) {
          if (j & 1) {
            smin(min, std::abs(val[j] - a[i]));
          } else {
            smin(min, std::abs(val[j] - b[i]));
          }
        }
        sum += min;
      }
    }
    smin(ans, sum);
  }
  std::cout << ans << "\n";
}

int main() {
  // freopen("t.in", "r", stdin);
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  
  std::cin >> t;
  
  while (t--) {
    solve();
  }
  return 0;
}