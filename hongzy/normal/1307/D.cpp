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

const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
int n, m, k, ds[N], dt[N], p[N];
bool mark[N];
vector<int> G[N];
void bfs(int s, int *d) {
   queue<int> q; q.push(s);
   fill(d + 1, d + n + 1, -1); d[s] = 0;
   while(q.size()) {
      int u = q.front(); q.pop();
      for(int v : G[u]) if(-1 == d[v]) {
         d[v] = d[u] + 1; q.push(v);
      }
   }
}
int main() {
   scanf("%d%d%d", &n, &m, &k);
   rep(i, 1, k) {
      int u; scanf("%d", &u); mark[u] = 1;
   }
   rep(i, 1, m) {
      int u, v; scanf("%d%d", &u, &v); G[u].pb(v); G[v].pb(u);
   }
   bfs(1, ds); bfs(n, dt);
   rep(i, 1, n) p[i] = i;
   sort(p + 1, p + n + 1, [&](int x, int y) { return ds[x] - dt[x] < ds[y] - dt[y]; });
   int ans = 0, cur = -1;
   rep(i, 1, n) {
      int u = p[i];
      // printf("%d!\n", u);
      if(mark[u]) {
         if(~ cur) ans = max(ans, min(dt[1], cur + dt[u] + 1));
         cur = max(cur, ds[u]);
      }
   }
   printf("%d\n", ans);
   return 0;
}