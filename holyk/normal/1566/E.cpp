// Author:  HolyK
// Created: Sun Sep 12 23:51:27 2021
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
std::vector<int> g[N];
int n, deg[N];
void dfs(int x, int p) {
  for (auto i = g[x].begin(); i != g[x].end(); i++) {
    if (*i == p) {
      g[x].erase(i);
      break;
    }
  }
  deg[x] = g[x].size();
  for (int y : g[x]) {
    dfs(y, x);
    if (deg[y]) deg[x]--;
  }
}
void solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
  }
  for (int i = 1, x, y; i < n; i++) {
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  int leaf = 0, bud = 0, bleaf = 0;
  for (int i = 2; i <= n; i++) {
    if (deg[i]) {
      bud++;
      bleaf += deg[i];
    } else {
      leaf++;
    }
  }
  if (leaf - bleaf > 0) {
    std::cout << leaf - bud << "\n";
  } else {
    std::cout << leaf - bud + 1 << "\n";
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}