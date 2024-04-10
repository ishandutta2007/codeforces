// Author:  HolyK
// Created: Sun Feb 20 23:02:19 2022
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
int n, m;
std::vector<int> g[N];

int col[N];
bool dfs(int x, int c) {
  col[x] = c;
  for (int y : g[x]) {
    if (~col[y]) {
      if (col[y] == col[x]) {
        return false;
      }
    } else {
      if (!dfs(y, c ^ 1)) {
        return false;
      }
    }
  }
  return true;
}

void solve() {
  std::cin >> n >> m;
  std::vector<std::array<int, 3>> a(m);
  for (int i = 0; i < m; i++) {
    int t, x, y;
    std::cin >> t >> x >> y;
    t--;
    a[i] = {t, x, y};
    g[x].push_back(y);
    g[y].push_back(x);
  }

  memset(col, -1, sizeof col);
  for (int i = 1; i <= n; i++) {
    if (col[i] == -1 && !dfs(i, 0)) {
      std::cout << "NO\n";
      return;
    }
  }
  
  for (int i = 1; i <= n; i++) g[i].clear();
  std::vector<int> d(n + 1);
  for (auto &[t, x, y] : a) {
    // std::cerr << x << " " << y << " " << col[x] << " " << col[y] << "\n";
    assert(col[x] != col[y]);
    if (col[x] != t) std::swap(x, y);
    g[x].push_back(y);
    d[y]++;
  }

  std::vector<int> q;

  for (int i = 1; i <= n; i++) {
    if (d[i] == 0) {
      q.push_back(i);
    }
  }

  for (int i = 0; i < q.size(); i++) {
    int x = q[i];
    for (int y : g[x]) {
      if (!--d[y]) {
        q.push_back(y);
      }
    }
  }

  if (q.size() == n) {
    std::cout << "YES\n";
    std::vector<int> ans(n);
    int t = 0;
    for (int x : q) {
      ans[x - 1] = t++;
    }
    for (int i = 0; i < n; i++) {
      std::cout << "LR"[col[i + 1]] << " " << ans[i] << "\n";
    }
    return;
  }
  
  std::cout << "NO\n";
}

int main() {
  // freopen("t.in", "r", stdin);
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  
  // std::cin >> t;
  
  while (t--) {
    solve();
  }
  return 0;
}