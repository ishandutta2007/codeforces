// Author:  HolyK
// Created: Mon Jul 12 19:20:29 2021
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

constexpr int P(998244353);
inline void inc(int &x, int y) {
  x += y;
  if (x >= P) x -= P;
}
int fpow(int x, int k = P - 2) {
  int r = 1;
  for (; k; k >>= 1, x = 1LL * x * x % P) {
    if (k & 1) r = 1LL * r * x % P;
  }
  return r;
}
constexpr int N(2e5 + 5);
int fac[N], ifac[N];
void init() {
  int n = 2e5;
  fac[0] = ifac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1LL * fac[i - 1] * i % P;
  ifac[n] = fpow(fac[n]);
  for (int i = n - 1; i; i--) ifac[i] = 1LL * ifac[i + 1] * (i + 1) % P;
}
int binom(int n, int m) {
  // assert(m >= 0 && m <= n);
  if (m < 0 || m > n) return 0;
  return 1LL * fac[n] * ifac[m] % P * ifac[n - m] % P;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  init();
  int t;
  std::cin >> t;
  while (t--) {
    int n, a = 0, b = 0;
    std::string s;
    std::cin >> n >> s;
    for (int i = 0, j; i < n; i = j) {
      for (j = i; j < n && s[i] == s[j]; j++) ;
      if (s[i] == '0') {
        a += j - i;
      } else {
        b += (j - i) / 2;
        // a += j - i & 1;
      }
    }
    std::cout << 1LL * fac[a + b] * ifac[a] % P * ifac[b] % P << "\n";
  }
  return 0;
}
/*

 */