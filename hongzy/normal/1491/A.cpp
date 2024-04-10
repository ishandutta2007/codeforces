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
int n, q, a[N], c[32];
int main() {
  scanf("%d%d", &n, &q);
  rep(i, 1, n) scanf("%d", a + i), c[a[i]] ++;
  rep(i, 1, q) {
    int t, x;
    scanf("%d%d", &t, &x);
    if(t == 1) {
      c[a[x]] --;
      c[1 - a[x]] ++;
      a[x] = 1 - a[x];
    }
    if(t == 2) {
      printf("%d\n", c[1] >= x ? 1 : 0);
    }
  }
  return 0;
}