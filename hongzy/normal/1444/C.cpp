#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

#define pb push_back

typedef pair<int, int> pii;
typedef long long ll;

const int N = 1e6 + 10;
const int mod = 998244353;

struct edge {
   int u, v, cu, cv;
   bool operator == (const edge &b) const {
      return cu == b.cu && cv == b.cv;
   }
   bool operator < (const edge &b) const {
      return cu < b.cu || (cu == b.cu && cv < b.cv);
   }
} e[N];
int n, m, k, c[N], B, bel[N], d[N], col[N];
map<pii, bool> Map;
bool ban[N];
vector<int> G[N], T[N];

bool fail;
void ins(int x, int y) {
   if(x > y) swap(x, y);
   // printf("%d <--> %d\n", x, y);
   Map[pii(x, y)] = 1;
}
void dfs(int u) {
   bel[u] = *bel;
   for(int v : G[u]) {
      if(c[v] == c[u]) {
         if(d[v] == -1) {
            d[v] = d[u] ^ 1;
            dfs(v);
         } else if(d[v] == d[u]) {
            fail = 1;
         }
      }
   }
}
bool cur[N];
int de[N];
void dfs2(int u) {
   for(int v : T[u]) {
      if(de[v] == -1) {
         de[v] = de[u] ^ 1;
         dfs2(v);
      } else if(de[v] == de[u]) {
         fail = 1;
      }
   }
}
int main() {
   scanf("%d%d%d", &n, &m, &k);
   rep(i, 1, n) scanf("%d", c + i);
   int u, v;
   rep(i, 1, m) {
      scanf("%d%d", &u, &v);
      G[v].pb(u); G[u].pb(v);
      e[i] = {u, v};
   }
   B = k;
   fill(d + 1, d + n + 1, -1);
   rep(i, 1, n) if(-1 == d[i]) {
      col[++ bel[0]] = c[i]; fail = 0; d[i] = 0; dfs(i);
      if(fail) { ban[c[i]] = 1; B --; }
   }
   rep(i, 1, m) {
      e[i].cu = col[bel[e[i].u]];
      e[i].cv = col[bel[e[i].v]];
      if(e[i].cu > e[i].cv) {
         swap(e[i].cu, e[i].cv);
         swap(e[i].u, e[i].v);
      }
   }
   sort(e + 1, e + m + 1);
   rep(i, 1, m) {
      int j = i;
      for(; j + 1 <= m && e[j + 1] == e[i]; j ++) ;
      if(!ban[e[i].cu] && !ban[e[i].cv] && e[i].cu != e[i].cv) {
         // printf("(%d,%d)\n", e[i].cu, e[i].cv);
         rep(k, i, j) {
            int bu = bel[e[k].u], bv = bel[e[k].v];
            // cur[bu] = cur[bv] = 1;
            de[bu] = de[bv] = -1;
            T[bu].clear(); T[bv].clear();
         }
         rep(k, i, j) {
            int bu = bel[e[k].u], bv = bel[e[k].v];
            if(d[e[k].u] == d[e[k].v]) {
               ++ bel[0]; de[bel[0]] = -1; //cur[bel[0]] = 1;
               T[bel[0]].pb(bu); T[bu].pb(bel[0]);
               T[bel[0]].pb(bv); T[bv].pb(bel[0]);
            } else {
               T[bu].pb(bv);
               T[bv].pb(bu);
            }
         }
         fail = 0;
         rep(k, i, j) {
            int bu = bel[e[k].u], bv = bel[e[k].v];
            if(-1 == de[bu]) de[bu] = 0, dfs2(bu);
            if(-1 == de[bv]) de[bv] = 0, dfs2(bv);
            if(fail) break ;
         }
         if(fail) ins(e[i].cu, e[i].cv);
         // rep(k, i, j) cur[bel[e[k].u]] = cur[bel[e[k].v]] = 0;
      }
      i = j;
   }
   ll ans = B * (B - 1ll) / 2 - Map.size();
   printf("%lld\n", ans);
   return 0;
}