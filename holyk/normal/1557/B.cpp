// Author:  HolyK
// Created: Mon Aug  9 22:39:05 2021
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

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int &x : a) std::cin >> x;
    auto b = a;
    std::sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
      a[i] = std::lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }
    int cnt = 0;
    for (int i = 0, j; i < n; i = j) {
      for (j = i + 1; j < n && a[j] == a[j - 1] + 1; j++) ;
      cnt++;
    }
    // std::cerr << cnt << "\n";
    if (cnt <= k) {
      std::cout << "Yes\n";
    } else {
      std::cout << "No\n";
    }
  }
  return 0;
}