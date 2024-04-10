#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long i64;

const int N = 50 + 10, E = 100000 + 10, INF = 1000000000;
const double eps = 1e-7;

int n, m, x;

int adj[N], to[E], next[E], cnt;
i64 cap[E];

inline void link(int a, int b, i64 c) {
  to[cnt] = b, next[cnt] = adj[a], cap[cnt] = c, adj[a] = cnt++;
  to[cnt] = a, next[cnt] = adj[b], cap[cnt] = 0, adj[b] = cnt++;
}

int h[N], gap[N + 1];

i64 dfs(int a, i64 df) {
  if (a == n) return df;
  i64 res = 0;
  for (int i = adj[a]; i; i = next[i]) {
    int b = to[i];
    if (cap[i] && h[a] == h[b] + 1) {
      i64 f = dfs(b, std::min(df - res, cap[i]));
      cap[i] -= f;
      cap[i ^ 1] += f;
      res += f;
    }
    if (res == df) return res;
  }
  if (--gap[h[a]] == 0) h[1] = n + 1;
  ++gap[++h[a]];
  return res;
}

int a[E], b[E], c[E];

inline bool check(double th) {
  memset(h, 0, sizeof h);
  memset(gap, 0, sizeof gap);
  memset(adj, 0, sizeof adj);
  cnt = 2;
  for (int i = 1; i <= m; ++i) link(a[i], b[i], (i64)(c[i] / th));
  i64 res = 0;
  while (h[1] < n + 1) if ((res += dfs(1, INF)) >= x) return true;
  return false;
}

int main() {
  scanf("%d%d%d", &n, &m, &x);
  for (int i = 1; i <= m; ++i) scanf("%d%d%d", &a[i], &b[i], &c[i]);
  double l = 0., r = 1e9;
  while (fabs(r - l) * x > eps) {
    double mid = (l + r) / 2.;
    if (check(mid)) l = mid; else r = mid;
  }
  printf("%.12f\n", l * x);
  return 0;
}