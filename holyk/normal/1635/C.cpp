// Author:  HolyK
// Created: Sun Feb 20 22:41:06 2022
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
  for (int i = n - 1; i > 0; i--) {
    if (a[i] < a[i - 1]) {
      std::cout << "-1\n";
      return;
    }
    if (a[i] >= 0) {
      std::cout << i - 1 << "\n";
      for (int j = 0; j < i - 1; j++) {
        std::cout << j + 1 << " " << i << ' ' << i + 1 << "\n";
      }
      return;
    } 
  }
  std::cout << "0\n";
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