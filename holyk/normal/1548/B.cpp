// Author:  HolyK
// Created: Sun Aug  1 22:36:38 2021
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

constexpr int N(2e5 + 5);
LL a[N], s[18][N];
int lg[N];
void solve() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  a[0] = a[1];
  for (int i = 1; i <= n; i++) {
    s[0][i] = abs(a[i] - a[i - 1]);
  }
  for (int i = 2; i <= n; i++) {
    lg[i] = lg[i >> 1] + 1;
  }
  for (int i = 1; i < 18; i++) {
    for (int j = 1 << i; j <= n; j++) {
      s[i][j] = std::gcd(s[i - 1][j], s[i - 1][j - (1 << i - 1)]);
    }
  }
  auto gcd = [&](int i, int j) {
    int k = lg[j - i + 1];
    return std::gcd(s[k][j], s[k][i + (1 << k) - 1]);
  };
  int ans = 1;
  for (int i = 2, j = 2; i <= n; i++) {
    while (j <= i && gcd(j, i) == 1) j++;
    // std::cerr << i << " " << j << "\n";
    smax(ans, i - j + 2);
  }
  std::cout << ans << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}