// Author:  HolyK
// Created: Sat May 28 21:09:17 2022
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
namespace DT {
std::vector<int> g[N], h[N], dom[N];
int in[N], id[N], dfn, par[N], f[N], val[N], sem[N], fa[N];

void add(int x, int y) {
  g[x].push_back(y);
  h[y].push_back(x);
}
void dfs(int x) {
  in[x] = ++dfn, id[in[x]] = x;
  for (int y : g[x]) {
    if (in[y]) continue;
    dfs(y);
    par[in[y]] = in[x];
  }
}
int find(int x) {
  if (x == f[x]) return x;
  int y = find(f[x]);
  if (sem[val[f[x]]] < sem[val[x]]) val[x] = val[f[x]];
  return f[x] = y;
}
int tarjan(int s) {
  dfs(s);
  for (int i = 1; i <= dfn; i++) {
    f[i] = sem[i] = val[i] = i;
  }
  for (int y = dfn; y > 1; y--) {
    int x = par[y];
    for (int v : h[id[y]]) {
      int z = in[v];
      if (!z) continue;
      find(z);
      smin(sem[y], sem[val[z]]);
    }
    dom[sem[y]].push_back(y);
    f[y] = x;
    for (int v : dom[x]) {
      find(v);
      fa[v] = sem[val[v]] < x ? val[v] : x;
    }
    dom[x].clear();
  }
  for (int i = 2; i <= dfn; i++) {
    if (fa[i] != sem[i]) fa[i] = fa[fa[i]];
    dom[fa[i]].push_back(i);
  }
  fa[1] = 0;

  std::vector<int> ans(dfn + 1, 1);
  for (int i = dfn; i > 1; i--) {
    ans[fa[i]] += ans[i];
  }
  return dfn > 1 ? *std::max_element(ans.begin() + 2, ans.end()) : 0;
}
}

std::vector<PII> g[N];
LL d[N];

bool vis[N];

void solve() {
  int n, m, s;
  std::cin >> n >> m >> s;
  while (m--) {
    int x, y, z;
    std::cin >> x >> y >> z;
    g[x].push_back({y, z});
    g[y].push_back({x, z});
  }

  std::priority_queue<std::pair<LL, int>> q;
  memset(d, 0x3f, sizeof d);
  d[s] = 0;
  q.push({0LL, s});
  while (!q.empty()) {
    auto [_, x] = q.top();
    q.pop();
    if (vis[x]) continue;
    vis[x] = true;
    for (auto [y, z] : g[x]) {
      if (smin(d[y], d[x] + z)) {
        q.push({-d[y], y});
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (auto [j, z] : g[i]) {
      if (d[j] == d[i] + z) {
        DT::add(i, j);
      }
    }
  }

  std::cout << DT::tarjan(s) << "\n";
  
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}