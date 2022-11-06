// Author:  HolyK
// Created: Fri May  6 00:27:18 2022
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
  std::vector<std::vector<int>> dp(m + 1, std::vector<int>(m + 1));
  for (int i = 1, s = 0; i <= n; i++) {
    int x;
    std::cin >> x;
    s += x;
    auto newdp = dp;
    for (int j = 0; j <= m; j++) {
      for (int k = 0; k <= m; k++) newdp[j][k] = 1e9; 
      for (int k = j; k >= 0; k--) {
        if (k < j) newdp[j][k] = newdp[j][k + 1];
        smin(newdp[j][k], dp[j - k][k] + std::abs(j - s));
      }
    }
    dp = newdp;
  }
  std::cout << dp[m][0] << "\n";
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