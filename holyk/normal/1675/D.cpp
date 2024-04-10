// Author:  HolyK
// Created: Thu May  5 23:29:01 2022
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

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> p(n + 1), d(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> p[i];
    if (p[i] == i) p[i] = 0;
    d[p[i]]++;
  }

  std::vector<bool> vis(n + 1);
  std::vector<std::vector<int>> ans;
  std::function<void(int)> dfs = [&](int x) {
    if (!x || vis[x]) return;
    vis[x] = true;
    dfs(p[x]);
    ans.back().push_back(x);
  };

  for (int i = 1; i <= n; i++) {
    if (!d[i]) ans.push_back({}), dfs(i);
  }
  std::cout << ans.size() << "\n";
  for (auto &v : ans) {
    std::cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) {
      std::cout << v[i] << " \n"[i + 1 == v.size()];
    }
  }
  std::cout << "\n";
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