// Author:  HolyK
// Created: Sun May 30 23:12:52 2021
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
#define int LL
constexpr int P(1e9 + 7);
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
void tmp() {
  int n = 15, k = 2;
  int m = (n + k - 1) / k;
  std::vector<int> f;
  for (int i = 1; i <= m; i++) {
    if (i == 1) {
      f.assign(n, 1);
    } else {
      for (int j = n - 1; j >= 0; j--) {
	f[j] = 0;
	for (int p = j - k; p >= 0; p--) f[j] += f[p];
      }
    }
    dbg("n = %d, k = %d, i = %d, f = %d\n", n, k, i, std::accumulate(f.begin(), f.end(), 0));
  }
  exit(0);
}
constexpr int N(2e5 + 5);
int fac[N], ifac[N];
int binom(int n, int m) {
  // assert();
  return m >= 0 && m <= n ? 1LL * fac[n] * ifac[m] % P * ifac[n - m] % P : 0;
}
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  // tmp();
  int n, k, t;
  n = 2e5;
  fac[0] = ifac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1LL * fac[i - 1] * i % P;
  ifac[n] = fpow(fac[n]);
  for (int i = n - 1; i >= 1; i--) ifac[i] = 1LL * ifac[i + 1] * (i + 1) % P;
  std::cin >> t;
  while (t--) {
    std::cin >> n >> k;
    int m = (n + k - 1) / k;
    int ans = 0;
    for (int i = 1; i <= m; i++) {
      int u = i - 1, v = n - k * u;
      int x = (1LL * v * binom(v + u, u) - 1LL * u * binom(v + u, i)) % P;
      // dbg("%d %d %d %d\n", n, k, i, x);
      ans = (ans + 1LL * x * fac[n - i] % P * fac[i]) % P;
    }
    ans = 1LL * ans * ifac[n] % P;
    std::cout << (P + 1 + ans) % P << "\n";
  }
  return 0;
}
/*
3
3 2
15 2
40 15

15 2 1 15
15 2 2 169
15 2 3 726
15 2 4 1485
15 2 5 1470
15 2 6 630
15 2 7 84
15 2 8 1
 */