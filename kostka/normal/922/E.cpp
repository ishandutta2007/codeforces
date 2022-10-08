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

const int MAXN = 1e3+7;
const int MAXA = 1e4+7;
const long long INF = 1e18+7;

ll dp[MAXN][MAXA];
int c[MAXN], cost[MAXN];

int main()
{
  ios_base::sync_with_stdio(0);
  int n, w, b, x;
  cin >> n >> w >> b >> x;
  for(int i=1; i<=n; i++) {
    cin >> c[i];
  }
  for(int i=1; i<=n; i++) {
    cin >> cost[i];
  }
  for(int i=0; i<=n; i++) {
    for(int j=0; j<MAXA; j++)
      dp[i][j] = -INF;
  }
  dp[0][0] = w;
  int opt = 0;
  for(int i=1; i<=n; i++) {
    for(int j=0; j<=c[i]; j++) {
      for(int k=0; k<=opt; k++) {
        if(dp[i-1][k] >= 1LL * j * cost[i]) {
          dp[i][j+k] = max(dp[i][j+k], dp[i-1][k] - 1LL * j * cost[i]);
          opt = max(opt, j+k);
        }
      }
    }
    for(int k=0; k<MAXA; k++) {
      if(dp[i][k] >= 0) dp[i][k] = min(dp[i][k] + x, w + 1LL * k * b);
      //cerr << dp[i][k] << " ";
    }
    //cerr << "\n";
  }
  int res = -1;
  for(int i=0; i<MAXA; i++) {
    if(dp[n][i] != -INF) res = i;
  }
  cout << res << "\n";
  return 0;
}