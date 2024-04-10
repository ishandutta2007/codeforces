// Author:  HolyK
// Created: Sun Mar  6 17:56:54 2022
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
  std::map<int, std::vector<int>> v[2];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int c;
      std::cin >> c;
      v[0][c].push_back(i);
      v[1][c].push_back(j);
    }
  }

  LL ans = 0;
  for (int i = 0; i < 2; i++) {
    for (auto &[_, a] : v[i]) {
      LL s = 0;
      std::sort(a.begin(), a.end());
      for (int x : a) {
        s += x;
      }
      LL t = 0;
      int c = 0, n = a.size();
      for (int x : a) {
        ans += 1LL * c * x - t + s - t - 1LL * (n - c) * x;
        t += x;
        c++;
      }
    }
  }
  std::cout << ans / 2 << "\n";
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