#include <stdio.h>
#include <cstring>
#include <vector>

typedef long long i64;

const int N = 100000 + 10, MOD = 1000000007;

int n, fa[N], dep[N], size[N], son[N], top[N], map[N], dist[N];

int adj[N], to[2 * N], next[2 * N], tag[2 * N];

void link(int a, int b, int c) {
  static int cnt = 2;
  to[cnt] = b;
  next[cnt] = adj[a];
  tag[cnt] = c;
  adj[a] = cnt++;
}

int f[N];
int down[N][3], up[N][3];

inline int sqr(int x) { return (i64)x * x % MOD; }

void bfs() {
  static int q[N];
  q[1] = dep[1] = 1;
  fa[1] = 0;
  for (int f = 1, r = 1; f <= r; ++f) {
    int a = q[f];
    for (int i = adj[a]; i; i = next[i]) {
      int b = to[i], t = tag[i];
      if (b != fa[a]) fa[b] = a, dep[b] = dep[a] + 1, dist[b] = (dist[a] + t) % MOD, q[++r] = b;
    }
  }
  for (int i = 1; i <= n; ++i) size[i] = 1;
  for (int i = n; i > 1; --i) size[fa[q[i]]] += size[q[i]];
  for (int i = 2; i <= n; ++i) if (size[i] > size[son[fa[i]]]) son[fa[i]] = i;
  for (int i = 1, tot = 0; i <= n; ++i) {
    int a = q[i];
    if (map[a]) continue;
    for (int b = a; b; b = son[b]) map[b] = ++tot, top[b] = a;
  }
  for (int i = n; i > 0; --i) {
    int a = q[i];
    down[a][0] = 1;
    down[a][1] = down[a][2] = 0;
    for (int j = adj[a]; j; j = next[j]) {
      int b = to[j], t = tag[j];
      if (b == fa[a]) continue;
      //sum of (x + t)^2
      //x^2 + 2xt + t^2
      down[a][2] = (down[a][2] + (i64)sqr(t) * down[b][0] + 2LL * t * down[b][1] + down[b][2]) % MOD;
      down[a][1] = (down[a][1] + down[b][1] + (i64)down[b][0] * t) % MOD;
      down[a][0] += down[b][0];
    }
  }
  for (int i = 1; i <= n; ++i) {
    int a = q[i];
    f[a] = (up[a][2] + down[a][2]) % MOD;
    int sum[3];
    memcpy(sum, up[a], sizeof sum);
    for (int j = adj[a]; j; j = next[j]) {
      int b = to[j], t = tag[j];
      if (b == fa[a]) continue;
      sum[2] = (sum[2] + (i64)sqr(t) * down[b][0] + 2LL * t * down[b][1] + down[b][2]) % MOD;
      sum[1] = (sum[1] + down[b][1] + (i64)down[b][0] * t) % MOD;
      sum[0] += down[b][0];
    }
    ++sum[0];
    for (int j = adj[a]; j; j = next[j]) {
      int b = to[j], t = tag[j];
      if (b == fa[a]) continue;
      int cur[3];
      cur[2] = (sum[2] - ((i64)sqr(t) * down[b][0] + 2LL * t * down[b][1] + down[b][2])) % MOD;
      cur[1] = (sum[1] - (down[b][1] + (i64)down[b][0] * t)) % MOD;
      cur[0] = sum[0] - down[b][0];
      up[b][2] = ((i64)sqr(t) * cur[0] + 2LL * t * cur[1] + cur[2]) % MOD;
      up[b][1] = (cur[1] + (i64)cur[0] * t) % MOD;
      up[b][0] = cur[0];
    }
  }
}

int lca(int a, int b) {
  while (top[a] != top[b]) {
    if (dep[top[a]] < dep[top[b]]) std::swap(a, b);
    a = fa[top[a]];
  }
  return dep[a] < dep[b] ? a : b;
}

int solve(int u, int v) {
  int t = lca(u, v);
  if (t == v) {
    int temp = (dist[u] - dist[t]) % MOD;
    int res = (((i64)sqr(temp) * up[v][0] + 2LL * temp * up[v][1] + up[v][2]) % MOD + MOD) % MOD;
    res = ((f[u] - res) % MOD + MOD) % MOD;
    return res;
  } else {
    int temp = (dist[u] + dist[v] - 2LL * dist[t]) % MOD;
    int res = ((i64)sqr(temp) * down[v][0] + 2LL * temp * down[v][1] + down[v][2]) % MOD;
    return (res + MOD) % MOD;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = n - 1; i--;) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    link(a, b, c);
    link(b, a, c);
  }
  bfs();
  int q;
  for (scanf("%d", &q); q--;) {
    int u, v;
    scanf("%d%d", &u, &v);
    int a = solve(u, v), b = ((f[u] - a) % MOD + MOD) % MOD;
    printf("%d\n", (a - b + MOD) % MOD);
  }
  return 0;
}