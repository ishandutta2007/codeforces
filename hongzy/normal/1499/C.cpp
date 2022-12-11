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
const ll INF = 1e18;
int n;
ll c[N];
int main() {
  int t; cin >> t;
  while(t --) {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%lld", c + i);
    ll w[2] = {0};
    ll Min[2]; Min[0] = Min[1] = INF;
    ll s[2] = {0};
    ll ans = INF;
    rep(k, 1, n) {
      w[k & 1] ++;
      chkmin(Min[k & 1], c[k]);
      s[k & 1] += c[k];
      if(k >= 2) {
        ans = min(ans, s[0] + s[1] + (n - w[0]) * Min[0] + (n - w[1]) * Min[1]);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}