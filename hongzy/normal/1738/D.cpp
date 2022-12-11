#include <bits/stdc++.h>
#define LOG(FMT...) fprintf(stderr, FMT);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
mt19937 mt(std::chrono::system_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> ran(0, 1ll << 62);
void ucin() { ios::sync_with_stdio(0); cin.tie(0); }
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }
inline ll sqr(ll x) { return x * x; }
inline ll cub(ll x) { return x * x * x; }

const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int n, b[N], a[N], m, k;
vector<int> G[N];
void dfs(int u, int d) {
  if(1 <= u && u <= n) {
    a[++ m] = u;
    if(d == 1) k = min(k, u);
  }
  sort(G[u].begin(), G[u].end(), [&](int x, int y) {
    return G[x].size() < G[y].size();
  });
  for(int v : G[u]) {
    dfs(v, d ^ 1);
  }
}
int main() {
  int test;
  scanf("%d", &test);
  rep(T, 1, test) {
    scanf("%d", &n);
    m = 0;
    rep(i, 0, n+1) G[i].clear();
    rep(i, 1, n) scanf("%d", b + i), G[b[i]].pb(i);

    int rt = G[n+1].size() ? n+1 : 0;
    k = n+1;
    dfs(rt, rt == n+1 ? 1 : 0);
    printf("%d\n", k-1);
    rep(i, 1, n) printf("%d%c", a[i], " \n"[i==n]);
  }
  return 0;
}