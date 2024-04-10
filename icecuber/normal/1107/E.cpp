#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll p[101];
ll dp[101][101][101];
ll dp2[101][101];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  for (int i = 1; i <= n; i++)
    cin >> p[i];
  for (int a = n-1; a >= 0; a--) {
    for (int b = a+1; b <= n; b++) {
      for (int c = 1; c <= n; c++) {
	dp[a][b][c] = c==1?dp2[a+1][b]:-1e18;
	for (int i = a+1; i < b; i++) {
	  if (s[a] == s[i])
	    dp[a][b][c] = max(dp[a][b][c], dp2[a+1][i]+dp[i][b][c-1]);
	}
	dp2[a][b] = max(dp2[a][b], dp[a][b][c]+p[c]);
      }
    }
  }
  cout << dp2[0][n] << endl;
}