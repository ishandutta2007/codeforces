// Author:  HolyK
// Created: Mon Aug  9 22:59:58 2021
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
constexpr int P(1e9 + 7);
inline void inc(int &x, int y) {
  x += y;
  if (x >= P) x -= P;
}
inline int mod(LL x) {
  return x % P;
}
int fpow(int x, int k = P - 2) {
  int r = 1;
  for (; k; k >>= 1, x = 1LL * x * x % P) {
    if (k & 1) r = 1LL * r * x % P;
  }
  return r;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n, k;
    std::cin >> n >> k;
    int cnt = 1, ans = 0;
    int pw2 = fpow(2, n - 1);
    for (int i = 0; i < k; i++) {
      int p = pw2;
      if (~n & 1) {
        ans = mod(ans + 1LL * cnt * fpow(fpow(2, k - 1 - i), n));
        p--;
      } else {
        p++;
      }
      cnt = 1LL * cnt * p % P;
    }
    std::cout << (ans + cnt) % P << "\n";
  }
  return 0;
}