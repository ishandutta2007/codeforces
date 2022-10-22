#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int maxn = 4e5 + 10;
int n, m, h[maxn];

struct edges {
  int nxt, to;
} e[maxn];

void addline(int u, int v) {
  static int cnt = 1;
  e[++cnt] = edges{h[u], v}, h[u] = cnt;
}

bool vis[maxn], ont[maxn];
int fa[maxn], dep[maxn], val[maxn];

int dfs(int u, int f) {
  int sum = 0;
  fa[u] = f;
  vis[u] = 1;
  dep[u] = dep[f] + 1;
  for (int i = h[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == f) continue;
    if (!vis[v]) {
      sum += dfs(v, u);
      ont[i ^ 1] = ont[i] = 1;
    } else if (dep[v] < dep[u]) {
      val[u]++, val[v]--;
    }
  }
  sum += val[u];
  return val[u] = sum;
}

int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  while (dep[u] != dep[v]) {
    u = fa[u];
  }
  if (u == v) return u;
  while (fa[u] != fa[v]) {
    u = fa[u], v = fa[v];
  }
  return fa[u];
}

vector <int> edge;

void DFS(int u, int rt) {
  for (int i = h[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (v == fa[u]) continue;
    if (ont[i]) {
      DFS(v, rt);
    } else if (dep[v] < dep[rt]) {
      edge.push_back(i);
    }
  }
}

int Q[maxn], pre[maxn];
bool flg[maxn], permit[maxn];

void run(int S, int T) {
  memset(pre, 0, sizeof pre);
  int l = 1, r = 1;
  Q[1] = S, pre[S] = -1;
  while (l <= r) {
    int u = Q[l++];
    for (int i = h[u]; i; i = e[i].nxt) {
      int v = e[i].to;
      if (ont[i] && !pre[v]) {
        pre[v] = i, Q[++r] = v;
      }
    }
  }
  for (int u = T, i = pre[u]; u != S; u = e[i ^ 1].to, i = pre[u]) {
    permit[i ^ 1] = permit[i] = 1;
  }
}

void bfs(int S, int T) {
  memset(pre, 0, sizeof pre);
  int l = 1, r = 1;
  Q[1] = S, pre[S] = -1;
  while (l <= r) {
    int u = Q[l++];
    for (int i = h[u]; i; i = e[i].nxt) {
      int v = e[i].to;
      if (!flg[v] && permit[i] && !pre[v]) {
        pre[v] = i, Q[++r] = v;
      }
    }
  }
  vector <int> path;
  for (int u = T, i = pre[u]; u != S; u = e[i ^ 1].to, i = pre[u]) {
    path.push_back(u);
    permit[i ^ 1] = permit[i] = 0, flg[u] = 1;
  }
  printf("%d ", (int) path.size() + 1);
  for (int u : path) printf("%d ", u);
  printf("%d\n", S);
  flg[S] = flg[T] = 0;
}

void solve(int rt) {
  DFS(rt, rt);
  assert(edge.size() > 1);
  int p1 = edge[0], p2 = edge[1];
  int u1 = e[p1 ^ 1].to, v1 = e[p1].to;
  int u2 = e[p2 ^ 1].to, v2 = e[p2].to;
  if (dep[u1] > dep[v1]) swap(u1, v1);
  if (dep[u2] > dep[v2]) swap(u2, v2);
  int S = lca(v1, v2), T = dep[u1] < dep[u2] ? u2 : u1;
  permit[p1 ^ 1] = permit[p1] = 1;
  permit[p2 ^ 1] = permit[p2] = 1;
  run(u1, v1), run(u2, v2), run(u1, v2), run(u2, v1);
  puts("YES");
  int Tests = 3;
  while (Tests--) {
    bfs(S, T);
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    addline(u, v), addline(v, u);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) dfs(i, 0);
  }
  for (int i = 1; i <= n; i++) {
    if (val[i] > 1) {
      solve(i); return 0;
    }
  }
  puts("NO");
  return 0;
}