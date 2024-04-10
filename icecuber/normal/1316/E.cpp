#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, p, k;
  cin >> n >> p >> k;
  vector<pair<int,vector<int>>> player(n);
  for (int i = 0; i < n; i++) cin >> player[i].first;
  for (auto&[a,s] : player) {
    s.resize(p);
    for (int&v : s) cin >> v;
  }
  sort(player.rbegin(), player.rend());

  vector<ll> dp(1<<p,-1e18);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    auto [a,s] = player[i];
    vector<ll> ndp = dp;
    for (int m = 0; m < 1<<p; m++) {
      for (int j = 0; j < p; j++) {
	if (!(m>>j&1)) {
	  //Place in position p
	  ndp[m|1<<j] = max(ndp[m|1<<j], dp[m]+s[j]);
	}
      }
      if (i-__builtin_popcount(m) < k) {
	//Place in audience
	ndp[m] = max(ndp[m], dp[m]+a);
      }
    }
    swap(dp,ndp);
  }
  cout << dp[(1<<p)-1] << endl;
}