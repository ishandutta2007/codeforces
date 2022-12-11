#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;

const int N = 2e5 + 10;

int k, n, f[N], f2[N], g[N], d[N], q, dia, a[N];
vector<int> G[N];
bool vis[N];
void dfs(int u, int p = 0) {
  f[u] = 0;
  d[u] = p ? d[p] + 1 : 0;
  if(!q || d[u] > d[q]) q = u;
  for(int v : G[u]) if(v ^ p) {
    dfs(v, u);
    if(f[v] + 1 > f[u])
      f2[u] = f[u], f[u] = f[v] + 1;
    else
      f2[u] = max(f2[u], f[v] + 1);
  }
}
void dfs2(int u, int p = 0) {
  int mx = g[u];
  for(int v : G[u]) if(v ^ p) {
    g[v] = max(g[v], mx + 1);
    mx = max(mx, f[v] + 1);
  }
  reverse(G[u].begin(), G[u].end());
  mx = 0;
  for(int v : G[u]) if(v ^ p) {
    g[v] = max(g[v], mx + 1);
    mx = max(mx, f[v] + 1);
  }
  for(int v : G[u]) if(v ^ p) dfs2(v, u);
}
int fa[N], q0, b[N];
void dfs3(int u, int p = 0) {
  f[u] = 0; fa[u] = p;
  d[u] = p ? d[p] + 1 : 0;
  if(!q0 || d[u] > d[q0]) q0 = u;
  for(int v : G[u]) if(v ^ p) {
    dfs3(v, u);
    if(f[v] + 1 > f[u])
      f[u] = f[v] + 1;
  }
}
void dfs4(int u, int dep, int bel, int p = 0) {
  if(vis[u]) return ;
  d[u] = dep;
  b[u] = bel;
  for(int v : G[u]) if(v ^ p) {
    dfs4(v, dep + 1, bel, u);
  }
}
int main() {
  scanf("%d%d", &n, &k);
  int u, v;
  rep(i, 1, n - 1) {
    scanf("%d%d", &u, &v);
    G[u].pb(v); G[v].pb(u);
  }
  dfs(1); dfs2(1);
  if(k == 2) {
    puts("Yes");
    rep(i, 1, n)
      printf("%d%c", d[i] & 1 ? 1 : 2, " \n"[i == n]);
    return 0;
  }
  rep(u, 1, n) {
    int a[3] = {f[u], f2[u], g[u]};
    sort(a, a + 3);
    if(a[0] && a[1] + a[0] >= k - 1) {
      puts("No"), exit(0);
    }
  }
  dfs3(q);
  dia = d[q0];
  for(int u = q0; u; u = fa[u])
    vis[u] = 1, a[u] = d[u] % k;
  rep(i, 1, n) if(vis[i]) {
    for(int v : G[i]) {
      dfs4(v, 1, i, i);
    }
  }
  rep(i, 1, n) if(!vis[i]) {
    int rt = b[i];
    if(f[i] + d[i] + min(d[rt], dia - d[rt]) >= k - 1) {
      puts("No"), exit(0);
    }
    if(f[i] + d[i] + d[rt] >= k - 1) {
      a[i] = (d[rt] + d[i]) % k;
    } else {
      a[i] = ((d[rt] - d[i]) % k + k) % k;
    }
  }
  puts("Yes");
  rep(i, 1, n)
    printf("%d%c", a[i]+1, " \n"[i == n]);
  return 0;
}