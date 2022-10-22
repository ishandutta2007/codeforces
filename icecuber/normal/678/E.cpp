#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double p[18][18];
double dp[1<<17][17];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> p[i][j];
  n--;

  for (int i = (1<<n)-1; i; i--) {
    for (int j = 0; j < n; j++) {
      if ((i>>j&1)==0) continue;
      if (i == (1<<n)-1) {
	dp[i][j] = p[0][j+1];
	continue;
      }
      for (int k = 0; k < n; k++) {
	if (i>>k&1) continue;
	dp[i][j] = max(dp[i][j], dp[i|1<<k][j]*p[j+1][k+1]+dp[i|1<<k][k]*p[k+1][j+1]);
      }
    }
  }
  double ans = n==0;
  for (int j = 0; j < n; j++)
    ans = max(ans, dp[1<<j][j]);
  cout << setprecision(20) << ans << endl;
}