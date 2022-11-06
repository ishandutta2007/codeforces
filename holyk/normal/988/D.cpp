// Author:  HolyK
// Created: Tue Oct  4 15:29:56 2022
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
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.end());

  std::vector<int> ans = {a[0]};
  for (int k = 0; k <= 30; k++) {
    std::vector<int> p(n, -1);
    for (int i = 0, j = 0; i < n; i++) {
      while (j < i && a[i] - a[j] > (1 << k)) {
        j++;
      }
      if (j < i && a[i] - a[j] == (1 << k)) {
        p[i] = j;
        if (~p[j]) {
          std::cout << 3 << "\n";
          std::cout << a[i] << " " << a[j] << " " << a[p[j]] << "\n";
          return;
        }
        ans = {a[i], a[j]};
      }
    }
  }

  std::cout << ans.size() << "\n";
  for (int x : ans) std::cout << x << " ";
}

int main() {
  // freopen("t.in", "r", stdin);
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  
  // std::cin >> t;
  
  while (t--) {
    solve();
  }
  return 0;
}