#include <bits/stdc++.h>
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

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 Rand(seed);
uniform_int_distribution<ll> range(0, 1ll << 32);
inline void ucin() {
   ios::sync_with_stdio(0); cin.tie(0);
}

template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }

const int N = 1e5 + 10;
const int mod = 1e9 + 7;

int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
int n, m;
ll a[N], sz[N], h[N], ha[N], happy[N];
vector<int> G[N];
bool tag;
void dfs(int u, int fa = 0) {
   sz[u] = a[u];
   for(int v : G[u]) if(v != fa) {
      dfs(v, u); sz[u] += sz[v];
   }
}
void dfs2(int u, int fa = 0) {
   if((sz[u] + h[u]) & 1) {
      // cerr << "1" << endl;
      tag = 0; return ;
   } 
   ha[u] = (sz[u] + h[u]) / 2;
   if(ha[u] < 0 || ha[u] > sz[u]) {
      // cerr << "2" << endl;
      tag = 0; return ;
   }
   ll sg = 0; happy[u] = a[u];
   for(int v : G[u]) if(v != fa) {
      dfs2(v, u);
      if(!tag) return ;
      sg += ha[v]; happy[u] += happy[v];
   }
   if(sg <= ha[u]) {
      if(happy[u] < ha[u] - sg) {
         // cerr << 3 << endl;
         tag = 0; return ;
      }
      happy[u] -= ha[u] - sg;
   } else {
      // cout << 3<< endl;
      tag = 0; return ;
   }
}
int main() {
   int t; scanf("%d", &t);
   while(t --) {
      scanf("%d%d", &n, &m);
      rep(i, 1, n) scanf("%lld", a + i);
      rep(i, 1, n) G[i].clear();
      rep(i, 1, n) scanf("%lld", h + i);
      tag = 1;
      int u, v;
      rep(i, 1, n - 1) {
         scanf("%d%d", &u, &v);
         G[u].pb(v); G[v].pb(u);
      }
      dfs(1);
      if(!tag) { puts("NO"); continue ; }
      dfs2(1);
      if(!tag) { puts("NO"); continue ; }
      puts("YES");
   }
   return 0;
}