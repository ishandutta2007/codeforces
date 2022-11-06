// Author:  HolyK
// Created: Thu Jul  8 09:48:07 2021
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

int ask(int x) {
  std::cout << x << std::endl;
  int r;
  std::cin >> r;
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
    if (ask(0)) continue;
    for (int i = 1; i < n; i++) {
      int x = 0;
      for (int j = 1; j <= i; j *= k) {
	int u = (i / j - (i - 1) / j) % k;
	if (i & 1) u = (k - u) % k;
	x += u * j;
      }
      if (ask(x)) break;
    }
  }
  return 0;
}
/*
0
 */