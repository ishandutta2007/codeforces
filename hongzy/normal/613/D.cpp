#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
const int N = 1e5 + 20, INF = 1e9 + 10;
int n, q, st[N], top, dfn[N], seq[N], s, logn, f[N][21], d[N];
vector<int> G[N], T[N];
void dfs(int u, int p = 0) {
   dfn[u] = ++ *dfn; f[u][0] = p; d[u] = d[p] + 1;
   rep(i, 1, logn) {
      f[u][i] = f[f[u][i - 1]][i - 1];
      if(!f[u][i]) break ;
   }
   for(int &v : G[u]) if(v ^ p) dfs(v, u);
}
int LCA(int u, int v) {
   if(d[u] < d[v]) swap(u, v);
   int c = d[u] - d[v];
   per(i, logn, 0) if(c >> i & 1) u = f[u][i];
   if(u == v) return v;
   per(i, logn, 0) if(f[u][i] ^ f[v][i]) u = f[u][i], v = f[v][i];
   return f[u][0];
}
bool mark[N];
ll dp[N][2];
void dfs2(int u, int p = 0) {
   if(mark[u]) {
      dp[u][0] = 0; dp[u][1] = INF;
      for(int &v : T[u]) if(v ^ p) {
         dfs2(v, u);
         dp[u][0] += min(dp[v][1], dp[v][0] + (d[v] - d[u] == 1 ? INF : 1));
      }
   } else {
      for(int &v : T[u]) if(v ^ p) dfs2(v, u);
      ll fv0 = 0, st = 0, mn = 0;
      for(int &v : T[u]) if(v ^ p) {
         ll t = min(dp[v][1], dp[v][0] + (d[v] - d[u] == 1 ? INF : 1));
         fv0 += dp[v][0];
         st += t;
         mn = min(mn, - t + dp[v][0]);
      }
      dp[u][1] = min(fv0 + 1, st);
      dp[u][0] = min(fv0 + 1, mn + st);
   }
   if(dp[u][0] > INF) dp[u][0] = INF;
   if(dp[u][1] > INF) dp[u][1] = INF;
   // printf("dp[%d] = {%lld, %lld}\n", u, dp[u][0], dp[u][1]);
}
void clr(int u, int p = 0) {
   for(int v : T[u]) if(v ^ p) clr(v, u);
   T[u].clear(); mark[u] = 0;
}
void insert(int u) {
   if(top) {
      int x = LCA(st[top], u);
      if(x != st[top]) {
         while(dfn[st[top - 1]] > dfn[x]) {
            T[st[top - 1]].pb(st[top]);
            top --;
         }
         T[x].pb(st[top --]);
         if(x != st[top]) st[++ top] = x;
      }
   }
   st[++ top] = u;
}
int main() {
   scanf("%d", &n);
   for(logn = 1; (1 << logn) <= n; logn ++) ;
   logn --;
   int u, v;
   rep(i, 1, n - 1) {
      scanf("%d%d", &u, &v);
      G[u].pb(v); G[v].pb(u);
   }
   dfs(1);
   scanf("%d", &q);
   rep(Q, 1, q) {
      scanf("%d", &s);
      rep(i, 1, s) scanf("%d", seq + i), mark[seq[i]] = 1;
      sort(seq + 1, seq + s + 1, [&](int x, int y) { return dfn[x] < dfn[y]; });
      top = 0;
      if(seq[1] != 1) insert(1);
      rep(i, 1, s) insert(seq[i]);
      rep(i, 1, top - 1) T[st[i]].pb(st[i + 1]);
      // printf("Q %d!\n", Q);
      dfs2(1);
      printf("%d\n", dp[1][0] <= n ? (int)dp[1][0] : -1);
      clr(1);
   }
   return 0;
}