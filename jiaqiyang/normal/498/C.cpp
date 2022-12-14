#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

const int N = 100 + 10, E = 10 * N * N, INF = 0x3f3f3f3f;

int adj[N], to[E], next[E], cap[E], cnt;
int h[N], gap[N], s, t;

int dfs(int a, int df) {
  if (a == t) return df;
  int res = 0;
  for (int i = adj[a]; i; i = next[i]) {
    int b = to[i];
    if (cap[i] && h[a] == h[b] + 1) {
      int f = dfs(b, std::min(df - res, cap[i]));
      cap[i] -= f;
      cap[i ^ 1] += f;
      res += f;
    }
    if (res == df) return res;
  }
  if (--gap[h[a]] == 0) h[s] = t + 1;
  ++gap[++h[a]];
  return res;
}

inline void clear() {
  cnt = 2;
  memset(adj, 0, sizeof adj);
}

inline void link(int a, int b, int c) {
  to[cnt] = b, next[cnt] = adj[a], cap[cnt] = c, adj[a] = cnt++;
  to[cnt] = a, next[cnt] = adj[b], cap[cnt] = 0, adj[b] = cnt++;
}

int flow() {
  memset(h, 0, sizeof h);
  memset(gap, 0, sizeof gap);
  int res = 0;
  while (h[s] < t + 1) res += dfs(s, INF);
  return res;
}

int n, m, a[N], p[N], q[N];

int solve(int x) {
  clear();
  s = n + 1;
  t = s + 1;
  for (int i = 1; i <= n; ++i) {
    int tot = 0;
    for (int y = a[i]; y % x == 0; y /= x) ++tot;
    if (i & 1) link(s, i, tot); else link(i, t, tot);
  }
  for (int i = 1; i <= m; ++i) link(p[i], q[i], INF);
  return flow();
}

std::map<int, int> mem;

void factor(int x) {
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      ++mem[i];
      while (x % i == 0) x /= i;
    }
  }
  if (x > 1) ++mem[x];
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), factor(a[i]);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &p[i], &q[i]);
    if (q[i] & 1) std::swap(p[i], q[i]);
  }
  int ans = 0;
  for (std::map<int, int>::iterator it = mem.begin(); it != mem.end(); ++it) if (it->second > 1) ans += solve(it->first);
  printf("%d\n", ans);
  return 0;
}