#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb push_back

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> point;

const int mod = 1e9 + 7;

int add(int x, int y) {
  x += y;
  if(x >= mod) return x - mod;
  return x;
}
int mul(int x, int y) {
  return (int) ((ll) x * y % mod);
}
int sub(int x, int y) {
  x -= y;
  if(x < 0) return x + mod;
  return x;
}

const int MAXN = 3e5 + 5;

ll dp1[MAXN], dp2[MAXN];

vector<pll> e[MAXN];

ll gas[MAXN];

void dfs(int u, int v) {
  ll tmp = 0;

  vector<pll> ch;
  vector<ll> pref, suff;

  for(auto pw: e[v]) {
    int w = (int) pw.first;
    ll c = pw.second;

    if(w == u) continue;

    dfs(v, w);
    ch.pb({w, c});

    tmp = max(tmp, dp1[w] - c);

    pref.pb(dp1[w] - c + gas[v]);
    suff.pb(dp1[w] - c + gas[v]);
  }

  REP(i, pref.size()) {
    if(i) pref[i] = max(pref[i], pref[i - 1]);
  }
  for(int i = suff.size() - 2; i >= 0; --i) {
    suff[i] = max(suff[i], suff[i + 1]);
  }

  int j = 0;
  for(auto pw: ch) {
    int w = pw.first;
    ll c = pw.second;

    dp2[w] = gas[v];
    if(j) dp2[w] = max(dp2[w], pref[j - 1]);
    if(j + 1 < suff.size()) {
      dp2[w] = max(dp2[w], suff[j + 1]);
    }

    dp2[w] = max(0LL, dp2[w] - c);
    ++j;
  }

  dp1[v] = gas[v] + tmp;
}

ll sol = 0;

void dfs2(int u, int v, ll c) {
  dp2[v] = max(dp2[v], dp2[u] - c);
  dp2[v] += gas[v];

  sol = max(sol, dp2[v]);

  for(auto pw: e[v]) {
    int w = pw.first;
    ll c = pw.second;
    if(w == u) continue;

    dfs2(v, w, c);
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  REP(i, n) {
    cin >> gas[i];
  }
  REP(i, n - 1) {
    int x, y, c; cin >> x >> y >> c;
    x --; y --;
    e[x].pb({y, c});
    e[y].pb({x, c});
  }

  dfs(0, 0);
  dfs2(0, 0, 0);

  cout << sol << endl;
}