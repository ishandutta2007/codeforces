#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[2001][2001];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  //dp[i][j] = minimum cost of getting j items with the first i items
  vector<ll> dp(n,1e18);
  dp[0] = 0;
  ll ans = 1e18;
  for (int i = 0; i < n; i++) {
    vector<ll> ndp = dp;
    ll t, c;
    cin >> t >> c;
    for (int j = 0; j < n; j++) {
      int j_ = j+t+1;
      ll cost = c+dp[j];
      if (j_ >= n) ans = min(ans, cost);
      else
	ndp[j_] = min(ndp[j_], cost);
    }
    swap(dp,ndp);
  }
  cout << ans << endl;
}