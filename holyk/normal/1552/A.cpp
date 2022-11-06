// Author:  HolyK
// Created: Sun Jul 25 22:25:46 2021
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
    int x;
    std::string a, b;
    std::cin >> x >> a;
    b = a;
    std::sort(b.begin(), b.end());
    int c = 0;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] != b[i]) c++;
    }
    std::cout << c << "\n";
  }
  return 0;
}
/*

 */