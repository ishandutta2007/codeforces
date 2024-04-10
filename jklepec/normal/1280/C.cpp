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

typedef double lf;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;
int add(int x, int y) {x += y; if(x >= mod) return x - mod; return x;}
int sub(int x, int y) {x -= y; if(x < 0) return x + mod; return x;}
int mul(int x, int y) {return (ll) x * y % mod;}

const int MAXN = 2e5 + 5;

int sz[MAXN];
vector<pii> e[MAXN];

void dfs(int u, int v) {
  sz[v] = 1;
  for(auto p: e[v]) {
    int w = p.fi;
    if(u != w) {
      dfs(v, w);
      sz[v] += sz[w];
    }
  }
}

vector<pair<int, pii>> edges;

void solve() {
  int k; cin >> k;
  int n = 2 * k;
  FOR(i, 1, n + 1) e[i].clear();
  edges.clear();
  REP(i, n - 1) {
    int u, v, w; cin >> u >> v >> w;
    e[u].pb({v, w});
    e[v].pb({u, w});

    edges.pb({w, {u, v}});
  }

  dfs(1, 1);

  ll A = 0, B = 0;
  for(auto p: edges) {
    int w = p.fi;
    int u = p.se.fi;
    int v = p.se.se;

    if(sz[u] > sz[v]) swap(u, v);

    int L = sz[u];
    int R = n - sz[u];

    A += (ll) w * min(L, R);
    B += (ll) w * (L % 2);
  }

  cout << B _ A << endl;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t --) solve();
}