#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  //dp[i][j] = number of ways if the i'th digit is j
  int dail_self = 1;
  vector<ll> dp(10,1);
  for (int i = 1; i < n; i++) {
    vector<ll> ndp(10,0);
    int d = s[i]-'0';
    for (int j = 0; j < 10; j++) {
      ndp[d+j>>1] += dp[j];
      if (d+j&1)
	ndp[d+j+1>>1] += dp[j];
    }
    swap(dp,ndp);
    if (abs((s[i-1]-'0')-(s[i]-'0')) > 1)
      dail_self = 0;
  }
  ll ans = -dail_self;
  for (ll v : dp) ans += v;
  cout << ans << endl;
}