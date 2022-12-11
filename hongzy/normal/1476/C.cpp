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

const int N = 4e5 + 10;
const int mod = 1e9 + 7;
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 Rand(seed);
uniform_int_distribution<long long> ran(0, 1ll << 62);
void ucin() {
  ios::sync_with_stdio(0); cin.tie(0);
}
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }

inline ll sqr(ll x) { return x * x; }
inline ll cub(ll x) { return x * x * x; }
int test, n, c[N], a[N], b[N];
int main() {
  scanf("%d", &test);
  while(test --) {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", c + i);
    rep(i, 1, n) scanf("%d", a + i);
    rep(i, 1, n) scanf("%d", b + i);
    rep(i, 1, n) if(a[i] > b[i]) swap(a[i], b[i]);
    ll ans = 0, cur = 0;
    rep(i, 1, n) {
      if(i > 1) {
        cur += 2;
        ans = max(ans, cur + c[i] - 1);
      }
      if(i == n) break ;
      if(a[i + 1] == b[i + 1]) {
        cur = 0;
      } else {
        if(i == 1) cur = b[i + 1] - a[i + 1];
        else cur = max(cur + a[i + 1] - 1 + c[i] - b[i + 1], (ll)b[i + 1] - a[i + 1]);
      }
      // cerr << "cur = " << cur << endl;
    }
    printf("%lld\n", ans);
  }
  return 0;
}