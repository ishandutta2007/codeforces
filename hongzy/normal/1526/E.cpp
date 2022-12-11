#include <bits/stdc++.h>
#define LOG(FMT...) fprintf(stderr, FMT);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;
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
int n, k, sa[N], rk[N], a[N];
int fac[N], fav[N];
int qpow(int a, int b) {
  int ans = 1;
  for(; b >= 1; b >>= 1, a = (ll)a * a % mod)
    if(b & 1) ans = (ll)ans * a % mod;
  return ans;
}
int C(int n, int m) {
  return n < m ? 0 : (ll)fac[n] * fav[m] % mod * fav[n - m] % mod;
}
void binom(int n) {
  fac[0] = 1;
  for(int i = 1; i <= n; i ++) fac[i] = (ll)fac[i - 1] * i % mod;
  fav[n] = qpow(fac[n], mod - 2);
  for(int i = n; i >= 1; i --) fav[i - 1] = (ll)fav[i] * i % mod;
}
int main() {
  scanf("%d%d", &n, &k);
  rep(i, 1, n) scanf("%d", sa + i), ++ sa[i], rk[sa[i]] = i;
  rk[n + 1] = 0;
  rep(i, 1, n) a[i] = rk[sa[i] + 1];
  binom(max(k, n));
  int c = 0;
  rep(i, 1, n - 1) if(a[i] > a[i + 1]) ++ c;
  // cerr << "c = " << c << endl;
  int ans = 0;
  rep(i, c + 1, min(k, n)) {
    ans = (ans + (ll)C(n - 1 - c, i - c - 1) * C(k, i)) % mod;
  }
  printf("%d\n", ans);
  return 0;
}