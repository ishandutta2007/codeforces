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

const int N = 2e5 + 10;
const int mod = 998244353;
int n, a[N];
ll sum, s[N], pre[N];
ll work(int n, ll lim) { //P 
  ll ans = 0;
  rep(i, 1, n - 1) {
    //[C>=1][PC][P]
    //i + 2k <= n - 1
    int l = 0, r = (n - 1 - i) / 2, k = -1;
    while(l <= r) {
      int mid = (l + r) >> 1;
      if(s[i + 2 * mid] + s[i - 1] <= lim) l = (k = mid) + 1;
      else r = mid - 1;
    }
    ans += k + 1ll;
  }
  rep(i, 2, n - 1) {
    //P[C>=1][PC][P]
    //i + 2k <= n - 1
    int l = 0, r = (n - 1 - i) / 2, k = -1;
    while(l <= r) {
      int mid = (l + r) >> 1;
      if(s[i + 2 * mid] + s[i - 1] - a[1] <= lim) l = (k = mid) + 1;
      else r = mid - 1;
    }
    ans += k + 1ll;
  }
  return ans % mod;
}
int main() {
  int test;
  scanf("%d", &test);
  while(test --) {
    scanf("%d", &n);
    if(n == 1) { scanf("%d", a + 1); puts("1"); continue ; }
    rep(i, 1, n) scanf("%d", a + i);
    rep(i, 1, n) s[i] = (i >= 2 ? s[i - 2] : 0) + a[i];
    rep(i, 1, n) pre[i] = pre[i - 1] + a[i];
    sum = pre[n];
    sum = sum % 2 ? sum / 2 : sum / 2 - 1; //C <= sum
    ll ans = work(n, sum) + work(n - 1, sum - a[n]);
    //[C>=1][PC][P] (C), have P
    //P[C>=1][PC][P] (C), have P
    //[P][C]
    ll t = 0;
    per(i, n + 1, 1) {
      if(i <= n) t += a[i];
      if(t <= sum) ++ ans;
    }
    printf("%lld\n", ans % mod);
  }
  return 0;
}