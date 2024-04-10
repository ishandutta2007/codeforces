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
int n, l[N], r[N];
vector<int> G[N];
ll f[N], g[N];
void dfs(int u, int fa = 0) {
  f[u] = g[u] = 0;
  for(int v : G[u]) if(v != fa) {
    dfs(v, u);
    f[u] += max(g[v] + abs(r[v] - l[u]), f[v] + abs(l[v] - l[u]));
    g[u] += max(g[v] + abs(r[v] - r[u]), f[v] + abs(l[v] - r[u]));
  }
}
int main() {
  int test;
  scanf("%d", &test);
  while(test --) {
    scanf("%d", &n);
    rep(i, 1, n) G[i].clear();
    rep(i, 1, n) scanf("%d%d", l + i, r + i);
    int u, v;
    rep(i, 1, n - 1) {
      scanf("%d%d", &u, &v);
      G[u].pb(v); G[v].pb(u);
    }
    dfs(1);
    printf("%lld\n", max(f[1], g[1]));
  }
  return 0;
}