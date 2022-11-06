// Author:  HolyK
// Created: Sat Jul 30 09:01:39 2022
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
  int n, z;
  std::cin >> n >> z;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 29; i >= 0; i--) {
    int m = *std::max_element(a.begin(), a.end()), m0 = 0;
    for (int j = 0; j < n; j++) {
      smax(m0, a[j] | z);
    }
    if (m0 > m) {
      int t0 = 0;
      for (int j = 0; j < n; j++) {
        if (m0 == (a[j] | z)) {
          smax(t0, a[j] & z);
        }
      }
      for (int j = 0; j < n; j++) {
        if (m0 == (a[j] | z) && t0 == (a[j] & z)) {
          a[j] = m0;
          z = t0;
          break;
        }
      }
    }
  }
  std::cout << *std::max_element(a.begin(), a.end()) << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  
  std::cin >> t;
  
  while (t--) {
    solve();
  }
  return 0;
}