#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__);
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
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 Rand(seed);
uniform_int_distribution<ll> ran(0, 1ll << 62);
void ucin() { ios::sync_with_stdio(0); cin.tie(0); }
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }
inline ll sqr(ll x) { return x * x; }
inline ll cub(ll x) { return x * x * x; }

const int N = 4e5 + 10;
const int mod = 1e9 + 7;
int n;
ll a[N];
ll gcd(ll x, ll y) {
  return y == 0 ? x : gcd(y, x % y);
}
int main() {
  int t; scanf("%d", &t);
  while(t --) {
    ll k;
    scanf("%d%lld", &n, &k);
    rep(i, 1, n) scanf("%lld", a + i);
    sort(a + 1, a + n + 1);
    bool ok = 0;
    ll d = 0;
    rep(i, 2, n) {
      if((k - a[i]) % (a[i] - a[i - 1]) == 0) {
        ok = 1; break ;
      }
      d = gcd(d, a[i] - a[i - 1]);
    }
    rep(i, 1, n) if(d && (k - a[i]) % d == 0) ok = 1;
    puts(ok ? "YES" : "NO");
  }  
  return 0;
}