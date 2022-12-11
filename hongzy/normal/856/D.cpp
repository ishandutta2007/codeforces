#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 2e5 + 20;
int n, m, lg, pu[N], pv[N], pw[N], dp[N], s[N], dfn[N], d[N], f[N][20];
vector<int> pa[N], G[N];
int LCA(int u, int v) {
   if(d[u] < d[v]) swap(u, v);
   int c = d[u] - d[v];
   per(i, lg - 1, 0) if(c >> i & 1) u = f[u][i];
   if(u == v) return u;
   per(i, lg - 1, 0) if(f[u][i] ^ f[v][i]) {
      u = f[u][i]; v = f[v][i];
   }
   return f[v][0];
}
int bit[N];
void ins(int u, int v) {
   for(; u <= n; u += u & (-u)) bit[u] += v;
}
int qry(int u) {
   int ans = 0;
   for(; u >= 1; u &= u - 1) ans += bit[u];
   return ans;
}
void dfs(int u) {
   dfn[u] = ++ *dfn;
   for(int v : G[u]) {
      dfs(v); s[u] += dp[v];
   }
   dp[u] = s[u];
   for(int id : pa[u]) {
      dp[u] = max(dp[u], s[u] + qry(dfn[pu[id]]) + qry(dfn[pv[id]]) + pw[id]);
   }
   ins(dfn[u], s[u] - dp[u]);
   ins(*dfn + 1, - (s[u] - dp[u]));
}
int main() {
   scanf("%d%d", &n, &m);
   for(lg = 1; (1 << lg) <= n; lg ++) ;
   int u;
   rep(i, 2, n) {
      scanf("%d", &u);
      G[u].pb(i); f[i][0] = u; d[i] = d[u] + 1;
   }
   rep(i, 1, n) rep(j, 1, lg - 1)
      if(!(f[i][j] = f[f[i][j - 1]][j - 1])) break ;
   rep(i, 1, m) {
      scanf("%d%d%d", pu + i, pv + i, pw + i);
      pa[LCA(pu[i], pv[i])].pb(i);
   }
   dfs(1);
   printf("%d\n", dp[1]);
   return 0;
}