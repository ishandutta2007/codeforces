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
const int mod = 1e9 + 7;
int n, k;
int qpow(int a, int b) {
  int ans = 1;
  for(; b >= 1; b >>= 1, a = (ll)a * a % mod)
    if(b & 1) ans = (ll)ans * a % mod;
  return ans;
}
int fac[N], fav[N]; 
int C(int n, int m) {
  return n < 0 || n < m ? 0 : (ll)fac[n] * fav[m] % mod * fav[n - m] % mod;
}
int iC(int n, int m) {
  return n < m ? 0 : (ll)fav[n] * fac[m] % mod * fac[n - m] % mod;
}
void binom(int n) {
  fac[0] = 1;
  rep(i, 1, n) fac[i] = (ll)fac[i - 1] * i % mod;
  fav[n] = qpow(fac[n], mod - 2);
  per(i, n, 1) fav[i - 1] = (ll)fav[i] * i % mod;
}
int main() {
  binom(2e5);
  int test;
  scanf("%d", &test);
  while(test --) {
    scanf("%d%d", &n, &k);
    int ans = 1;
    rep(i, 1, n - 1) {
      if(n - 1 - (i - 1) * k < 0) break ;
      ans = (ans + 1ll * C(n - 1 - (i - 1) * k + i + 1 - 1, i + 1 - 1) * iC(n, i)) % mod;
    }
    printf("%d\n", ans);
  }
  return 0;
}
//choose i[0,n-1], x_{1,...,i}, 1111 (i+1), x_1 >= 0, x_{2,..i} >= k,x_{i+1} >= 0, \sum = n-1