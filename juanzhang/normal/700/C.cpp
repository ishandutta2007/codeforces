#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef long long ll;
const int maxn = 2010, maxm = 6e4 + 10;
bool vis[maxm];
int n, m, S, T, h[maxn];

struct edges {
  int nxt, to, w;
} e[maxm];

void addline(int u, int v, int w) {
  static int cnt = 1;
  e[++cnt] = edges{h[u], v, w}, h[u] = cnt;
}

typedef pair <int, int> pii;

ll dis[maxn];
int pre[maxn], lst[maxn];

priority_queue <pii, vector <pii>, greater <pii> > Q;

void dijkstra() {
  memset(dis, 0x3f, sizeof dis);
  dis[S] = 0, Q.push(pii(0, S));
  while (!Q.empty()) {
    pii p = Q.top();
    int u = p.second;
    Q.pop();
    if (dis[u] < p.first) continue;
    for (int i = h[u]; i; i = e[i].nxt) {
      int v = e[i].to;
      if (!vis[i] && dis[v] > dis[u] + e[i].w) {
        pre[v] = i;
        dis[v] = dis[u] + e[i].w;
        Q.push(pii(dis[v], v));
      }
    }
  }
}

bool bfs() {
  static int Q[maxn];
  static bool flg[maxn];
  memset(flg, 0, sizeof flg);
  int l = 1, r = 1;
  Q[1] = S, flg[S] = 1;
  while (l <= r) {
    int u = Q[l++];
    for (int i = h[u]; i; i = e[i].nxt) {
      int v = e[i].to;
      if (!vis[i] && !flg[v]) {
        if (v == T) return 1;
        Q[++r] = v, flg[v] = 1;
      }
    }
  }
  return 0;
}

bool cut[maxm], cho[maxm];
int tot, now, bl[maxn], dfn[maxn], low[maxn];

vector <int> E[maxn], G[maxn];

void tarjan(int u, int f) {
  dfn[u] = low[u] = ++now;
  for (int i = h[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (vis[i] || v == f) continue;
    if (!dfn[v]) {
      tarjan(v, u);
      low[u] = min(low[u], low[v]);
      if (low[u] < low[v]) cut[i ^ 1] = cut[i] = 1;
    } else {
      low[u] = min(low[u], dfn[v]);
    }
  }
}

void dfs(int u) {
  bl[u] = tot;
  for (int i = h[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    if (!vis[i] && !cut[i] && !bl[v]) {
      dfs(v);
    }
  }
}

void BFS() {
  static bool flg[maxn];
  static int Q[maxn], pre[maxn], pos[maxn];
  memset(flg, 0, sizeof flg);
  int l = 1, r = 1;
  Q[1] = bl[S], flg[bl[S]] = 1;
  while (l <= r) {
    int u = Q[l++];
    int sz = E[u].size();
    for (int i = 0; i < sz; i++) {
      int v = E[u][i];
      if (!flg[v]) {
        Q[++r] = v, flg[v] = 1, pre[v] = u, pos[v] = G[u][i];
      }
    }
  }
  if (!flg[bl[T]]) return;
  for (int u = bl[T]; u != bl[S]; u = pre[u]) {
    cho[pos[u] ^ 1] = cho[pos[u]] = 1;
  }
}

void solve() {
  now = tot = 0;
  memset(bl, 0, sizeof bl);
  memset(dfn, 0, sizeof dfn);
  memset(low, 0, sizeof low);
  memset(cut, 0, sizeof cut);
  memset(cho, 0, sizeof cho);
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) tarjan(i, 0);
  }
  for (int i = 1; i <= n; i++) {
    if (!bl[i]) tot++, dfs(i);
  }
  for (int i = 1; i <= tot; i++) {
    E[i].clear(), G[i].clear();
  }
  for (int i = 2; i <= m * 2; i += 2) {
    if (cut[i]) {
      int u = bl[e[i ^ 1].to], v = bl[e[i].to];
      E[u].push_back(v), E[v].push_back(u);
      G[u].push_back(i), G[v].push_back(i);
    }
  }
  BFS();
}

int main() {
  scanf("%d %d %d %d", &n, &m, &S, &T);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    addline(u, v, w), addline(v, u, w);
  }
  dijkstra();
  if (dis[T] > (1ll << 60)) {
    return puts("0\n0"), 0;
  }
  memcpy(lst, pre, sizeof pre);
  int ans = 2e9 + 10, c1 = 0, c2 = 0;
  for (int u = T, i = lst[T]; u != S; u = e[i ^ 1].to, i = lst[u]) {
    vis[i ^ 1] = vis[i] = 1;
    dijkstra();
    if (dis[T] > (1ll << 60) && ans > e[i].w) {
      ans = e[i].w, c1 = i >> 1, c2 = 0;
    }
    solve();
    for (int j = 2; j <= m * 2; j += 2) {
      if (cho[j] && ans > e[i].w + e[j].w) {
        ans = e[i].w + e[j].w, c1 = i >> 1, c2 = j >> 1;
      }
    }
    vis[i ^ 1] = vis[i] = 0;
  }
  if (ans > 2e9) {
    return puts("-1"), 0;
  }
  printf("%d\n", ans);
  if (c2) {
    printf("2\n%d %d", c1, c2);
  } else {
    printf("1\n%d", c1);
  }
  return 0;
}