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

const int N = 1503;
int n, m, a[N][N], b[N][N], bad[N];
bool use[N], vis_row[N];
vector<int> ans;
bool judge() {
  static int ord[N];
  rep(i, 1, n) ord[i] = i;
  for(int k : ans) {
    stable_sort(ord + 1, ord + n + 1, [&](int x, int y) {
      return a[x][k] < a[y][k];
    });
  }
  rep(i, 1, n) rep(j, 1, m) if(a[ord[i]][j] != b[i][j]) return 0;
  return 1;
}
int main() {
  scanf("%d%d", &n, &m);
  rep(i, 1, n) rep(j, 1, m) scanf("%d", a[i] + j);
  rep(i, 1, n) rep(j, 1, m) scanf("%d", b[i] + j);
  rep(i, 1, n - 1) rep(j, 1, m) bad[j] += b[i][j] > b[i + 1][j];
  rep(c, 1, m) {
    bool ok = 0;
    rep(j, 1, m) if(!bad[j] && !use[j]) {
      ans.pb(j); use[j] = 1; ok = 1;
      rep(i, 1, n - 1) if(!vis_row[i] && b[i][j] < b[i + 1][j]) {
        vis_row[i] = 1;
        rep(j, 1, m) bad[j] -= b[i][j] > b[i + 1][j];
      }
      break ;
    }
    if(!ok) break ;
  }
  reverse(ans.begin(), ans.end());
  if(judge()) {
    printf("%lu\n", ans.size());
    for(int v : ans) {
      printf("%d ", v);
    }
    puts("");
  } else {
    puts("-1");
  }
  return 0;
}