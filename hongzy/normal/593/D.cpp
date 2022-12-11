#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
const ll INF = 1e18 + 100;
int n, m, idx, d[N], ed[N], eu[N], sz[N], son[N], top[N], seg[N], pos[N], fa[N];
ll W[N], val[N << 2];
ll mul(ll x, ll y) {
   if(x == 0 || y == 0) return 0;
   if(x > INF / y) return INF;
   return x * y;
}
struct Edge { int v, id; };
vector<Edge> G[N];
void dfs1(int u, int fa = 0) {
   d[u] = d[fa] + 1; sz[u] = 1; son[u] = 0; ::fa[u] = fa;
   for(Edge e : G[u]) if(e.v != fa) {
      ed[e.v] = e.id; eu[e.id] = e.v;
      dfs1(e.v, u); sz[u] += sz[e.v];
      if(sz[e.v] > sz[son[u]]) son[u] = e.v;
   }
}
void dfs2(int u, int t) {
   top[u] = t; idx ++; seg[idx] = u; pos[u] = idx;
   if(!son[u]) return ;
   dfs2(son[u], t);
   for(Edge e : G[u]) if(!pos[e.v]) dfs2(e.v, e.v);
}
void build(int u, int l, int r) {
   if(l == r) { val[u] = W[ed[ seg[l] ]]; return ; }
   int mid = (l + r) >> 1;
   build(u << 1, l, mid);
   build(u << 1 | 1, mid + 1, r);
   val[u] = mul(val[u << 1], val[u << 1 | 1]);
}
void modify(int u, int l, int r, int p, ll v) {
   if(l == r) { val[u] = v; return ; }
   int mid = (l + r) >> 1;
   if(p <= mid) modify(u << 1, l, mid, p, v);
   else modify(u << 1 | 1, mid + 1, r, p, v);
   val[u] = mul(val[u << 1], val[u << 1 | 1]);
}
ll query(int u, int l, int r, int ql, int qr) {
   if(l == ql && r == qr) return val[u];
   int mid = (l + r) >> 1;
   if(qr <= mid) return query(u << 1, l, mid, ql, qr);
   if(ql > mid) return query(u << 1 | 1, mid + 1, r, ql, qr);
   return mul(query(u << 1, l, mid, ql, mid), query(u << 1 | 1, mid + 1, r, mid + 1, qr));
}
ll query(int u, int v) {
   ll ans = 1;
   while(top[u] != top[v]) {
      if(d[top[u]] < d[top[v]]) swap(u, v);
      ans = mul(ans, query(1, 1, n, pos[top[u]], pos[u]));
      u = fa[top[u]];
   }
   if(d[u] > d[v]) swap(u, v);
   if(pos[u] != pos[v]) {
      ans = mul(ans, query(1, 1, n, pos[u] + 1, pos[v]));
   }
   return ans;
}
int main() {
   scanf("%d%d", &n, &m);
   for(int i = 1; i < n; i ++) {
      int u, v; ll w;
      scanf("%d%d%lld", &u, &v, &w);
      G[u].push_back({v, i});
      G[v].push_back({u, i});
      W[i] = w;
   }
   dfs1(1); dfs2(1, 1); build(1, 1, n);
   for(int q = 0; q < m; q ++) {
      int op; scanf("%d", &op);
      if(op == 1) {
         int u, v; ll w;
         scanf("%d%d%lld", &u, &v, &w);
         // printf("[%lld][%lld]\n", w, query(u, v));
         printf("%lld\n", w / query(u, v));
      }
      if(op == 2) {
         int u; ll w;
         scanf("%d%lld", &u, &w);
         modify(1, 1, n, pos[eu[u]], w);
      }
   }
   return 0;
}