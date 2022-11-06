// Author:  HolyK
// Created: Mon Oct 18 19:45:12 2021
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

constexpr int N(4e5 + 5);

struct Edge {
  int a, b, c, d;
} e[N];
int n, m, a[N], b[N], bn;
int fa[N];
int find(int x) {
  while (x != fa[x]) x = fa[x] = fa[fa[x]];
  return x;
}

std::vector<int> g1[N], g2[N];
int f1[19][N], f2[19][N], v1[N], v2[N];
int in1[N], out1[N], in2[N], id2[N], dep2[N], lg[N];

int lca2(int x, int y) {
  if (dep2[x] < dep2[y]) std::swap(x, y);
  for (int i = 0; dep2[x] != dep2[y]; i++) {
    if (dep2[x] - dep2[y] >> i & 1)
      x = f2[i][x];
  }
  if (x == y) return x;
  for (int i = 18; i >= 0; i--) {
    if (f2[i][x] != f2[i][y]) {
      x = f2[i][x], y = f2[i][y];
    }
  }
  return f2[0][x];
}

struct Info {
  int val, max, min;
  friend Info operator+(Info a, Info b) {
    if (a.val == b.val)
      return {a.val, std::max(a.max, b.max), std::min(a.min, b.min)};
    return a.val > b.val ? a : b;
  }
} st[19][N];
  
Info ask(int l, int r) {
  int k = lg[r - l + 1];
  return st[k][r] + st[k][l + (1 << k) - 1];
}

void dfs2(int x) {
  in2[x] = in2[0] + 1;
  if (x <= n) {
    id2[++in2[0]] = x;
  }
  for (int y : g2[x]) {
    dep2[y] = dep2[x] + 1;
    dfs2(y);
  }
}

void dfs1(int x) {
  in1[x] = in1[0] + 1;
  if (x <= n) {
    st[0][++in1[0]] = {a[x], in2[x], in2[x]};
  }
  for (int y : g1[x]) {
    dfs1(y);
  }
  out1[x] = in1[0];
}

void init() {
  // kruskal1  
  std::sort(e + 1, e + n, [](Edge u, Edge v) {
    return u.c > v.c;
  });

  for (int i = 1; i <= n; i++) fa[i] = i;
  
  int t = n;
  for (int i = 1; i < n; i++) {
    int x = find(e[i].a), y = find(e[i].b);
    if (x == y) continue;
    t++;
    fa[x] = fa[y] = fa[t] = t;
    f1[0][x] = f1[0][y] = t;
    g1[t].push_back(x);
    g1[t].push_back(y);
    v1[t] = e[i].c;
  }
  assert(t == n * 2 - 1);
  
  for (int i = 1; i < 19; i++) {
    for (int j = 1; j <= t; j++) {
      f1[i][j] = f1[i - 1][f1[i - 1][j]];
    }
  }
  
  // kruskal2
  std::sort(e + 1, e + n, [](Edge u, Edge v) {
    return u.d < v.d;
  });

  for (int i = 1; i <= n; i++) fa[i] = i;
  
  t = n;
  for (int i = 1; i < n; i++) {
    int x = find(e[i].a), y = find(e[i].b);
    if (x == y) continue;
    t++;
    fa[x] = fa[y] = fa[t] = t;
    f2[0][x] = f2[0][y] = t;
    g2[t].push_back(x);
    g2[t].push_back(y);
    v2[t] = e[i].d;
  }

  for (int i = 1; i < 19; i++) {
    for (int j = 1; j <= t; j++) {
      f2[i][j] = f2[i - 1][f2[i - 1][j]];
    }
  }
    
  dfs2(t);

  dfs1(t);
  
  for (int i = 1; i < 18; i++) {
    for (int j = 1 << i; j <= n; j++) {
      st[i][j] = st[i - 1][j] + st[i - 1][j - (1 << i - 1)];
    }
  }
  
  for (int i = 2; i <= n; i++) {
    lg[i] = lg[i >> 1] + 1;
  }

}

int main() {
  // freopen("t.in", "r", stdin);
  // freopen(".out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> m;
  
  for (int i = 1; i <= n; i++) std::cin >> a[i];
    
  for (int i = 1; i < n; i++) {
    std::cin >> e[i].a >> e[i].b >> e[i].c >> e[i].d;
  }
  
  init();
  
  for (int i = 1; i <= m; i++) {
    int v, u, x;
    std::cin >> v >> u;
    x = u;
    for (int j = 18; j >= 0; j--) {
      if (f1[j][x] && v1[f1[j][x]] >= v) {
        x = f1[j][x];
      }
    }
    
    Info ans = ask(in1[x], out1[x]);
    smin(ans.min, in2[u]);
    smax(ans.max, in2[u]);
    std::cout << ans.val << " " << v2[lca2(id2[ans.min], id2[ans.max])] << "\n";
    
  }
  
  return 0;
}