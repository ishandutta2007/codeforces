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

const int mod = 998244353;
int add(int x, int y) {x += y; if(x >= mod) return x - mod; return x;}
int sub(int x, int y) {x -= y; if(x < 0) return x + mod; return x;}
int mul(int x, int y) {return (ll) x * y % mod;}

const int MAXN = 5e5 + 5;

int dp[MAXN][4];

vector<pii> e[MAXN];

bool cmp(const pii &A, const pii &B) {
  return A.se < B.se;
}

int biojenemoj(vector<int> &v) {
  int ret = 1;
  for(auto x: v) {
    ret = mul(ret, add(dp[x][0], dp[x][2]));
  }
  return ret;
}

int suff[MAXN];
int pref[MAXN];

int biojeuzmi(vector<int> &v) {
  REP(i, v.size()) {
    suff[i] = dp[v[i]][1];
  }
  for(int i = v.size() - 2; i >= 0; --i) {
    suff[i] = mul(suff[i], suff[i + 1]);
  }

  REP(i, v.size()) {
    pref[i] = add(dp[v[i]][0], dp[v[i]][2]);
  }
  for(int i = 1; i < v.size(); ++i) {
    pref[i] = mul(pref[i], pref[i - 1]);
  }

  int ret = 0;
  REP(i, v.size()) {
    int tmp = 1;
    if(i) tmp = mul(tmp, pref[i - 1]);
    if(i + 1 < v.size()) tmp = mul(tmp, suff[i + 1]);

    ret = add(ret, mul(tmp, dp[v[i]][3]));
  }
  return ret;
}
int nijebio(vector<int> &v) {
  int ret = 1;
  for(auto x: v) {
    ret = mul(ret, dp[x][1]);
  }
  return ret;
}

void dfs(int u, int v, int t) {
  vector<int> pref;
  vector<int> suff;

  vector<int> pri, pos;

  for(auto p: e[v]) {
    int w = p.fi;
    int T = p.se;
    if(u != w) {
      dfs(v, w, T);
      if(T < t) {
        pri.pb(w);
      } else {
        pos.pb(w);
      }
    }
  }

  int nijp = nijebio(pos);

  // bio je gore i uzimam ja
  int tmp = biojenemoj(pri);
  dp[v][2] = mul(tmp, nijp);
  // bio je i ne uzimam
  dp[v][1] = mul(tmp, add(biojenemoj(pos), biojeuzmi(pos)));
  // uzet cu dolje
  dp[v][3] = dp[v][1];

  // nijebio
  tmp = biojeuzmi(pri);
  // sam
  dp[v][0] = mul(tmp, nijp);
  dp[v][1] = add(dp[v][1], mul(tmp, nijp));

}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n; cin >> n;
  REP(i, n - 1) {
    int u, v; cin >> u >> v;
    --u; --v;
    e[u].pb({v, i});
    e[v].pb({u, i});
  }

  REP(i, n) sort(all(e[i]), cmp);

  dfs(0, 0, n + 1);

  cout << add(dp[0][2], dp[0][0]) << endl;
}