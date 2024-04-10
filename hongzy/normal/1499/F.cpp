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

const int N = 5005;
const int mod = 998244353;
inline int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline int dec(int x, int y) { return x - y < 0 ? x - y + mod : x - y; }
inline void ADD(int &x, const int &y) { (x += y) >= mod ? x -= mod : 0; }
inline void DEC(int &x, const int &y) { (x -= y) < 0 ? x += mod : 0; }

int f[N][N], tot[N], n, k, g[N];
vector<int> G[N];
void dfs(int u, int fa = 0) {
  f[u][0] = 1;
  for(int v : G[u]) if(v ^ fa) {
    dfs(v, u);
    static int t[N], pf[N], pg[N];
    rep(i, 0, k) t[i] = 0;
    g[0] = 0;
    rep(i, 1, k) g[i] = f[v][i - 1];
    rep(i, 0, k) pf[i] = add(f[u][i], (i ? pf[i - 1] : 0));
    rep(i, 0, k) pg[i] = add(g[i], (i ? pg[i - 1] : 0));
    rep(i, 0, k) t[i] = (t[i] + (ll)g[i] * pf[min(i, k - i)]) % mod;
    rep(i, 1, k) t[i] = (t[i] + (ll)f[u][i] * pg[min(i - 1, k - i)]) % mod;
    rep(i, 0, k) t[i] = (t[i] + (ll)tot[v] * f[u][i]) % mod;
    rep(i, 0, k) f[u][i] = t[i];
  }
  rep(i, 0, k) ADD(tot[u], f[u][i]);
}
int main() {
  scanf("%d%d", &n, &k);
  int u, v;
  rep(i, 1, n - 1) {
    scanf("%d%d", &u, &v);
    G[u].pb(v); G[v].pb(u);
  }
  dfs(1);
  printf("%d\n", tot[1]);
  return 0;
}