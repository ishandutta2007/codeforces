// Author:  HolyK
// Created: Mon May 24 22:49:56 2021
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
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> np(n + 1), p, g(n + 1), c(n + 1), f(n + 1);
  f[1] = 1;
  g[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!np[i]) p.push_back(i), g[i] = 2, c[i] = 1;
    inc(f[i] = f[i - 1], g[i]);
    inc(f[i], f[i - 1]);
    for (int j : p) {
      if (j * i > n) break;
      np[j * i] = 1;
      if (i % j == 0) {
	g[i * j] += g[i] / (c[i] + 1) * (c[i] + 2);
	c[i * j] = c[i] + 1;
	break;
      }
      g[i * j] = g[i] << 1;
      c[i * j] = 1;
    }
  }
  std::cout << (f[n] - f[n - 1] + P) % P << "\n";
  return 0;
}
/*
2
3
6
100
 */