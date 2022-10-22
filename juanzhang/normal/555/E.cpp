#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int maxn = 4e5 + 10;
int n, m, q, tot;

int h[maxn];

struct edges {
  int nxt, to;
} E[maxn << 1];

void addline(int u, int v) {
  static int cnt = 1;
  E[++cnt] = edges{h[u], v}, h[u] = cnt;
}

int bl[maxn], dfn[maxn], low[maxn], cut[maxn << 1];

void tarjan(int u, int f) {
  static int now;
  dfn[u] = low[u] = ++now;
  for (int i = h[u]; i; i = E[i].nxt) {
    int v = E[i].to;
    if (!dfn[v]) {
      tarjan(v, i);
      low[u] = min(low[u], low[v]);
      if (dfn[u] < low[v]) cut[i ^ 1] = cut[i] = 1;
    } else if (i != (f ^ 1)) {
      low[u] = min(low[u], dfn[v]);
    }
  }
}

void dfs(int u) {
  bl[u] = tot;
  for (int i = h[u]; i; i = E[i].nxt) {
    int v = E[i].to;
    if (!bl[v] && !cut[i]) dfs(v);
  }
}

void init() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    addline(u, v), addline(v, u);
  }
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) tarjan(i, 0);
  }
  for (int i = 1; i <= n; i++) {
    if (!bl[i]) tot++, dfs(i);
  }
}

int par[maxn];

int find(int x) {
  return par[x] == x ? x : par[x] = find(par[x]);
}

void unite(int x, int y) {
  par[find(x)] = find(y);
}

bool vis[maxn];
int val[2][maxn];

vector <int> e[maxn];

int fa[maxn], sz[maxn], dep[maxn], son[maxn], top[maxn];

void dfs1(int u, int f) {
  vis[u] = 1;
  sz[u] = 1;
  fa[u] = f;
  dep[u] = dep[f] + 1;
  for (int v : e[u]) {
    if (v != f) {
      dfs1(v, u);
      sz[u] += sz[v];
      if (sz[v] > sz[son[u]]) son[u] = v;
    }
  }
}

void dfs2(int u, int tp) {
  top[u] = tp;
  if (son[u]) dfs2(son[u], tp);
  for (int v : e[u]) {
    if (v != fa[u] && v != son[u]) {
      dfs2(v, v);
    }
  }
}

int lca(int u, int v) {
  for (; top[u] != top[v]; u = fa[top[u]]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
  }
  return dep[u] < dep[v] ? u : v;
}

bool FLG;

void DFS(int u, int f) {
  vis[u] = 1;
  for (int v : e[u]) {
    if (v != f) {
      DFS(v, u);
      val[0][u] += val[0][v];
      val[1][u] += val[1][v];
    }
  }
  if (val[0][u] && val[1][u]) {
    FLG = 1;
  }
}

int main() {
  init();
  for (int i = 1; i <= tot; i++) {
    par[i] = i;
  }
  for (int i = 2; i <= m * 2; i += 2) {
    if (!cut[i]) continue;
    int u = bl[E[i].to], v = bl[E[i ^ 1].to];
    if (find(u) != find(v)) {
      e[u].push_back(v), e[v].push_back(u), unite(u, v);
    }
  }
  for (int i = 1; i <= tot; i++) {
    if (!vis[i]) dfs1(i, 0), dfs2(i, i);
  }
  for (int i = 1; i <= q; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u = bl[u], v = bl[v];
    if (find(u) != find(v)) {
      return puts("No"), 0;
    }
    int anc = lca(u, v);
    val[0][u]++, val[0][anc]--;
    val[1][v]++, val[1][anc]--;
  }
  memset(vis, 0, sizeof vis);
  for (int i = 1; i <= tot; i++) {
    if (!vis[i]) DFS(i, 0);
  }
  puts(FLG ? "No" : "Yes");
  return 0;
}