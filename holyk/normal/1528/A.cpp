// Author:  HolyK
// Created: Mon May 24 22:34:53 2021
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
    std::vector<std::array<int, 2>> a(n);
    std::vector<std::array<LL, 2>> f(n);
    for (auto &[x, y] : a) std::cin >> x >> y;
    std::vector<std::vector<int>> g(n);
    for (int i = 1; i < n; i++) {
      int x, y;
      std::cin >> x >> y;
      x--, y--;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    std::function<void(int, int)> dfs = [&](int x, int fa) {
      for (int y : g[x]) {
	if (y == fa) continue;
	dfs(y, x);
	for (int i = 0; i < 2; i++) {
	  LL t = 0;
	  for (int j = 0; j < 2; j++) {
	    smax(t, f[y][j] + std::abs(a[x][i] - a[y][j]));
	  }
	  f[x][i] += t;
	}
      }
    };
    dfs(0, -1);
    std::cout << std::max(f[0][0], f[0][1]) << "\n";
  }
  return 0;
}
/*
3
2
1 6
3 8
1 2
3
1 3
4 6
7 9
1 2
2 3
6
3 14
12 20
12 19
2 12
10 17
3 17
3 2
6 5
1 5
2 6
4 6

 */