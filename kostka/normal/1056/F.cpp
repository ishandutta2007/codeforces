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

void test() {
  int n;
  double C, T;
  cin >> n >> C >> T;
  vector <pair <int, int> > Z(n);
  for(int i=0; i<n; i++) cin >> Z[i].x >> Z[i].y;
  sort(ALL(Z));
  vector <vector <double> > dp(n+1);
  dp[0].resize(10*n+7, 1e18);
  dp[0][0] = 0.0;
  for(int i=0; i<n; i++) {
    dp[i+1].resize(10*n+7, 1e18);
    for(int j=i; j>=0; j--) {
      for(int k=0; k<=10*j; k++) {
        if(dp[j][k] >= 1e18) continue; 
        double ttt = dp[j][k] / 0.9 + Z[i].x;
        if(dp[j+1][k + Z[i].y] > ttt) dp[j+1][k+Z[i].y] = ttt;
      }
    }
  }
  for(int k=10*n; k>=0; k--) {
    for(int j=0; j<=n; j++) {
      if(10 * j >= k) {
        if(dp[j][k] >= 1e18) continue;
        // cerr << j << " " << k << " " << dp[j][k] << "\n";
        // cerr << dp[j][k] / 0.9 * C << "\n";
        double t = ((dp[j][k] / 0.9 * C < 1.0) ? 
          (dp[j][k] / 0.9 + j * 10) :
          (2 * sqrt(dp[j][k] / 0.9 / C) - 1.0 / C + j * 10));
        if(t <= T) {
          cout << k << "\n";
          return;
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--) test();
  return 0;
}