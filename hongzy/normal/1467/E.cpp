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
int n, a[N], c[N], cnt[N], dl[N], dr[N], idx;
vector<int> pos[N], G[N];
template<class T>
struct BIT {
   int c[N];
   void add(int x, T y) {
      for(; x <= n; x += x & (-x))
         c[x] += y;
   }
   T qry(int x) {
      T ans = 0;
      for(; x >= 1; x &= x - 1)
         ans += c[x];
      return ans;
   }
};
BIT<int> bit;
int q(int c, int l, int r) {
   return upper_bound(pos[c].begin(), pos[c].end(), r) - lower_bound(pos[c].begin(), pos[c].end(), l);
}
void dfs(int u, int fa = 0) {
   dl[u] = ++ idx; pos[a[u]].pb(idx);
   for(int v : G[u]) if(v ^ fa) {
      dfs(v, u);
   }
   dr[u] = idx;
}
void dfs2(int u, int fa = 0) {
   for(int v : G[u]) if(v ^ fa) {
      dfs2(v, u);
   }
   int num = 0;
   for(int v : G[u]) if(v ^ fa) {
      int c = q(a[u], dl[v], dr[v]);
      if(c) {
         num ++;
         bit.add(dl[v], -1);
         bit.add(dr[v] + 1, 1);
      }
   }
   bit.add(1, num);
}
int main() {
   scanf("%d", &n);
   rep(i, 1, n) scanf("%d", a + i), c[i] = a[i];
   sort(c + 1, c + n + 1);
   rep(i, 1, n) a[i] = lower_bound(c + 1, c + n + 1, a[i]) - c, cnt[a[i]] ++;
   rep(i, 1, n - 1) {
      int u, v;
      scanf("%d%d", &u, &v);
      G[u].pb(v); G[v].pb(u);
   }
   dfs(1);
   rep(i, 1, n) {
      int y = cnt[a[i]] - q(a[i], dl[i], dr[i]);
      if(y) {
         bit.add(dl[i], 1); bit.add(dr[i] + 1, -1);
      }
   }
   dfs2(1);
   int ans = 0;
   rep(i, 1, n) if(!bit.qry(i)) ans ++;
   printf("%d\n", ans);
   return 0;
}