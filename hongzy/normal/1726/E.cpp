#include <bits/stdc++.h>
#define LOG(FMT...) fprintf(stderr, FMT);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
mt19937 mt(std::chrono::system_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> ran(0, 1ll << 62);
void ucin() { ios::sync_with_stdio(0); cin.tie(0); }
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }
inline ll sqr(ll x) { return x * x; }
inline ll cub(ll x) { return x * x * x; }

const int N = 4e5 + 10;
const int mod = 998244353;
int qpow(int a, int b) {
  int ans = 1;
  for(; b >= 1; b >>= 1, a = (ll)a * a % mod)
    if(b & 1) ans = (ll)ans * a % mod;
  return ans;
}
int fac[N], fav[N], pw[N]; 
int C(int n, int m) {
  return n < m ? 0 : (ll)fac[n] * fav[m] % mod * fav[n - m] % mod;
}
void binom(int n) {
  fac[0] = 1;
  for(int i = 1; i <= n; i ++) fac[i] = (ll)fac[i - 1] * i % mod;
  fav[n] = qpow(fac[n], mod - 2);
  for(int i = n; i >= 1; i --) fav[i - 1] = (ll)fav[i] * i % mod;
  pw[0] = 1;
  rep(i, 1, n) pw[i] = (pw[i-1] << 1) % mod;
}
int n, f[N], g[N];
int main() {
  f[0] = 1;
  f[1] = 1;
  rep(i, 2, int(300000))
    f[i] = (f[i-1] + (i-1ll) * f[i-2]) % mod;
  g[0] = 1;
  for(int i = 2; i <= 300000; i += 2)
    g[i] = g[i-2] * (i-1ll) % mod;
  binom(300000);
  int t; scanf("%d", &t);
  while(t--) {
    int ans = 0;
    scanf("%d", &n);
    rep(i, 0, n) { //'1'
      if((n - i) % 4) continue ;
      // printf("i = %d: %lld\n", i, (ll)C(i + (n - i) / 2, i) * f[i] % mod * f[(n - i) / 2]);
      ans = (ans + (ll)C(i + (n - i) / 2, i) * f[i] % mod * g[(n - i) / 2] % mod * pw[(n - i) / 4]) % mod;
    }
    printf("%d\n", ans);
  }
  return 0;
}