#include <bits/stdc++.h>
#define pb push_back
#define debug(...) fprintf(stderr, __VA_ARGS__);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int n, m, p[N], sz[N], cnt[N], f[N], d[N];
vector<int> G[N];
ll ans, g[N];
ll F(int n) { return n * (n - 1ll); }
void dfs(int u, int fa = 0) {
  p[u] = fa; sz[u] = cnt[u] = 1; d[u] = d[fa] + 1;
  for(int v : G[u]) if(v != fa) {
    dfs(v, u);
    sz[u] += sz[v];
    g[u] += F(sz[v]);
  }
  ans -= F(n - sz[u]) + g[u];
}
int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }
void solve(int u, int v) {
  u = find(u); v = find(v);
  if(u == v) return ;
  ll G = 0, s = 0;
  for(int x = u, y = v; x != y; ) {
    if(d[x] < d[y]) swap(x, y);
    G += g[x] - F(sz[x]);
    ans += (g[x] + F(n - sz[x])) * cnt[x];
    s += cnt[x]; x = find(p[x]);
  }
  while(u != v) {
    if(d[u] < d[v]) swap(u, v);
    u = f[u] = find(p[u]);
  }
  ans += cnt[u] * (g[u] + F(n - sz[u]));
  cnt[u] += s; g[u] += G;
  ans -= (g[u] + F(n - sz[u])) * cnt[u];
}
int main() {
  scanf("%d", &n);
  int u, v;
  rep(i, 1, n - 1) {
    scanf("%d%d", &u, &v);
    G[u].pb(v); G[v].pb(u);
  }
  rep(i, 1, n) f[i] = i;
  ans = n * (n - 1ll) * (n - 2ll);
  dfs(1);
  printf("%lld\n", ans);
  scanf("%d", &m);
  while(m --) {
    scanf("%d%d", &u, &v);
    solve(u, v);
    printf("%lld\n", ans);
  }
  return 0;
}