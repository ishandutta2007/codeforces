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

const int N = 3e5 + 10;
const int mod = 1e9 + 7;
int n, k, ans[N], a[N];
vector<int> G[N];
int w[N], rt, size, sz[N];
bool vis[N];
void findrt(int u, int fa = 0) {
  sz[u] = 1; w[u] = 0;
  for(int &v : G[u]) if(v != fa && !vis[v]) {
    findrt(v, u); sz[u] += sz[v];
    w[u] = max(w[u], sz[v]);
  }
  w[u] = max(w[u], size - sz[u]);
  if(!rt || w[u] < w[rt]) rt = u;
}
int d[N], seq[N], m, md, res[N], arr[N], a2[N], sum[N], tmp[N];
void dfs(int u, int fa = 0) {
  md = max(md, d[u] = fa ? d[fa] + 1 : 0);
  seq[++ m] = u;
  for(int v : G[u]) if(!vis[v] && v != fa) {
    dfs(v, u);
  }
}
void calc(int u, int fa) {
  m = md = 0; dfs(u, fa);
  int lim = 2 * k - 1;
  while(lim < md) lim += k << 1;
  rep(i, 0, lim + 1) res[i] = arr[i] = a2[i] = 0;
  rep(i, 1, m) {
    int x = seq[i];
    arr[d[x]] ^= a[x];
  }
  sum[0] = arr[0];
  rep(i, 0, lim) a2[i % k] ^= arr[i];
  rep(i, 0, lim) if((i / k) & 1) res[0] ^= arr[i];
  rep(i, 0, lim - 1) {
    res[i + 1] = res[i] ^ a2[(lim - i) % k];
  }
  rep(i, 1, m) {
    int x = seq[i];
    ans[x] ^= res[d[x]];
  }
}
void solve(int u) {
  vis[u] = 1; calc(u, 0);
  for(int v : G[u]) if(!vis[v]) calc(v, u);
  for(int v : G[u]) if(!vis[v]) {
    rt = 0; size = sz[v]; findrt(v); solve(rt);
  }
}
int main() {
  scanf("%d%d", &n, &k);
  rep(i, 1, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].pb(v); G[v].pb(u);
  }
  rep(i, 1, n) scanf("%d", a + i);
  rt = 0; size = n; findrt(1); solve(rt);
  rep(i, 1, n) {
    printf("%d ", ans[i] ? 1 : 0);
  }
  puts("");
  return 0;
}