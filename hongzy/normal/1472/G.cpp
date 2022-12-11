#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__);
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

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 Rand(seed);
// mt19937_64 
uniform_int_distribution<ll> range(0, 1ll << 32);
inline void ucin() {
   ios::sync_with_stdio(0); cin.tie(0);
}
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }

inline ll sqr(ll x) { return x * x; }
inline ll cub(ll x) { return x * x * x; }

const int N = 4e5 + 10;
const int mod = 1e9 + 7;
int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
vector<int> G[N], T[N];
int n, m, g[N], d[N], ans[N], deg[N];
int main() {
   int t; scanf("%d", &t);
   while(t --) {
      scanf("%d%d", &n, &m);
      rep(i, 1, n) G[i].clear(), deg[i] = 0, d[i] = n;
      rep(i, 1, m) {
         int u, v;
         scanf("%d%d", &u, &v);
         G[u].pb(v);
      }
      queue<int> q; q.push(1); d[1] = 0;
      while(q.size()) {
         int u = q.front(); q.pop();
         for(int v : G[u]) if(d[v] == n) {
            d[v] = d[u] + 1; q.push(v);
         }
      }
      rep(u, 1, n) {
         g[u] = d[u];
         for(int v : G[u]) if(d[u] >= d[v]) {
            g[u] = min(g[u], d[v]);
         } else {
            deg[v] ++;
         }
      }
      rep(i, 1, n) if(!deg[i]) q.push(i);
      vector<int> s;
      while(q.size()) {
         int u = q.front(); s.pb(u); q.pop();
         for(int v : G[u]) if(d[u] < d[v] && !(-- deg[v])) q.push(v);
      }
      reverse(s.begin(), s.end());
      for(int u : s) {
         for(int v : G[u]) if(d[u] < d[v]) g[u] = min(g[u], g[v]);
         else g[u] = min(g[u], d[v]);
      }
      rep(i, 1, n) printf("%d%c", g[i], " \n"[i == n]);
   }
   return 0;
}