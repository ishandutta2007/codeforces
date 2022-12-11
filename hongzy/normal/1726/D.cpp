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

const int N = 4e5 + 10;
const int mod = 1e9 + 7;
int n, m;
char ans[N];
vector<int> G[N], ID[N];

int tf[N], d[N];
struct edge {
  int u, v, id;
  bool operator < (const edge &e) const {
    return d[u] - d[v] < d[e.u] - d[e.v];
  }
};
vector<edge> vv;
bool vis[N];
void dfs(int u, int fa = 0) {
  vis[u] = 1;
  d[u] = d[fa] + 1;
  rep(i, 0, int(G[u].size()) - 1) {
    int v = G[u][i], id = ID[u][i];
    if(v != fa && !vis[v]) {
      tf[v] = id;
      dfs(v, u);
    } else if(v != fa && d[v] < d[u]) {
      vv.pb({u, v, id});
    }
  }
}
int main() {
  int t; scanf("%d", &t);
  while(t--) {
    scanf("%d%d", &n, &m);
    rep(i, 1, n) G[i].clear(), ID[i].clear(), vis[i] = 0;
    int u, v;
    rep(i, 1, m) {
      ans[i] = '0';
      scanf("%d%d", &u, &v);
      G[u].pb(v); ID[u].pb(i);
      G[v].pb(u); ID[v].pb(i);
    }
    ans[m + 1] = 0;
    vv.clear();
    dfs(1);

    bool ok = vv.size() < 3;
    vector<int> z;
    if(!ok) {
      rep(i, 0, 2)
        z.pb(vv[i].u), z.pb(vv[i].v);
      sort(z.begin(), z.end());
      ok = 1;
      if(z[0] == z[1] && z[2] == z[3] && z[4] == z[5])
        ok = 0;
    }
    if(ok) {
      for(auto &e : vv) ans[e.id] = '1';
    } else {
      int x = z[0];
      if(d[z[2]] > d[x]) x = z[2];
      if(d[z[4]] > d[x]) x = z[4];
      ans[tf[x]] = '1';
      sort(vv.begin(), vv.end());
      ans[vv[0].id] = ans[vv[1].id] = '1';
    }
    puts(ans + 1);
  }
  return 0;
}