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

const int N = 500 + 10;
const int mod = 1e9 + 7;
int n, m, a[N][N], b[N][N], cnt[N];
vector<pii> vec;
int main() {
  int test;
  scanf("%d", &test);
  while(test --) {
    scanf("%d%d", &n, &m);
    rep(i, 1, n) rep(j, 1, m) scanf("%d", a[i] + j), b[i][j] = 0;
    vec.clear();
    rep(i, 1, n) rep(j, 1, m) vec.pb(mp(a[i][j], i));
    sort(vec.begin(), vec.end());
    fill(cnt, cnt + m + 1, 0);
    for(pii p : vec) {
      int c = -1;
      rep(i, 1, m) if(!cnt[i]) c = i;
      if(~c) {
        cnt[c] ++;
        b[p.sc][c] = p.fs;
      } else {
        rep(j, 1, m) if(!b[p.sc][j]) {
          b[p.sc][j] = p.fs; break ;
        }
      }
    }
    rep(i, 1, n) rep(j, 1, m) printf("%d%c", b[i][j], " \n"[j == m]);
  }
  return 0;
}