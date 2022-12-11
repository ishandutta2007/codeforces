#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 1e5 + 10, mod = 1e9 + 7;
int n, q;
int d[N], sz[N], son[N], fa[N];
int idx, dfn[N], top[N];
vector<int> G[N]; 
void dfs(int u, int p = 0) {
   sz[u] = 1; fa[u] = p; d[u] = d[p] + 1;
   for(int v : G[u]) if(v ^ p) {
      dfs(v, u); sz[u] += sz[v];
      if(sz[v] > sz[son[u]]) son[u] = v;
   }
}
void dfs2(int u, int t) {
   top[u] = t; dfn[u] = ++ idx;
   if(!son[u]) return ;
   dfs2(son[u], t);
   for(int v : G[u]) {
      if(v != fa[u] && v != son[u]) {
         dfs2(v, v);
      }
   }
}
int sum[N << 2], f[N];
void modify(int u, int l, int r, int p, int v) {
   sum[u] += v;
   if(l == r) return ;
   int mid = (l + r) >> 1;
   if(p <= mid) modify(u << 1, l, mid, p, v);
   else modify(u << 1 | 1, mid + 1, r, p, v);
}
int query(int u, int l, int r, int ql, int qr) {
   if(l == ql && r == qr) return sum[u];
   int mid = (l + r) >> 1;
   if(qr <= mid) return query(u << 1, l, mid, ql, qr);
   if(ql > mid) return query(u << 1 | 1, mid + 1, r, ql, qr);
   return query(u << 1, l, mid, ql, mid) + query(u << 1 | 1, mid + 1, r, mid + 1, qr);
}
int tree(int u, int v) {
   int ans = 0;
   for(; top[u] ^ top[v]; u = fa[top[u]]) {
      if(d[top[u]] < d[top[v]]) swap(u, v);
      ans += query(1, 1, n, dfn[top[u]], dfn[u]);
   }
   if(dfn[u] > dfn[v]) swap(u, v);
   ans += query(1, 1, n, dfn[u], dfn[v]);
   return ans;
}
int s, m, rt, seq[N], dp[N][305];
int main() {
   scanf("%d%d", &n, &q);
   int u, v;
   rep(i, 1, n - 1) {
      scanf("%d%d", &u, &v);
      G[u].pb(v); G[v].pb(u);
   }
   dfs(1); dfs2(1, 1);
   rep(Q, 1, q) {
      scanf("%d%d%d", &s, &m, &rt);
      rep(i, 1, s) scanf("%d", seq + i);
      rep(i, 1, s) modify(1, 1, n, dfn[seq[i]], 1);
      rep(i, 1, s) f[seq[i]] = tree(rt, seq[i]) - 1;
      sort(seq + 1, seq + s + 1, [&](int x, int y) { return f[x] < f[y]; });
      rep(i, 1, s) modify(1, 1, n, dfn[seq[i]], -1);
      dp[0][0] = 1;
      rep(i, 1, s) {
         rep(j, 1, m) {
            dp[i][j] = (1ll * (j - f[seq[i]]) * dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
         }
      }
      int ans = 0;
      rep(i, 1, m) {
         ans += dp[s][i];
         if(ans >= mod) ans -= mod;
      }
      printf("%d\n", ans);
   }
   return 0;
}