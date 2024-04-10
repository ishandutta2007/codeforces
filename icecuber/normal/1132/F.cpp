#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[501][501];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int l = 1; l <= n; l++) {
    for (int i = 0; i+l <= n; i++) {
      dp[l][i] = dp[l-1][i+1]+1;
      for (int j = 1; j < l; j++) {
	if (s[i] == s[i+j]) {
	  dp[l][i] = min(dp[l][i], dp[j-1][i+1]+dp[l-j][i+j]);
	}
      }
    }
  }
  cout << dp[n][0] << endl;
}