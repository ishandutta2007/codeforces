#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[300001];
int dp[5001][5001];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a+n);
  a[n] = a[n-1];

  int na = k-n%k, nb = n%k;
  int x = n/k, y = x+1;
  for (int i = 0; i <= na; i++) {
    for (int j = 0; j <= nb; j++) {
      //cout << i << ' ' << j << ": " << dp[i][j] << ' ' << x*i+y*j << endl;
      if (i < na) {
	dp[i+1][j] = max(dp[i+1][j], dp[i][j]+a[x*i+y*j+x]-a[x*i+y*j+x-1]);
      }
      if (j < nb) {
	dp[i][j+1] = max(dp[i][j+1], dp[i][j]+a[x*i+y*j+y]-a[x*i+y*j+y-1]);
      }
    }
  }
  cout << a[n-1]-a[0]-dp[na][nb] << endl;
}