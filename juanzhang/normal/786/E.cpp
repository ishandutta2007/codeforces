#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef pair <int, int> pii;
const int maxn = 2e4 + 10, inf = 1 << 30;
int n, m;

namespace Dinic {
  const int maxn = 1e6 + 10;
  int S, T, h[maxn], cur[maxn], dis[maxn];

  struct edges {
    int nxt, to, w;
  } e[maxn << 2];

  void addline(int u, int v, int w) {
    static int cnt = 1;
    e[++cnt] = edges{h[u], v, w}, h[u] = cnt;
    e[++cnt] = edges{h[v], u, 0}, h[v] = cnt;
  }

  bool bfs() {
    static int Q[maxn];
    memcpy(cur, h, sizeof h);
    memset(dis, 0, sizeof dis);
    int l = 1, r = 1;
    Q[1] = S, dis[S] = 1;
    while (l <= r) {
      int u = Q[l++];
      for (int i = h[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        if (e[i].w && !dis[v]) {
          Q[++r] = v, dis[v] = dis[u] + 1;
          if (v == T) return 1;
        }
      }
    }
    return 0;
  }

  int dfs(int u, int f) {
    if (u == T || !f) {
      return f;
    }
    int res = 0, tmp;
    for (int& i = cur[u]; i && f; i = e[i].nxt) {
      int v = e[i].to;
      if (e[i].w && dis[v] == dis[u] + 1) {
        if (!(tmp = dfs(v, min(f, e[i].w)))) {
          dis[v] = 0; continue;
        }
        res += tmp, f -= tmp, e[i].w -= tmp, e[i ^ 1].w += tmp;
      }
    }
    return res;
  }

  int dinic() {
    int res = 0;
    while (bfs()) {
      res += dfs(S, inf);
    }
    return res;
  }
  
  bool vis[maxn];
  
  void DFS(int u) {
    vis[u] = 1;
    for (int i = h[u]; i; i = e[i].nxt) {
      int v = e[i].to;
      if (e[i].w && !vis[v]) DFS(v);
    }
  }
}

vector <int> e[maxn];
int dep[maxn], fa[15][maxn];

int emp[maxn];
map <pii, int> G;

void dfs(int u, int f) {
  fa[0][u] = f;
  dep[u] = dep[f] + 1;
  Dinic::addline(m + n + u, m + u, inf);
  for (int i = 1; i < 15; i++) {
    fa[i][u] = fa[i - 1][fa[i - 1][u]];
    if (fa[i][u]) {
      int t = m + n + i * n + u;
      Dinic::addline(t, m + i * n + u, inf);
      Dinic::addline(t, m + i * n + fa[i - 1][u], inf);
    }
  }
  for (int v : e[u]) {
    if (v != f) dfs(v, u), emp[v] = G[{u, v}];
  }
}

void query(int u, int v, int pos) {
  if (dep[u] < dep[v]) swap(u, v);
  per(i, 14, 0) {
    if (dep[u] - (1 << i) >= dep[v]) {
      Dinic::addline(pos, m + n + i * n + u, inf);
      u = fa[i][u];
    }
  }
  if (u == v) return;
  per(i, 14, 0) {
    if (fa[i][u] != fa[i][v]) {
      Dinic::addline(pos, m + n + i * n + u, inf);
      Dinic::addline(pos, m + n + i * n + v, inf);
      u = fa[i][u], v = fa[i][v];
    }
  }
  Dinic::addline(pos, m + n + u, inf);
  Dinic::addline(pos, m + n + v, inf);
}

int main() {
  scanf("%d %d", &n, &m);
  rep(i, 1, n - 1) {
    int u = read(), v = read();
    G[{u, v}] = G[{v, u}] = i;
    e[u].push_back(v), e[v].push_back(u);
  }
  Dinic::S = 1000001;
  Dinic::T = Dinic::S + 1;
  rep(i, 1, m) {
    Dinic::addline(Dinic::S, i, 1);
  }
  rep(i, 2, n) {
    Dinic::addline(m + i, Dinic::T, 1);
  }
  dfs(1, 0);
  rep(i, 1, m) {
    int u = read(), v = read();
    query(u, v, i);
  }
  vector <int> ans1, ans2;
  printf("%d\n", Dinic::dinic());
  Dinic::DFS(Dinic::S);
  rep(i, 1, m) {
    if (!Dinic::vis[i]) {
      ans1.push_back(i);
    }
  }
  rep(i, 2, n) {
    if (Dinic::vis[m + i]) {
      ans2.push_back(emp[i]);
    }
  }
  printf("%d ", (int) ans1.size());
  for (int x : ans1) printf("%d ", x);
  printf("\n%d ", (int) ans2.size());
  for (int x : ans2) printf("%d ", x);
  return 0;
}