// Author:  HolyK
// Created: Wed Mar  9 10:29:50 2022
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
  std::vector<int> a(n), ans(n);
  for (int i = 0; i < n; i++) std::cin >> a[i], a[i]--;
  for (int i = n - 1; i >= 0; i--) {
    int j = std::find(a.begin(), a.end(), i) - a.begin();
    ans[i] = (j + 1) % (i + 1);
    std::rotate(a.begin(), a.begin() + (j + 1) % (i + 1), a.end());
    a.pop_back();
  }
  for (int i = 0; i < n; i++) {
    std::cout << ans[i] << " \n"[i + 1 == n];
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