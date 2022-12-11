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
int n, u, v, ans, a[N];
int main() {
  int test = 1;
  scanf("%d", &test);
  while(test --) {
    ans = 2e9 + 10;
    scanf("%d%d%d", &n, &u, &v);
    rep(i, 1, n) {
      scanf("%d", a + i);
      if(i > 1) {
        if(abs(a[i] - a[i - 1]) >= 2) ans = 0;
        else if(a[i] == a[i - 1]) ans = min(ans, min(2 * v, u + v));
        else {
          ans = min(ans, min(u, v));
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}