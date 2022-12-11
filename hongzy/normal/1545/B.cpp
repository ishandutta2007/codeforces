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
int qpow(int a, int b) {
  int ans = 1;
  for(; b >= 1; b >>= 1, a = (ll)a * a % mod)
    if(b & 1) ans = (ll)ans * a % mod;
  return ans;
}
int n, pre[N], suf[N];
char s[N];
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
int main() {
  binom(2e5);
  int test;
  scanf("%d", &test);
  rep(T, 1, test) {
    scanf("%d%s", &n, s + 1);
    int x = 0, y = 1;
    rep(i, 1, n) y += s[i] == '0';
    rep(i, 1, n) {
      int j = i;
      while(j < n && s[j + 1] == s[i]) j ++;
      if(s[i] == '1') {
        x += (j - i + 1) / 2;
      }
      i = j;
    }
    printf("%d\n", C(x + y - 1, y - 1));
  }  
  return 0;
}