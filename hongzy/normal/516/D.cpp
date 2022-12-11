#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
struct Edge {
   int v, w;
};
vector<Edge> G[N];
int rt1, rt2, n, q, L[N], R[N];
ll ans, d[N];
ll dfs(int u, int fa = 0) {
   L[u] = R[u] = u;
   ll f = 0, g = 0;
   for(auto e : G[u]) if(e.v ^ fa) {
      ll h = dfs(e.v, u) + e.w;
      if(h > f) {
         g = f; R[u] = L[u];
         f = h; L[u] = L[e.v];
      } else if(h > g) {
         g = h; R[u] = L[e.v];
      }
   }
   if(f + g > ans) { ans = f + g; rt1 = L[u]; rt2 = R[u]; }
   return f;
}
void dfs2(int u, ll dep = 0, int fa = 0) {
   d[u] = max(d[u], dep);
   for(auto e : G[u]) if(e.v ^ fa) {
      dfs2(e.v, dep + e.w, u);
   }
}
struct ufs {
   int f[N], sz[N];
   void init(int n) {
      for(int i = 1; i <= n; i ++) f[i] = i, sz[i] = 1;
   }
   int find(int u) {
      return u == f[u] ? u : f[u] = find(f[u]);
   }
   void unite(int u, int v) {
      u = find(u); v = find(v);
      if(u == v) return ;
      f[u] = v; sz[v] += sz[u];
   }
} ufs;
int main() {
   scanf("%d", &n);
   int u, v, w;
   for(int i = 1; i < n; i ++) {
      scanf("%d%d%d", &u, &v, &w);
      G[u].pb({v, w});
      G[v].pb({u, w});
   }
   dfs(1); dfs2(rt1); dfs2(rt2);
   static int p[N];
   for(int i = 1; i <= n; i ++) p[i] = i;
   sort(p + 1, p + n + 1, [&](int x, int y) {
      return d[x] < d[y];
   });
   scanf("%d", &q);
   ll t;
   static bool use[N];
   for(int i = 1; i <= q; i ++) {
      scanf("%lld", &t);
      for(int j = 1; j <= n; j ++) use[j] = 0;
      ufs.init(n);
      int pos = n, ans = 0;
      for(int j = n; j >= 1; j --) {
         int u = p[j];
         use[u] = 1;
         for(auto e : G[u]) {
            if(use[e.v]) {
               ufs.unite(e.v, u);
            }
         }
         for(; pos > j && d[p[pos]] - d[p[j]] > t; pos --) 
            ufs.sz[ufs.find(p[pos])] --;
         ans = max(ans, ufs.sz[ufs.find(u)]);
      }
      printf("%d\n", ans);
   }
   return 0;
}