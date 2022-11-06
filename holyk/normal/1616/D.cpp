// Author:  HolyK
// Created: Thu Dec 30 00:15:34 2021
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

constexpr int N(1e5 + 5);
int n, a[N];
LL s[N];
void solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::cin >> a[0];
  for (int i = 1; i <= n; i++) {
    a[i] -= a[0];
    s[i] = s[i - 1] + a[i];
  }
  int ans = n;
  LL m = -1e18;
  for (int i = 1, c = 0; i <= n; i++) {
    c++;
    if (c >= 2 && m > s[i]) {
      ans--;
      c = 0;
      m = -1e18;
    } else {
      smax(m, s[i - 1]);
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