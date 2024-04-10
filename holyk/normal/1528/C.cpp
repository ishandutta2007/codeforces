// Author:  HolyK
// Created: Mon May 24 23:30:05 2021
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
    std::vector<std::vector<int>> g(n), h(n);

    for (int i = 1; i < n; i++) {
      int x;
      std::cin >> x;
      g[x - 1].push_back(i);
    }
    for (int i = 1; i < n; i++) {
      int x;
      std::cin >> x;
      h[x - 1].push_back(i);
    }
    int cnt = 0;
    std::vector<int> in(n), out(n), id(n + 1);
    std::function<void(int)> dfs1 = [&](int x) {
      in[x] = ++cnt;
      id[cnt] = x;
      for (int y : h[x]) {
	dfs1(y);
      }
      out[x] = cnt;
    };
    // std::vector<int> c(n);
    // auto add = [&](int p, int x) {
    //   for (; p <= n; p += p & -p) c[p] += x;
    // };
    // auto ask = [&](int p) {
    //   int r = 0;
    //   for (; p; p -= p & -p) r += c[p];
    //   return r;
    // };
    
    int ans = 0, now = 0;
    std::vector<PII> up;
    std::set<int> s;
    std::function<void(int)> dfs2 = [&](int x) {
      auto it = s.lower_bound(in[x]);
      auto t = up.size();
      if (it == s.end() || *it > out[x]) {
	if (it == s.begin() || out[id[*--it]] < in[x]) {
	  
	} else {
	  up.emplace_back(*it, -1);
	  s.erase(it);
	}
	up.emplace_back(in[x], 1);
	s.insert(in[x]);
      }
      smax(ans, s.size());
      for (int y : g[x]) {
	dfs2(y);
      }
      while (up.size() > t) {
	auto [u, v] = up.back();
	up.pop_back();
	if (v == -1) s.insert(u);
	else s.erase(u);
      }
    };
    dfs1(0), dfs2(0);
    std::cout << ans << "\n";
  }
  return 0;
}
/*
4
4
1 2 3
1 2 3
5
1 2 3 4
1 1 1 1
6
1 1 1 1 2
1 2 1 2 2
7
1 1 3 4 4 5
1 2 1 4 2 5

 */