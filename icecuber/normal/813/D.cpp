#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[5001][5001];
int prev_pos[5000][3];
int last[100010];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int&v : a) cin >> v;

  fill_n(last, 1e5+10, -1);
  for (int i = 0; i < n; i++) {
    prev_pos[i][0] = last[a[i]-1];
    prev_pos[i][1] = last[a[i]+1];
    prev_pos[i][2] = last[a[i]];
    last[a[i]] = i;
  }

  for (int j = -1; j < n; j++) {
    int best7[7] = {};
    for (int i = -1; i < n; i++) {
      if (i == j) continue;
      int&d = dp[i+1][j+1];
      if (i < j) {
	d = dp[j+1][i+1];
      } else {
	d = max(d, best7[a[i]%7]);

	for (int k : {0,1}) {
	  int p = prev_pos[i][k];
	  if (p == j && p > -1) p = prev_pos[p][2];
	  d = max(d, dp[p+1][j+1]+1);
	}
      }
      if (i > -1)
	best7[a[i]%7] = max(best7[a[i]%7], d+1);
    }
  }
  /*cout << dp[0][0] << endl;
  cout << dp[1][0] << endl;
  cout << dp[2][0] << endl;
  cout << dp[2][3] << endl;
  cout << dp[2][4] << endl;*/

  int ans = 0;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++)
      ans = max(ans, dp[i][j]);
  cout << ans << endl;
}