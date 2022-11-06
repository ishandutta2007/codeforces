// Author:  HolyK
// Created: Fri Jul 30 00:22:02 2021
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
constexpr int N(1e5 + 5);
std::vector<int> primes;
bool np[N];
int mu[N];
void sieve(int n) {
  mu[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!np[i]) primes.push_back(i), mu[i] = -1;
    for (int j : primes) {
      if (1LL * i * j > n) break;
      np[i * j] = true;
      if (i % j == 0) {
        mu[i * j] = 0;
        break;
      }
      mu[i * j] = -mu[i];
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  sieve(1e5);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> g(n);
    for (int i = 1, x, y; i < n; i++) {
      std::cin >> x >> y;
      x--, y--;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    auto dfs = [&](auto rec, int x, int p, int k) -> int {
      int cnt = 0, del = 1;
      for (int y : g[x]) {
        if (y == p) continue;   
        int c = rec(rec, y, x, k);
        if (c == -1) return -1;
        cnt += c;
      }
      if (cnt % k == 0) {
        return 1;
      }
      if (~p && (cnt + 1) % k == 0) {
        return 0;
      }
      return -1;
    };
    std::vector<int> ans(n + 1), f(n + 1);
    ans[1] = fpow(2, n - 1);
    int t = n - 1;
    for (int i = 2; i <= n; i++) {
      if (t % i) continue;
      if (~dfs(dfs, 0, -1, i)) f[i] = 1;
    }
    for (int i = 2; i <= n; i++) {
      for (int j = 1; i * j <= n; j++) {
        ans[i] += mu[j] * f[i * j];
      }
    }
    for (int i = 2; i <= n; i++) inc(ans[1], P - ans[i]);
    for (int i = 1; i <= n; i++) {
      std::cout << ans[i] << " \n"[i == n];
    }
  }
  return 0;
}
/*

 */