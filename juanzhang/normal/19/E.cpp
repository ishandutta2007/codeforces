#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int maxn = 2e4 + 10;
int n, m, h[maxn];

struct edge {
  int u, v;
} E[maxn];

struct edges {
  int nxt, to;
} e[maxn << 1];

void addline(int u, int v) {
  static int cnt = 1;
  e[++cnt] = edges{h[u], v}, h[u] = cnt;
}

int par[maxn];
bool vis[maxn];

int find(int x) {
  return par[x] == x ? x : par[x] = find(par[x]);
}

void unite(int x, int y) {
  par[find(x)] = find(y);
}

int fa[maxn], sz[maxn], dep[maxn], son[maxn], top[maxn], mp[maxn];

int dfs1(int u, int f) {
  fa[u] = f;
  dep[u] = dep[f] + 1;
  for (int i = h[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (vis[i] && v != f) {
      mp[v] = i >> 1;
      sz[u] += dfs1(v, u);
      if (sz[son[u]] < sz[v]) son[u] = v;
    }
  }
  return ++sz[u];
}

void dfs2(int u, int tp) {
  top[u] = tp;
  if (son[u]) dfs2(son[u], tp);
  for (int i = h[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (vis[i] && v != fa[u] && v != son[u]) {
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

int val[maxn];
vector <int> ans;

int DFS(int u) {
  for (int i = h[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (vis[i] && v != fa[u]) val[u] += DFS(v);
  }
  return val[u];
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    par[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    E[i] = edge{u, v};
    addline(u, v), addline(v, u);
  }
  for (int i = 1; i <= m; i++) {
    int u = E[i].u, v = E[i].v;
    if (find(u) != find(v)) {
      unite(u, v);
      vis[(i << 1) ^ 1] = vis[(i << 1)] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (find(i) == i) {
      dfs1(i, 0), dfs2(i, i);
    }
  }
  int cnt = 0, pos;
  for (int i = 1; i <= m; i++) {
    if (vis[(i << 1)]) continue;
    int u = E[i].u, v = E[i].v;
    int anc = lca(u, v);
    if ((dep[u] + dep[v] - dep[anc] * 2 + 1) & 1) {
      cnt++, pos = i;
      val[u]++, val[v]++, val[anc] -= 2;
    } else {
      val[u]--, val[v]--, val[anc] += 2;
    }
  }
  if (!cnt) {
    printf("%d\n", m);
    for (int i = 1; i <= m; i++) {
      printf("%d ", i);
    }
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (find(i) == i) DFS(i);
  }
  for (int i = 1; i <= n; i++) {
    if (val[i] == cnt) ans.push_back(mp[i]);
  }
  if (cnt == 1) {
    ans.push_back(pos);
  }
  sort(ans.begin(), ans.end());
  printf("%d\n", (int) ans.size());
  for (int x : ans) printf("%d ", x);
  return 0;
}