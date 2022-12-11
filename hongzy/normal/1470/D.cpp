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

const int N = 3e5 + 10;
const int mod = 1e9 + 7;
int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
int n, m, d[N], col[N];
vector<int> G[N];
bool vis[N];
void dfs(int u) {
   vis[u] = 1; col[u] = 1;
   for(int v : G[u]) if(col[v]) col[u] = 0;
   for(int v : G[u]) if(!vis[v]) dfs(v);
}
int main() {
   int t; scanf("%d", &t);
   while(t --) {
      scanf("%d%d", &n, &m);
      rep(i, 1, n) G[i].clear(), vis[i] = col[i] = 0;
      rep(i, 1, m) {
         int u, v;
         scanf("%d%d", &u, &v);
         G[v].pb(u); G[u].pb(v);
      }
      dfs(1); bool mark = 0;
      rep(i, 1, n) if(!vis[i]) {
         puts("NO"); mark = 1; break ;
      }
      if(!mark) {
         puts("YES"); int c = 0;
         rep(i, 1, n) if(col[i]) c ++;
         printf("%d\n", c);
         rep(i, 1, n) if(col[i]) printf("%d ", i);
         puts("");
      }
   }
   return 0;
}