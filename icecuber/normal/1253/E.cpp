#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x[80], s[80];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> s[i];
  }

  vector<int> dp(m+1,1e9);
  vector<int> diff(m+1,1e9);
  dp[0] = 0;
  diff[0] = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < n; j++) {
      int a = x[j]-s[j]-1, b = max(0, i-s[j]-x[j]);
      int maxk = a-b;
      if (maxk < 0) {
	dp[i] = min(dp[i], dp[0]+b);
      } else {
	dp[i] = min(dp[i], diff[min(maxk,i-1)]+a);
	//for (int k = 0; k <= maxk && k < i; k++)
	//  dp[i] = min(dp[i], dp[k]+a-k);
      }
    }
    diff[i] = min(diff[i-1], dp[i]-i);
  }
  cout << dp[m] << endl;
}