#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 4e5 + 10;
int n, k, r, logn, f[N][20], d[N];
vector<int> G[N];
struct Ufs {
   int f[N];
   void init(int n) { rep(i, 1, n) f[i] = i; }
   int find(int u) { return u == f[u] ? u : f[u] = find(f[u]); }
   void unite(int u, int v) { f[find(u)] = find(v); }
} ufs;
void dfs(int u, int fa = 0) {
   f[u][0] = fa; d[u] = d[fa] + 1;
   rep(i, 1, logn - 1) {
      f[u][i] = f[f[u][i - 1]][i - 1];
      if(!f[u][i]) break ;
   }
   for(int v : G[u]) if(v != fa) dfs(v, u);
}
int lca(int u, int v) {
   if(d[u] < d[v]) swap(u, v);
   int c = d[u] - d[v];
   per(i, logn - 1, 0) if(c >> i & 1) u = f[u][i];
   if(u == v) return v;
   per(i, logn - 1, 0) if(f[u][i] ^ f[v][i])
      u = f[u][i], v = f[v][i];
   return f[v][0];
}
int jump(int u, int k) {
   for(; k >= 1; k &= k - 1) u = f[u][__builtin_ffs(k) - 1];
   return u;
}
int main() {
   scanf("%d%d%d", &n, &k, &r);
   for(logn = 1; (1 << logn) < 2 * n; logn ++);
   int x, y;
   rep(i, 1, n - 1) {
      scanf("%d%d", &x, &y);
      G[x].pb(n + i); G[n + i].pb(x);
      G[y].pb(n + i); G[n + i].pb(y);
   }
   dfs(1);
   ufs.init(2 * n - 1);
   struct node {
      int u, d;
      operator int() const { return u; }
   };
   vector<bool> vis(2 * n);
   queue<node> q;
   rep(i, 1, r) { scanf("%d", &x); q.push({x, 0}); vis[x] = 1; }
   while(q.size()) {
      node u = q.front(); q.pop();
      if(u.d == k) continue ;
      for(int v : G[u]) {
         ufs.unite(u, v);
         if(!vis[v]) {
            q.push({v, u.d + 1}); vis[v] = 1;
         }
      }
   }
   int test; scanf("%d", &test);
   while(test --) {
      scanf("%d%d", &x, &y);
      int z = lca(x, y), t = -2 * d[z] + d[x] + d[y];
      if(t <= 2 * k) {
         puts("YES");
      } else {
         int x0 = ufs.find(d[x] - d[z] >= k ? jump(x, k) : jump(y, t - k));
         int y0 = ufs.find(d[y] - d[z] >= k ? jump(y, k) : jump(x, t - k));
         puts(x0 == y0 ? "YES" : "NO");
      }
   }
   return 0;
}