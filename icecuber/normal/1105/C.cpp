#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9+7;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, l, r;
  cin >> n >> l >> r;
  l--;
  vector<ll> dp(3,0), ways(3);
  ways[0] = r/3-l/3;
  ways[1] = (r+2)/3-(l+2)/3;
  ways[2] = (r+1)/3-(l+1)/3;
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    vector<ll> prev = dp;
    for (int j = 0; j < 3; j++) {
      dp[j] = 0;
      for (int k = 0; k < 3; k++)
	(dp[j] += prev[(j-k+3)%3]*ways[k]%mod) %= mod;
    }
  }
  cout << dp[0] << endl;
}