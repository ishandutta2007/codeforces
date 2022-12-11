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
const ll INF = 1e18;
int n, m, k, wr[N][N], wd[N][N];
ll dis[12][N][N];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  rep(i, 1, n) rep(j, 1, m - 1) scanf("%d", wr[i] + j);
  rep(i, 1, n - 1) rep(j, 1, m) scanf("%d", wd[i] + j);
  if(k & 1) {
    rep(i, 1, n) rep(j, 1, m) {
      printf("%d%c", -1, " \n"[j == m]);
    }
    return 0;
  }
  k >>= 1;
  rep(t, 1, k) {
    rep(i, 1, n) rep(j, 1, m) {
      dis[t][i][j] = INF;
      if(i < n) chkmin(dis[t][i][j], dis[t - 1][i + 1][j] + wd[i][j]);
      if(i > 1) chkmin(dis[t][i][j], dis[t - 1][i - 1][j] + wd[i - 1][j]);
      if(j < m) chkmin(dis[t][i][j], dis[t - 1][i][j + 1] + wr[i][j]);
      if(j > 1) chkmin(dis[t][i][j], dis[t - 1][i][j - 1] + wr[i][j - 1]);
    }
  }
  rep(i, 1, n) rep(j, 1, m) {
    printf("%lld%c", dis[k][i][j] * 2, " \n"[j == m]);
  }
  return 0;
}