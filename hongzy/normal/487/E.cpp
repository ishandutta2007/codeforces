#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <chrono>
#include <random>
#include <queue>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back

typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned uint;
typedef unsigned long long ull;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 2e5 + 10;

struct Tree {

int n, n0, w[N], d[N], sz[N], son[N], fa[N];
int idx, dfn[N], top[N], pos[N];
vector<int> G[N]; 
void link(int u, int v) { G[u].pb(v); G[v].pb(u); }
void dfs(int u, int p = 0) {
   sz[u] = 1; fa[u] = p; d[u] = d[p] + 1;
   for(int v : G[u]) if(v ^ p) {
      dfs(v, u); sz[u] += sz[v];
      if(sz[v] > sz[son[u]]) son[u] = v;
   }
}
void dfs2(int u, int t) {
   top[u] = t; dfn[u] = ++ idx; pos[idx] = u;
   if(!son[u]) return ;
   dfs2(son[u], t);
   for(int v : G[u]) {
      if(v != fa[u] && v != son[u]) {
         dfs2(v, v);
      }
   }
}
multiset<int> se[N];
void dfs3(int u, int p = 0) {
   for(int v : G[u]) if(v ^ p) {
      dfs3(v, u);
      if(u > n0) se[u].insert(w[v]);
   }
   if(u > n0) w[u] = *se[u].begin();
}
int val[N << 2];
void upd(int u) {
   val[u] = min(val[u << 1], val[u << 1 | 1]);
}
void build(int u, int l, int r) {
   if(l == r) { val[u] = w[pos[l]]; return ; }
   int mid = (l + r) >> 1;
   build(u << 1, l, mid);
   build(u << 1 | 1, mid + 1, r);
   upd(u);
}
void update(int u, int l, int r, int pos, int v) {
   if(l == r) { val[u] = v; return ; }
   int mid = (l + r) >> 1;
   if(pos <= mid) update(u << 1, l, mid, pos, v);
   else update(u << 1 | 1, mid + 1, r, pos, v);
   upd(u);
}
int query(int u, int l, int r, int ql, int qr) {
   if(l == ql && r == qr) {
      return val[u];
   }
   int mid = (l + r) >> 1;
   if(qr <= mid) return query(u << 1, l, mid, ql, qr);
   if(ql > mid) return query(u << 1 | 1, mid + 1, r, ql, qr);
   return min(query(u << 1, l, mid, ql, mid), query(u << 1 | 1, mid + 1, r, mid + 1, qr));
}
int query(int u, int v) {
   int ans = 1e9 + 10;
   while(top[u] ^ top[v]) {
      if(d[top[u]] < d[top[v]]) swap(u, v);
      ans = min(ans, query(1, 1, n, dfn[top[u]], dfn[u]));
      u = fa[top[u]];
   }
   if(dfn[u] > dfn[v]) swap(u, v);
   ans = min(ans, query(1, 1, n, dfn[u], dfn[v]));
   if(fa[u] && fa[u] <= n0) ans = min(ans, w[fa[u]]);
   return ans;
}

} tr;

int n, m, q, id, dfn[N], low[N], idx, st[N], top;
vector<int> G[N];
void tarjan(int u) {
   low[u] = dfn[u] = ++ idx; st[++ top] = u; //printf("!%d\n", u);
   for(int v : G[u]) {
      if(!dfn[v]) {
         tarjan(v); low[u] = min(low[u], low[v]);
         if(low[v] == dfn[u]) {
            id ++;
            while(st[top] != v) {
               tr.link(id, st[top --]);
            }
            tr.link(id, st[top --]);
            tr.link(id, u);
         }
      } else {
         low[u] = min(low[u], dfn[v]);
      }
   }
}
int main() {
   scanf("%d%d%d", &n, &m, &q);
   rep(i, 1, n) scanf("%d", tr.w + i);
   int u, v;
   rep(i, 1, m) {
      scanf("%d%d", &u, &v);
      G[u].pb(v); G[v].pb(u);
   }
   id = n; tarjan(1); tr.n = id; tr.n0 = n;
   tr.dfs(1); tr.dfs2(1, 1); tr.dfs3(1); tr.build(1, 1, id);
   char op[20];
   rep(i, 1, q) {
      scanf("%s%d%d", op, &u, &v);
      if(*op == 'C') {
         tr.update(1, 1, tr.n, tr.dfn[u], v);
         int f = tr.fa[u];
         if(f > n) {
            tr.se[f].erase(tr.se[f].lower_bound(tr.w[u]));
            tr.se[f].insert(v);
            tr.update(1, 1, id, tr.dfn[f], *tr.se[f].begin());
         }
         tr.w[u] = v;
      } else {
         printf("%d\n", tr.query(u, v));
      }
   }
   return 0;
}