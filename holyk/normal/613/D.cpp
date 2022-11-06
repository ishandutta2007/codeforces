// Author:  HolyK
// Created: Wed Aug 24 19:35:56 2022
#include <algorithm>
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

constexpr int N(1e5 + 5);
std::vector<int> g[N];
int st[17][N], lg[N], in[N], out[N], dfn, fa[N];
int get(int x, int y) {
  return in[x] < in[y] ? x : y;
}
int lca(int x, int y) {
  if (x == y) return x;
  x = in[x], y = in[y];
  if (x > y) std::swap(x, y);
  int k = lg[y - x];
  return get(st[k][x], st[k][y - (1 << k)]);
}
void init() {
  for (int i = 2; i <= dfn; i++) {
    lg[i] = lg[i >> 1] + 1;
  }
  for (int i = 1; i < 17; i++) {
    for (int j = 1; j + (1 << i) <= dfn; j++) {
      st[i][j] = get(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
    }
  }
}
void dfs(int x, int p) {
  st[0][dfn] = fa[x] = p;
  in[x] = ++dfn;
  for (int y : g[x]) {
    if (y != p) {
      dfs(y, x);
    }
  }
  out[x] = dfn;
}

int vis[N], vn, ans;
int dfs2(int x) {
  int c = 0;
  for (int y : g[x]) {
    c += dfs2(y);
  }
  g[x].clear();
  if (vis[x] == vn) {
    ans += c;
    return 1;
  }
  return c > 1 ? ans++, 0 : c;
}
void solve() {
  int n;
  std::cin >> n;
  for (int i = 1, x, y; i < n; i++) {
    std::cin >> x >> y;
    g[x].push_back(y), g[y].push_back(x);
  }

  dfs(1, 0);
  init();

  for (int i = 1; i <= n; i++) g[i].clear();
  int q;
  std::cin >> q;
  while (q--) {
    vn++;
    int k;
    std::cin >> k;
    std::vector<int> a(k), s(k * 2 + 1);
    for (int i = 0; i < k; i++) {
      std::cin >> a[i];
      vis[a[i]] = vn;
    }

    bool ok = true;
    for (int i : a) {
      if (vis[fa[i]] == vn) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      std::cout << "-1\n";
      continue;
    }

    std::sort(a.begin(), a.end(), [&](int i, int j){ return in[i] < in[j]; });
    int t = 0;
    auto pop = [&] { g[s[t - 1]].push_back(s[t]), t--; };
    for (int x : a) {
      if (t && out[x] > out[s[t]]) {
        int p = lca(s[t], x);
        while (t > 1 && in[s[t - 1]] >= in[p]) pop();
        if (s[t] != p) g[p].push_back(s[t]), s[t] = p;
      }
      s[++t] = x;
    }
    while (t > 1) pop();
    ans = 0;
    dfs2(s[1]);
    std::cout << ans << "\n";
  }
    
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