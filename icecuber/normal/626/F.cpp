#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9+7;
void self_add(ll&a, ll b) {
  a += b;
  if (a >= mod)
    a -= mod;
}
ll mul(ll a, ll b) { return a*b%mod; }

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  sort(a.begin(), a.end());
  //dp[i][j][k] = number of ways, up to i, with j open groups, with imbalance k
  vector<vector<ll>> dp(n, vector<ll>(m+1,0));
  dp[0][0] = 1;
  if (n > 1)
    dp[1][0] = 1;
  for (int i = 1; i < n; i++) {
    vector<vector<ll>> ndp(n, vector<ll>(m+1,0));
    for (int j = 0; j < n; j++) {
      for (int k = 0; k <= m; k++) {
	int k_ = k+j*(a[i]-a[i-1]);
	if (k_ > m) continue;
	if (j+1 < n)
	  self_add(ndp[j+1][k_], dp[j][k]);
	self_add(ndp[j][k_], dp[j][k]);
	self_add(ndp[j][k_], mul(j,dp[j][k]));
	if (j)
	  self_add(ndp[j-1][k_], mul(j,dp[j][k]));
      }
    }
    swap(dp,ndp);
    /*for (int j = 0; j < n; j++) {
      for (int k = 0; k <= m; k++)
	cout << dp[j][k] << ' ';
      cout << endl;
    }
    cout << endl;*/
  }
  ll ans = 0;
  for (int k = 0; k <= m; k++)
    self_add(ans, dp[0][k]);
  cout << ans << endl;
}