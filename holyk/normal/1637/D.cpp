// Author:  HolyK
// Created: Sat Feb 12 23:17:30 2022
#include <algorithm>
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
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }

  std::vector<LL> f(10001), g;
  LL s = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    g.assign(10001, 1e18);
    for (int j = 0; j <= s; j++) {
      if (j + a[i] <= 10000) smin(g[j + a[i]], f[j] + a[i] * j + b[i] * (s - j));
      if (j + b[i] <= 10000) smin(g[j + b[i]], f[j] + b[i] * j + a[i] * (s - j));
    }
    s += a[i] + b[i];
    f.swap(g);

    sum += a[i] * a[i] + b[i] * b[i];
  }
  std::cout << *std::min_element(f.begin(), f.end()) * 2 + sum * (n - 1) << '\n';
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