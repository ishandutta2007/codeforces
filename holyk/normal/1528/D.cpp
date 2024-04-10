// Author:  HolyK
// Created: Thu May 27 23:20:37 2021
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
  int n, m;
  std::cin >> n >> m;
  std::vector g(n, std::vector<int>(n, 2e9));
  while (m--) {
    int x, y, z;
    std::cin >> x >> y >> z;
    for (int i = 0; i < n; i++) {
      smin(g[x][(y + i) % n], z + i);
    }
  }
  for (int i = 0; i < n; i++) {
    std::vector<int> d(n, 2e9);
    std::vector<int> vis(n);
    d[i] = 0;
    for (int j = 0; j < n; j++) {
      int x = 0, min = 2e9;
      for (int k = 0; k < n; k++) {
	if (vis[k]) continue;
	if (smin(min, d[k])) x = k;
      }
      vis[x] = 1;
      for (int k = 0; k < n; k++) {
	int v = (d[x] + k) % n;
	smin(d[v], d[x] + g[x][k]);
      }
    }
    for (auto x : d) std::cout << x << " ";
    std::cout << "\n";
  }
  return 0;
}
/*
6 6
0 0 1
1 1 1
2 2 1
3 3 1
4 4 1
5 5 1

 */