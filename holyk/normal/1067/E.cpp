// Author:  HolyK
// Created: Mon Jul  5 20:35:41 2021
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
constexpr int N(5e5 + 5);
std::vector<int> g[N];
int f[N], ans;
void dfs(int x, int fa) {
  f[x] = 1;
  for (int y : g[x]) {
    if (y == fa) continue;
    dfs(y, x);
    f[x] = (P + 1LL >> 1) * f[x] % P * (1 + f[y]) % P;
  }
  f[x] = (P + 1 - f[x]) % P;
  inc(ans, f[x]);
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  for (int i = 1, x, y; i < n; i++) {
    std::cin >> x >> y;
    g[x].push_back(y), g[y].push_back(x);
  }
  dfs(1, 0);
  std::cout << 1LL * ans * fpow(2, n) % P << "\n";
  return 0;
}
/*
4
1 2
1 3
1 4
 */