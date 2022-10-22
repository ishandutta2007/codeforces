#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> hard(n);
    for (int&v : hard) cin >> v;
    vector<int> dp(n+1, 1e9);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
      for (int f : {1,2}) {
	if (f+i > n) continue;
	for (int you : {1,2}) {
	  int ndp = dp[i]+hard[i]+(f == 2 && hard[i+1]);
	  int j = min(i+f+you, n);
	  dp[j] = min(dp[j], ndp);
	}
      }
    }
    cout << dp[n] << endl;
  }
}