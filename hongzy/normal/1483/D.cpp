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

const int N = 610;
const ll INF = 1e17;
int n, m, q, ans;
ll D[N][N], g[N][N], Max[N];
bool res[N][N];
struct Q {
  int v, len;
};
vector<Q> vec[N];

int main() {
  scanf("%d%d", &n, &m);
  rep(i, 1, n) rep(j, 1, n) D[i][j] = g[i][j] = i == j ? 0 : INF;
  rep(i, 1, m) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    g[u][v] = g[v][u] = D[u][v] = D[v][u] = min(g[v][u], (ll)w);
  }
  rep(k, 1, n) rep(i, 1, n) rep(j, 1, n)
    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
  scanf("%d", &q);
  rep(i, 1, q) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    vec[u].pb({v, w});
    // vec[v].pb({u, w});
  }
  rep(u, 1, n) {
    if(!vec[u].size()) continue ;
    fill(Max + 1, Max + n + 1, -INF);
    for(Q x : vec[u]) {
      rep(v, 1, n) if(v != u && D[x.v][v] < INF) {
        Max[v] = max(Max[v], x.len - D[x.v][v]);
      }
    }
    rep(i, 1, n) if(D[u][i] < INF) rep(j, 1, n) if(i != j && g[i][j] < INF) {
      if(D[u][i] + g[i][j] <= Max[j]) {
        res[i][j] = res[j][i] = 1;
      }
    }
  }
  rep(i, 1, n) rep(j, i + 1, n) ans += res[i][j];
  printf("%d\n", ans);
  return 0;
}