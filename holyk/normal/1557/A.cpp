// Author:  HolyK
// Created: Mon Aug  9 22:36:39 2021
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
  std::cout << std::fixed << std::setprecision(10);
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x : a) std::cin >> x;
    int max = *std::max_element(a.begin(), a.end());
    LL sum = std::accumulate(a.begin(), a.end(), 0LL);
    std::cout << max + 1.0 * (sum - max) / (n - 1) << "\n";
  }
  return 0;
}