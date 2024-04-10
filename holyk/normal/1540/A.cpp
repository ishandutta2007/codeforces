// Author:  HolyK
// Created: Thu Jul  8 13:34:54 2021
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
    std::vector<int> a(n);
    for (int &x : a) std::cin >> x;
    std::sort(a.begin(), a.end());
    LL ans = 0, sum = 0;
    for (int i = 0; i < n; i++) {
      ans += sum - 1LL * i * a[i];
      sum += a[i];
    }
    std::cout << ans + a.back() << "\n";
  }
  return 0;
}
/*
3
3
0 2 3
2
0 1000000000
1
0

 */