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

const int N = 512;
const int mod = 1e9 + 7;
int n, p[N], a[N][N];
int main() {
  int test = 1;
  // scanf("%d", &test);
  while(test --) {
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", p + i);
    rep(i, 1, n) rep(j, 1, i) a[i][j] = 0;
    rep(i, 1, n) {
      int x = i, y = i;
      rep(j, 1, p[i]) {
        while(a[x][y]) {
          if(y > 1 && !a[x][y - 1]) -- y;
          else {
            x ++;
          }
        }
        a[x][y] = p[i];
      }
    }
    rep(i, 1, n) rep(j, 1, i) printf("%d%c", a[i][j], " \n"[j == i]);
  }
  return 0;
}