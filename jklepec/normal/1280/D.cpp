#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define pb push_back
#define fi first
#define se second
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define TRACE(x) cerr << #x << "  " << x << endl
template<typename T1, typename T2>inline void minaj(T1 &x, T2 y) { x = (x > y ? y: x);}
template<typename T1, typename T2>inline void maxaj(T1 &x, T2 y) { x = (x < y ? y: x);}

typedef long long ll;
typedef pair<int, ll> pii;

const int MAXN = 3005;

int sz[MAXN];
vector<int> e[MAXN];

int a[MAXN];

pii dp[MAXN][MAXN];
pii ndp[MAXN];

int m;

void dfs(int u, int v) {
  sz[v] = 1;
  dp[v][1] = pii(0, a[v]);

  for(int w: e[v]) {
    if(u != w) {
      dfs(v, w);

      REP(i, sz[v] + sz[w] + 1) ndp[i] = {-1, 0};

      FOR(i, 1, min(sz[v], m) + 1) FOR(j, 1, min(sz[w], m) + 1) {
        ll v1 = dp[v][i].se;
        ll v2 = dp[w][j].se;

        maxaj(ndp[i + j - 1], pii(dp[v][i].fi + dp[w][j].fi, v1 + v2));
        maxaj(ndp[i + j], pii(dp[v][i].fi + dp[w][j].fi + (v2 > 0), v1));
      }

      REP(i, sz[v] + sz[w] + 1) dp[v][i] = ndp[i];
      sz[v] += sz[w];
    }
  }
}

void solve() {
  int n; cin >> n >> m;
  REP(i, n) {
    cin >> a[i];
  }
  REP(i, n) {
    int x; cin >> x;
    a[i] -= x;
    a[i] *= -1;
    e[i].clear();
  }
  REP(i, n - 1) {
    int u, v; cin >> u >> v;
    u --; v --;
    e[u].pb(v);
    e[v].pb(u);
  }

  dfs(0, 0);
  cout << dp[0][m].fi + (dp[0][m].se > 0) << endl;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t --) solve();

}