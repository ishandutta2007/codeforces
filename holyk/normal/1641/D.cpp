// Author:  HolyK
// Created: Sat Feb 26 16:47:08 2022
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
  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  std::vector<int> b(n), c(n * m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j];
      c[i * m + j] = a[i][j];
    }
    std::cin >> b[i];
  }

  std::sort(c.begin(), c.end());
  c.resize(std::unique(c.begin(), c.end()) - c.begin());
  for (auto &u : a) {
    for (auto &i : u) {
      i = std::lower_bound(c.begin(), c.end(), i) - c.begin();
    }
  }
  
  std::mt19937 rng(123);
  std::vector<int> d(c.size());

  int ans = INT_MAX;
  
  for (int t = 0; t < 30; t++) {
    for (auto &x : d) x = rng() % 16;
    std::vector<int> min(1 << 16, INT_MAX), s(n);
    for (int i = 0; i < n; i++) {
      for (int &x : a[i]) s[i] |= 1 << d[x];
      smin(min[s[i]], b[i]);
    }

    for (int i = 1; i < 1 << 16; i *= 2) {
      for (int j = 0; j < 1 << 16; j += i * 2) {
        for (int k = 0; k < i; k++) {
          smin(min[i + j + k], min[j + k]);
        }
      }
    }

    for (int i = 0; i < n; i++) {
      smin(ans, (LL)b[i] + min[(1 << 16) - 1 ^ s[i]]);
    }
  }

  std::cout << (ans == INT_MAX ? -1 : ans) << "\n";
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