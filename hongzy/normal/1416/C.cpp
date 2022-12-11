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

const int N = 3e5 + 10;
const int mod = 1e9 + 7;
int n, a[N], ch[N * 35][2], sz[N * 35], id = 1;
ll z[32][2];
void ins(int x) {
  int u = 1; sz[1] ++;
  per(i, 30, 0) {
    int d = x >> i & 1;
    int &v = ch[u][d];
    if(!v) v = ++ id;
    if(d) {
      z[i][1] += sz[ch[u][0]];
    } else {
      z[i][0] += sz[ch[u][1]];
    }
    u = v; sz[u] ++;
  }
}
int main() {
  scanf("%d", &n);
  rep(i, 1, n) scanf("%d", a + i);
  rep(i, 1, n) {
    ins(a[i]);
  }
  ll ans = 0, x = 0;
  rep(i, 0, 30) {
    if(z[i][0] <= z[i][1]) {
      ans += z[i][0];
    } else {
      ans += z[i][1];
      x ^= 1ll << i;
    }
  }
  printf("%lld %lld\n", ans, x);
  return 0;
}