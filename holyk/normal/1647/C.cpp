// Author:  HolyK
// Created: Fri Mar 11 22:34:50 2022
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
  std::vector<std::string> s(n);
  for (int i = 0; i < n; i++) {
    std::cin >> s[i];
  }
  if (s[0][0] == '1') {
    std::cout << "-1\n";
    return;
  }
  std::vector<std::array<int, 4>> ans;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j; j--) {
      if (s[i][j] == '1') {
        ans.push_back({i, j - 1, i, j});
      }
    }
    if (s[i][0] == '1') {
      ans.push_back({i - 1, 0, i, 0});
    }
  }
  std::cout << ans.size() << "\n";
  for (auto [x, y, z, w] : ans) {
    std::cout << x + 1 << ' ' << y + 1 << ' ' << z + 1 << ' ' << w + 1 << "\n";
  }
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