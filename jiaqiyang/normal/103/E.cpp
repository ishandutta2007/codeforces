#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long i64;

const int N = 5000 + 10, E = 100 * N, INF = 0x3f3f3f3f;
const i64 INFF = 0x3f3f3f3f3f3f3fLL;

class Flow {
  int adj[N], to[E], next[E], cnt;
  i64 cap[E];
  int h[N], gap[N], s, t;
  i64 dfs(int a, i64 df) {
    if (a == t) return df;
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
    if (--gap[h[a]] == 0) h[s] = t + 1;
    ++gap[++h[a]];
    return res;
  }
 public:
  inline void clear(int _s, int _t) {
    cnt = 2, s = _s, t = _t;
    memset(adj, 0, sizeof adj);
  }
  inline void link(int a, int b, i64 c) {
    to[cnt] = b, next[cnt] = adj[a], cap[cnt] = c, adj[a] = cnt++;
    to[cnt] = a, next[cnt] = adj[b], cap[cnt] = 0, adj[b] = cnt++;
  }
  i64 flow() {
    memset(h, 0, sizeof h);
    memset(gap, 0, sizeof gap);
    i64 res = 0;
    while (h[s] < t + 1) res += dfs(s, INFF);
    return res;
  }
} g;

int n;

int main() {
  scanf("%d", &n);
  int s = 2 * n + 1, t = s + 1;
  g.clear(s, t);
  for (int i = 1; i <= n; ++i) {
    int m;
    for (scanf("%d", &m); m--;) {
      int j;
      scanf("%d", &j);
      g.link(i, j + n, INFF);
    }
  }
  i64 sum = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    sum += INF - x;
    g.link(s, i, INF - x);
    g.link(i + n, t, INF);
  }
  printf("%lld\n", g.flow() - sum);
  return 0;
}