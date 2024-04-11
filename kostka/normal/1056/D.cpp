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

const int MAXN = 100007;
vi G[MAXN];
int dp[MAXN];
bool odw[MAXN];

void dfs(int v) {
  odw[v] = true;
  dp[v] = (!G[v].empty() ? 0 : 1);
  for(auto w : G[v]) if(!odw[w]) {
    dfs(w);
    dp[v] += dp[w];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i=1; i<n; i++) {
    int a;
    cin >> a;
    a--;
    G[a].push_back(i);
  } 
  dfs(0);
  sort(dp, dp+n);
  for(int i=0; i<n; i++) cout << dp[i] << " ";
  cout << "\n";
  return 0;
}