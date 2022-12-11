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

const int N = 2e6 + 10;
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

int main() {
  ucin();
  int t;
  cin >> t;
  while(t --) {
    static int a[104];
    int n, k;
    ll ans = 0;
    cin >> n >> k;
    rep(i, 1, n) cin >> a[i];
    ll s = a[1];
    rep(i, 2, n) {
      ans = max(ans, (ll)ceil(a[i] * 100.0 / k) - s);
      s += a[i];
    }
    cout << ans << endl;
  }
  return 0;
}