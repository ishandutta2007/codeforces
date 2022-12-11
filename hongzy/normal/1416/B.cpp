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
int test, n, a[N];
struct node {
  int i, j, x;
};
int main() {
  scanf("%d", &test);
  while(test --) {
    scanf("%d", &n);
    int s = 0;
    rep(i, 1, n) scanf("%d", a + i), s += a[i];
    if(s % n != 0) { puts("-1"); continue ; }
    s /= n;
    vector<node> vec;
    rep(i, 2, n) {
      if(a[i] % i == 0) {
        vec.pb({i, 1, a[i] / i});
      } else {
        vec.pb({1, i, i - (a[i] % i)});
        vec.pb({i, 1, a[i] / i + 1});
      }
    }
    rep(i, 2, n) {
      vec.pb({1, i, s});
    }
    printf("%lu\n", vec.size());
    for(auto u : vec) {
      printf("%d %d %d\n", u.i, u.j, u.x);
    }
  }
  return 0;
}