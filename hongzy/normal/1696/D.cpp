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
int a[N], n, dp[N], Rmin[N], Rmax[N];
int main() {
  int test;
  scanf("%d", &test);
  while(test --) {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", a + i);
    static int stMin[N], stMax[N];
    int tmin = 0, tmax = 0;
    stMin[tmin = 1] = stMax[tmax = 1] = 1;

    rep(i, 2, n) {
      while(tmin && a[ stMin[tmin] ] > a[i]) {
        Rmin[ stMin[tmin --] ] = i;
      }
      stMin[++ tmin] = i;
    }
    while(tmin) Rmin[ stMin[tmin --] ] = n + 1;

    rep(i, 2, n) {
      while(tmax && a[ stMax[tmax] ] < a[i]) {
        Rmax[ stMax[tmax --] ] = i;
      }
      stMax[++ tmax] = i;
    }
    while(tmax) Rmax[ stMax[tmax --] ] = n + 1;

    int z = 0, x = 1;
    while(x != n) {
      int y1 = x;
      while(Rmax[y1] < Rmin[x]) y1 = Rmax[y1];

      int y2 = x;
      while(Rmin[y2] < Rmax[x]) y2 = Rmin[y2];

      z ++; x = max(y1, y2);
    }
    printf("%d\n", z);
  }
  return 0;
}