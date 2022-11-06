// Author:  HolyK
// Created: Thu Jul  8 12:01:06 2021
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
    int k, n;
    std::cin >> k;
    n = 1 << k;  
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < n * k / 2; i++) {
      int x, y;
      std::cin >> x >> y ;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    std::vector<int> q(1), d(n, 1e9), id(n), p(n);
    d[0] = 0;
    for (int i = 0; i < g[0].size(); i++) id[g[0][i]] = 1 << i;
    for (int i = 0; i < n; i++) {
      int x = q[i];
      for (int y : g[x]) {
	if (d[y] > d[x]) {
	  id[y] |= id[x];
	}
	if (smin(d[y], d[x] + 1)) {
	  q.push_back(y);
	}
      }
    }
    // for (int i = 0; i < n; i++) std::cout << id[i] << " \n"[i + 1 == n];
    for (int i = 0; i < n; i++) p[id[i]] = i;
    for (int x : p) std::cout << x << " ";
    std::cout << "\n";
    if (n % k) {
      std::cout << "-1\n";
      continue;
    }
    for (int i = 0; i < n; i++) {
      int ans = 0;
      for (int j = 0; j < k; j++) {
	if (id[i] >> j & 1) ans ^= j;
      }
      std::cout << ans << " ";
    }
    std::cout << "\n";
  }
  return 0;
}
/*
3
1
0 1
2
0 1
1 2
2 3
3 0
3
0 1
0 5
0 7
1 2
1 4
2 5
2 6
3 5
3 6
3 7
4 6
4 7

 */