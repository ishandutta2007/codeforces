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

const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int qpow(int a, int b) {
  int ans = 1;
  for(; b >= 1; b >>= 1, a = (ll)a * a % mod)
    if(b & 1) ans = (ll)ans * a % mod;
  return ans;
}
int fac[N], fav[N]; 
int C(int n, int m) {
  return n < m ? 0 : (ll)fac[n] * fav[m] % mod * fav[n - m] % mod;
}
void binom(int n) {
  fac[0] = 1;
  for(int i = 1; i <= n; i ++) fac[i] = (ll)fac[i - 1] * i % mod;
  fav[n] = qpow(fac[n], mod - 2);
  for(int i = n; i >= 1; i --) fav[i - 1] = (ll)fav[i] * i % mod;
}
int Lucas(int n, int m, int p) {
  if(n < m) return 0;
  if(n < p && m < p) return 1ll * fac[n] * fav[m] % p * fav[n - m] % p;
  return 1ll * Lucas(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;
}

int n, a[N];
int solve(int k, int s) {
  //x1+..+xk = s, x >= 0
  return C(s + k - 1, k - 1);
}
int main() {
  binom(5e5);
  scanf("%d", &n);
  n ++;
  rep(i, 1, n) scanf("%d", a + i);
  while(n && !a[n]) n --;
  if(n == 0) { puts("0"); return 0; }
  int ans = 0;
  rep(i, 1, n) {
    //x: k=i-1 step, y: x1+...+x_{k+1}<=a[i]-1 -> x1+...x_{k+2}=a[i]-1
    (ans += solve(i + 1, a[i] - 1)) %= mod;
  }
  printf("%d\n", ans);
  return 0;
}