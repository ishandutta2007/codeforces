#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double dp[101][101], dp2[101][101];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  ll k;
  string s;
  cin >> n >> k >> s;
  dp[0][0] = 1;
  int last[26];
  fill_n(last, 26, -1);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      int l = last[s[i-1]-'a'];
      dp[i][j] = dp[i-1][j]+dp[i-1][j-1]-(l==-1 ? 0 : dp[l][j-1]);
    }
    last[s[i-1]-'a'] = i-1;
  }
  ll ans = 0;
  for (int i = n; i >= 0; i--) {
    if (dp[n][i] >= k) {
      ans += k*(n-i);
      cout << ans << endl;
      return 0;
    }
    k -= ll(dp[n][i]);
    ans += ll(dp[n][i])*(n-i);
  }
  cout << -1 << endl;
}