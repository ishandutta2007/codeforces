#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[501][501];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  for (int l = n-1; l >= 0; l--) {
    for (int r = 1; r <= n; r++) {
      if (r-l == 1) {
	dp[l][r] = a[l];
      } else {
	for (int m = l+1; m < r; m++) {
	  if (dp[l][m] && dp[l][m] == dp[m][r])
	    dp[l][r] = dp[l][m]+1;
	}
      }
      //cout << l << ' ' << r << ' ' << dp[l][r] << endl;
    }
  }
  vector<int> dp2(n+1);
  for (int i = 1; i <= n; i++) {
    dp2[i] = 1e9;
    for (int j = 0; j < i; j++) {
      if (dp[j][i])
	dp2[i] = min(dp2[i], dp2[j]+1);
    }
  }
  cout << dp2[n] << endl;
}