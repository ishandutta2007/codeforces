// Author:  HolyK
// Created: Sun Jul 25 22:39:03 2021
#include <bits/stdc++.h>
#define dbg(a...) fprintf(stderr, a)
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
    int n;
    std::cin >> n;
    std::vector<std::array<int, 5>> a(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) std::cin >> a[i][j];
    }
    if (n == 1){
      std::cout << 1 << "\n";
      continue;
    }
    int p = 0;
    for (int i = 1; i < n; i++) {
      int c = 0;
      for (int j = 0; j < 5; j++) {
        if (a[i][j] < a[p][j]) c++;
      }
      if (c >= 3) p = i;
    }
    for (int i = 0; i < n; i++) {
      if (i == p) continue;
      int c = 0;
      for (int j = 0; j < 5; j++) {
        if (a[p][j] < a[i][j]) c++;
      }
      if (c < 3) {
        p = -2;
        break;
      }
    }
    std::cout << p + 1 << "\n";
  }
  return 0;
}
/*

 */