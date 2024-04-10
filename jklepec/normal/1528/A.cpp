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
ll dp[MAXN][2];
int l[MAXN];
int r[MAXN];

vector<int> e[MAXN];

void dfs(int u, int v) {
  for (auto w: e[v]) {
    if (w == u) continue;
    dfs(v, w);

    dp[v][0] += max(dp[w][1] + abs(r[w] - l[v]), dp[w][0] + abs(l[w] - l[v]));
    dp[v][1] += max(dp[w][1] + abs(r[w] - r[v]), dp[w][0] + abs(l[w] - r[v]));
  }
}

void solve() {
  int n; cin >> n;
  REP(i, n) dp[i][0] = dp[i][1] = 0;
  REP(i, n) e[i].clear();
  REP(i, n) cin >> l[i] >> r[i];
  REP(i, n-1) {
    int u, v; cin >> u >> v;
    e[--v].pb(--u);
    e[u].pb(v);
  }
  dfs(0, 0);
  cout << max(dp[0][0], dp[0][1]) << endl;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--) solve();
}