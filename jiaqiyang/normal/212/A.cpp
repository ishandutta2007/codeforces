#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 200 + 10, V = 2 * N, E = V * V, INF = 0x3f3f3f3f;

int arc[V], adj[V], to[E], next[E], cap[E], cnt, s, t, ss, tt;

inline void link(int a, int b, int c) {
  to[cnt] = b, next[cnt] = adj[a], cap[cnt] = c, adj[a] = cnt++;
  to[cnt] = a, next[cnt] = adj[b], cap[cnt] = 0, adj[b] = cnt++;
}

int h[V], gap[V];

int dfs(int a, int df) {
  if (a == tt) return df;
  int res = 0;
  for (int &i = arc[a]; i; i = next[i]) {
    int b = to[i];
    if (cap[i] && h[a] == h[b] + 1) {
      int f = dfs(b, std::min(df - res, cap[i]));
      cap[i] -= f;
      cap[i ^ 1] += f;
      res += f;
    }
    if (res == df) return res;
  }
  if (--gap[h[a]] == 0) h[s] = tt + 1;
  ++gap[++h[a]];
  arc[a] = adj[a];
  return res;
}

int n, m, k, tot;
int id[N][N], deg[2][N];

int ans[N * N];

void solve(int x) {
  cnt = 2;
  memset(adj, 0, sizeof adj);
  static int tag[N][N];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (id[i][j] && !ans[id[i][j]]) tag[i][j] = cnt, link(i, j + n, 1);
  s = n + m + 1;
  t = s + 1;
  ss = t + 1;
  tt = ss + 1;
  for (int i = 1; i <= n; ++i) {
    link(ss, i, deg[0][i] / x);
    link(s, tt, deg[0][i] / x);
    if (deg[0][i] % x) link(s, i, 1);
  }
  for (int i = 1; i <= m; ++i) {
    link(ss, t, deg[1][i] / x);
    link(i + n, tt, deg[1][i] / x);
    if (deg[1][i] % x) link(i + n, t, 1);
  }
  link(t, s, INF);
  memset(h, 0, sizeof h);
  memset(gap, 0, sizeof gap);
  memcpy(arc, adj, sizeof arc);
  int cur = 0;
  while (h[s] <= tt) cur += dfs(ss, INF);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (id[i][j] && !ans[id[i][j]] && !cap[tag[i][j]]) --deg[0][i], --deg[1][j], ans[id[i][j]] = x;
}

int main() {
  scanf("%d%d%d%d", &n, &m, &k, &tot);
  for (int i = 1; i <= k; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    id[x][y] = i;
    ++deg[0][x], ++deg[1][y];
  }
  int sum = 0;
  for (int i = 1; i <= n; ++i) if (deg[0][i] % tot) ++sum;
  for (int i = 1; i <= m; ++i) if (deg[1][i] % tot) ++sum;
  printf("%d\n", sum);
  for (int i = tot; i > 0; --i) solve(i);
  for (int i = 1; i <= k; ++i) printf("%d ", ans[i]);
  return 0;
}