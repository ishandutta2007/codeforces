#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[20][4][2];

ll slow(ll n, int K = 3) {
  ll ans = 0;
  for (int i = 0; i <= n; i++) {
    ll diffs = 0;
    ll m = i;
    while (m) {
      diffs += !!(m%10);
      m /= 10;
    }
    if (diffs <= K) ans++;
  }
  return ans;
}

ll f(ll n, int K = 3) {
  vector<int> v;
  ll m = n;
  while (m) {
    v.push_back(m%10);
    m /= 10;
  }
  dp[0][0][1] = 1;
  reverse(v.begin(), v.end());
  for (int i = 1; i <= v.size(); i++) {
    for (int j = 0; j < 4; j++) {
      int j_ = j-!!v[i-1];
      dp[i][j][1] = j_ > -1 ? dp[i-1][j_][1] : 0;
      dp[i][j][0] =
	(j ? 9 * dp[i-1][j-1][0] + dp[i-1][j-1][1] * max(0,v[i-1]-1) : 0) +
	dp[i-1][j][0] +
	dp[i-1][j][1]*!!v[i-1];
      //cout << i << ' ' << j << ' ' << dp[i][j][0] << ' ' << dp[i][j][1] <<endl;
    }
  }
  ll ans = 0;
  for (int j = 0; j <= K; j++)
    for (int k = 0; k < 2; k++)
      ans += dp[v.size()][j][k];
  //cout << ans << endl;
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll l, r;
    cin >> l >> r;
    cout << f(r)-f(l-1) << '\n';
  }
}