// Author:  HolyK
// Created: Mon Oct 18 18:57:32 2021
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

int n, k;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> k;
  std::vector<int> ans;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int x = i, y = j, z = 1;
      while (x % k >= y % k) {
        x /= k, y /= k;
        z++;
      }
      ans.push_back(z);
    }
  }
  std::cout << *std::max_element(ans.begin(), ans.end()) << "\n";
  for (int i = 0; i < ans.size(); i++) {
    std::cout << ans[i] << " \n"[i + 1 == ans.size()];
  }
  return 0;
}