// Author:  HolyK
// Created: Thu Jul  8 14:26:34 2021
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
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector d(n, std::vector<int>(n, 1e9));
  for (int i = 1, x, y; i < n; i++) {
    std::cin >> x >> y;
    x--, y--;
    d[x][y] = d[y][x] = 1;
  }
  for (int i = 0; i < n; i++) d[i][i] = 0;
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
	smin(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  auto f = d;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j == 0) {
	f[i][j] = 1;
	continue;
      }
      if (i == 0) {
	f[i][j] = 0;
	continue;
      }
      f[i][j] = (P + 1LL >> 1) * (f[i - 1][j] + f[i][j - 1]) % P;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      for (int k = 0; k < n; k++) {
	int x = d[i][k], y = d[j][k], z = (x + y - d[i][j]) / 2;
	inc(ans, f[x - z][y - z]);
      }
  std::cout << 1LL * ans * fpow(n) % P;
  return 0;
}
/*
3
1 2
1 3

 */