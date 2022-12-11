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
const int mod = 1e9 + 7;
int a[N], b[N], n, m, k;
bool solve() {
  vector< pair<int, int> > v1, v2;
  rep(i, 1, n) {
    int z = 1;
    while(a[i] % k == 0) {
      a[i] /= k;
      z *= k;
    }
    v1.pb(mp(a[i], z));
  }
  rep(i, 1, m) {
    int z = 1;
    while(b[i] % k == 0) {
      b[i] /= k;
      z *= k;
    }
    v2.pb(mp(b[i], z));
  }
  int x = 0, y = 0;
  while(x < n || y < m) {
    if(x >= n || y >= m) return 0;
    if(v1[x].fs != v2[y].fs) return 0;
    if(v1[x].sc < v2[y].sc) {
      v2[y].sc -= v1[x].sc;
      x ++;
    } else {
      v1[x].sc -= v2[y].sc;
      y ++;
      if(!v1[x].sc) x ++;
    }
  }
  return 1;
}
int main() {
  int test;
  scanf("%d", &test);
  while(test --) {
    scanf("%d%d", &n, &k);
    rep(i, 1, n) scanf("%d", a + i);
    scanf("%d", &m);
    rep(i, 1, m) scanf("%d", b + i);
    puts(solve() ? "Yes" : "No");
  }
  return 0;
}