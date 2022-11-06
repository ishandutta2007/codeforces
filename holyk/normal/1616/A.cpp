// Author:  HolyK
// Created: Wed Dec 29 23:25:39 2021
#include <bits/stdc++.h>
template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}
template <int S>
using AI = std::array<int, S>;
using LL = long long;
using PII = std::pair<int, int>;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(205);
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    a[x + 100]++;
  }
  int ans = a[100] > 0;
  for (int i = 1; i <= 100; i++) {
    if (a[i + 100] + a[-i + 100] > 1) {
      ans += 2;
    } else if (a[i + 100] + a[-i + 100] > 0) {
      ans++;
    }
  }
  std::cout << ans << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}