#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void minu(int&a, int b) {
  a = min(a, b);
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 1e9;
    for (int start = 0; start < 4; start++) {
      int inf = 1e9;
      vector<array<int,4>> dp(n+1, array<int,4>{inf,inf,inf,inf});
      dp[0][start] = 0;
      for (int i = 0; i < n; i++) {
	for (int j = 0; j < 4; j++) {
	  //Place L
	  if (j != 0)
	    minu(dp[i+1][j>>1], dp[i][j]+(s[i]!='L'));
	  //Place R
	  if (j != 3)
	    minu(dp[i+1][j>>1|2], dp[i][j]+(s[i]!='R'));
	}
      }
      ans = min(ans, dp[n][start]);
    }
    cout << ans << endl;
  }
}