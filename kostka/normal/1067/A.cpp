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
const int MAXA = 200;
const int MOD = 998244353;
ll dp[MAXN][MAXA+7][2];

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vi A(n+1);
  for(int i=1; i<=n; i++) cin >> A[i];

  dp[0][0][0] = 1;
  for(int i=1; i<=n; i++) {
    if(A[i] != -1) {
      for(int j=0; j<A[i]; j++) {
        dp[i][A[i]][0] += dp[i-1][j][0] + dp[i-1][j][1];
        dp[i][A[i]][0] %= MOD;
      }
      dp[i][A[i]][1] += dp[i-1][A[i]][0] + dp[i-1][A[i]][1];
      dp[i][A[i]][1] %= MOD;
      for(int j=A[i]+1; j<=MAXA; j++) {
        dp[i][A[i]][1] += dp[i-1][j][1];
        dp[i][A[i]][1] %= MOD;
      }
    } else {
      ll lef = dp[i-1][0][0];
      for(int j=1; j<=MAXA; j++) {
        dp[i][j][0] += lef;
        dp[i][j][0] %= MOD;
        lef += dp[i-1][j][0] + dp[i-1][j][1];
        lef %= MOD;
      }
      ll rig = 0;
      for(int j=MAXA; j>=1; j--) {
        rig += dp[i-1][j][1];
        rig %= MOD;
        dp[i][j][1] += rig + dp[i-1][j][0];
        dp[i][j][1] %= MOD;
      }
    }
  }
  ll ret = 0;
  for(int i=1; i<=MAXA; i++) {
    ret += dp[n][i][1];
    ret %= MOD;
  }
  cout << ret << "\n";
  return 0;
}