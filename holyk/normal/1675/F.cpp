// Author:  HolyK
// Created: Thu May  5 23:56:28 2022
#include <bits/stdc++.h>

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

constexpr int N(2e5 + 5);

void solve() {
  int n, k, s, t;
  std::cin >> n >> k >> s >> t;
  s--, t--;
  std::vector<int> a(k);
  for (int i = 0; i < k; i++) std::cin >> a[i], a[i]--;
  std::vector<std::vector<int>> g(n);
  for (int i = 1, x, y; i < n; i++) {
    std::cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  std::vector<int> dep(n), fa(n, -1);
  std::function<void(int)> dfs = [&](int x) {
    for (int y : g[x]) {
      if (fa[x] == y) continue;
      fa[y] = x;
      dep[y] = dep[x] + 1;
      dfs(y);
    }
  };

  dfs(s);
  LL ans = 0;
  std::vector<bool> vis(n);
  a.push_back(t);
  for (int i : a)
    for (int j = i; ~j && !vis[j]; j = fa[j]) {
      vis[j] = true;
      ans++;
    }
  ans = (ans - 1) * 2 - dep[t];
  std::cout << ans << '\n';
}

int main() {
  // freopen("t.in", "r", stdin);
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  
  std::cin >> t;
  
  while (t--) {
    solve();
  }
  return 0;
}