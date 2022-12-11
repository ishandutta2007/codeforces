#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
 
#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
 
typedef double db;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int n, m, d[N], f[N];
vector<int> G[N];
pii a[N], A, B;
bool dfs(int u, int fa = 0) {
   d[u] = d[fa] + 1; f[u] = fa;
   for(int v : G[u]) if(v != fa) {
      if(!d[v]) {
         if(dfs(v, u)) return 1;
      } else if(d[v] < d[u]) {
         for(int x = u; x != v; x = f[x]) {
            if(!a[x].fs) {
               a[x] = mp(v, u);
            } else {
               A = a[x]; B = mp(v, u);
               return 1;
            }
         }
      }
   }
   return 0;
}
int LCA(int u, int v) {
   if(d[u] < d[v]) swap(u, v);
   while(d[u] != d[v]) u = f[u];
   while(u != v) u = f[u], v = f[v];
   return u;
}
void path(int u, int v, vector<int> &p) { //u
   bool tag = 0;
   if(d[u] < d[v]) tag = 1, swap(u, v);
   vector<int> t;
   for(int x = u; ; x = f[x]) {
      t.pb(x);
      if(x == v) break ;
   }
   if(tag) reverse(t.begin(), t.end());
   int f = 0;
   for(int v : t) if(f ++) p.pb(v);
}
int main() {
   scanf("%d%d", &n, &m);
   int u, v;
   rep(i, 1, m) {
      scanf("%d%d", &u, &v);
      G[u].pb(v); G[v].pb(u);
   }
   rep(i, 1, n) if(!d[i]) {
      if(dfs(i)) break ;
   }
   if(!A.fs) puts("NO");
   else {
      puts("YES");
      int a = A.fs, b = A.sc, c = B.fs, d = B.sc;
      if(::d[a] < ::d[c]) swap(a, c), swap(b, d);
      int L = LCA(b, d);
      vector<int> T[3];
      T[0].pb(a); path(a, L, T[0]);
      T[1].pb(a); T[1].pb(b); path(b, L, T[1]);
      T[2].pb(a); path(a, c, T[2]); T[2].pb(d); path(d, L, T[2]);
      rep(i, 0, 2) {
         printf("%d", (int) T[i].size());
         for(int v : T[i]) {
            printf(" %d", v);
         }
         putchar('\n');
      }
   }
   return 0;
}
/*
(u, v)
*/