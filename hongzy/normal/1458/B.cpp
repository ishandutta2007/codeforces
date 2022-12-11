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
 
const int N = 105;
const int mod = 1e9 + 7;
int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
int n, a[N], b[N];
db f[2][N][10003], ans[N];
const db INF = 1e18;
int main() {
   scanf("%d", &n);
   int suma = 0, sumb = 0;
   rep(i, 1, n) {
      scanf("%d%d", a + i, b + i);
      suma += a[i]; sumb += b[i];
   }
   int cur = 0;
   rep(i, 0, n) rep(j, 0, suma) f[cur][i][j] = -INF;
   f[cur][0][0] = 0;
   rep(u, 1, n) {
      cur ^= 1;
      rep(i, 0, n) rep(j, 0, suma) f[cur][i][j] = -INF;
      rep(i, 0, n) rep(j, 0, suma) {
         chkmax(f[cur][i][j], f[cur ^ 1][i][j] + 0.5 * b[u]);
         if(j >= a[u] && i)
            chkmax(f[cur][i][j], f[cur ^ 1][i - 1][j - a[u]] + b[u]);
      }
   }
   rep(i, 1, n) {
      ans[i] = 0;
      rep(j, 0, suma) ans[i] = max(ans[i], min((db)j, f[cur][i][j]));
      printf("%.10f%c", ans[i], " \n"[i == n]);
   }
   return 0;
}