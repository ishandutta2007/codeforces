//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>
#define ALL(x) x.begin(), x.end()

#ifdef LOCAL
template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<" = "<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<" = "<<h<<", "; _dbg(sdbg+1, a...);
}
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#define cerr if(false) cout
#endif

#ifdef ONLINE_JUDGE
#define FREOPEN(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#else
#define FREOPEN(name)
#endif

const int MAXN = 500007;
const int MOD = 998244353;

int n;
int dwa[MAXN], pod[MAXN];
vi G[MAXN];
bool odw[MAXN];

int dfs(int v) {
  odw[v] = true;
  pod[v] = 1;
  for(auto w : G[v]) if(!odw[w]) pod[v] += dfs(w);
  return pod[v];
}

int RET = 0;

int dfs2(int v) {
  odw[v] = true;
  int ret = 1;
  for(auto w : G[v]) if(!odw[w]) {
    ret = (1LL * ret * (dwa[pod[w]-1] + dfs2(w))) % MOD;
  }
  ret = (MOD - ret + dwa[pod[v]-1]) % MOD;
  RET += (1LL * ret * dwa[n - pod[v]]) % MOD;
  RET %= MOD;
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  dwa[0] = 1;
  for(int i=1; i<MAXN; i++) {
    dwa[i] = (2 * dwa[i-1]) % MOD;
  }
  for(int i=1; i<n; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(1);
  for(int i=1; i<=n; i++) odw[i] = false;
  dfs2(1);
  cout << (2*RET) % MOD << "\n";
  return 0;
}