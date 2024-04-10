#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb push_back

typedef long long ll;
typedef pair<int, int> point;

#define fi first
#define se second

const int mod = 1e9 + 7;
int add(int x, int y) {
  x += y;
  if(x >= mod) return x - mod;
  return x;
}
int mul(int x, int y) {
  return (ll) x * y % mod;
}
int sub(int x, int y) {
  x -= y;
  if(x < 0) return x + mod;
  return x;
}

const int MAXN = 3e5 + 5;

ll a[MAXN];

vector<int> e[MAXN];

ll dp[MAXN];

ll cnt = 0;

void dfs(int u, int v) {
  ll uk = 0;
  for(auto w: e[v]) {
    if(w == u) continue;
    dfs(v, w);
    if(dp[w] >= 0) uk += dp[w];
  }

  dp[v] = a[v] + uk;
}

ll sum;
ll dp2[MAXN];

void dfs2(int u, int v) {
  ll uk = 0;
  for(auto w: e[v]) {
    if(w == u) continue;
    dfs2(v, w);
    if(dp2[w] >= 0) uk += dp2[w];
  }

  dp2[v] = a[v] + uk;

  if(dp2[v] == sum) {
    cnt ++;
    dp2[v] = 0;
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  bool pos = false;
  int n; cin >> n;
  REP(i, n) {
    cin >> a[i];
  }

  REP(i, n - 1) {
    int x, y; cin >> x >> y;
    x --; y --;
    e[x].pb(y);
    e[y].pb(x);
  }

  dfs(0, 0);

  sum = a[0];

  REP(i, n) {
    sum = max(sum, dp[i]);
  }

  dfs2(0, 0);

  cout << sum * cnt _ cnt << endl;
}