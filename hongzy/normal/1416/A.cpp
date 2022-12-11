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
int n, a[N];
int main() {
  int test; scanf("%d", &test);
  while(test --) {
    scanf("%d", &n);
    vector<int> pre(n + 1), maxd(n + 1), ans(n + 1);
    rep(i, 1, n) ans[i] = n + 1;
    rep(i, 1, n) {
      scanf("%d", a + i);
      chkmax(maxd[a[i]], i - pre[a[i]]);
      pre[a[i]] = i;
    }
    rep(i, 1, n) chkmax(maxd[i], n + 1 - pre[i]);
    rep(i, 1, n) if(maxd[i] <= n) chkmin(ans[maxd[i]], i);
    rep(i, 2, n) chkmin(ans[i], ans[i - 1]);
    rep(i, 1, n) printf("%d ", ans[i] > n ? -1 : ans[i]);
    puts("");
  }
  return 0;
}