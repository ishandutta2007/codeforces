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

const int N = 4e5 + 10;
const int mod = 1e9 + 7;

int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
int n, b[N], seq[N], deg[N], l;
ll ans, a[N];
vector<int> s;
queue<int> q;
int main() {
   scanf("%d", &n);
   rep(i, 1, n) scanf("%lld", a + i);
   rep(i, 1, n) {
      scanf("%d", b + i);
      if(~ b[i]) deg[b[i]] ++;
   }
   rep(i, 1, n) if(!deg[i]) {
      q.push(i);
   }
   while(q.size()) {
      int u = q.front(); q.pop(); seq[++ l] = u;
      if(~ b[u] && ! -- deg[b[u]]) {
         q.push(b[u]);
      }
   }
   rep(i, 1, n) {
      int u = seq[i];
      if(a[u] >= 0) {
         s.pb(u); ans += a[u];
         if(~ b[u]) a[b[u]] += a[u];
      }
   }
   per(i, n, 1) {
      int u = seq[i];
      if(a[u] < 0) {
         ans += a[u];
         s.pb(u);
      }
   }
   printf("%lld\n", ans);
   for(int v : s) printf("%d ", v);
   return 0;
}