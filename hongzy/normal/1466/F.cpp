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

const int N = 5e5 + 10;
const int mod = 1e9 + 7;
int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
int cnt[N];
struct num {
   vector<int> v;
   void in() {
      int k; scanf("%d", &k); v.clear();
      while(k --) {
         int x; scanf("%d", &x); v.pb(x);
      }
      sort(v.begin(), v.end());
   }
} a[N], b[N];
int t, n, m, f[N], ok[N];
vector<int> pos;
int find(int u) { return u == f[u] ? u : f[u] = find(f[u]); }
bool unite(int u, int v) {
   u = find(u); v = find(v);
   if(u == v) return 0;
   return f[v] = u, ok[u] |= ok[v], 1;
}
int pre = -1;
bool ins(num x) {
   if(x.v.size() == 1) {
      int u = find(x.v[0]);
      if(ok[u]) return 0;
      ok[u] = 1;
      if(pre == -1) pre = u;
      else unite(pre, u);
      return 1;
   } else {
      if(ok[find(x.v[0])] && ok[find(x.v[1])]) return 0;
      return unite(x.v[0], x.v[1]);
   }
}
int main() {
   int n, m;
   scanf("%d%d", &n, &m);
   rep(i, 1, m) f[i] = i;
   int sz = 0;
   rep(i, 1, n) {
      a[i].in();
      if(ins(a[i])) {
         sz ++;
         pos.pb(i);
      }
   }
   printf("%d %d\n", qpow(2, sz), (int)pos.size());
   for(int v : pos) printf("%d ", v);
   puts("");
   return 0;
}