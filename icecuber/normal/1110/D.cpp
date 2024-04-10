#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int c[1000000];
const int M = 10;
int dp[M][M], ndp[M][M];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    c[a-1]++;
  }

  fill_n((int*)dp, M*M, -1e9);
  dp[0][0] = 0;
  for (int i = 0; i < m; i++) {
    fill_n((int*)ndp, M*M, -1e9);
    for (int a = 0; a < M; a++)
      for (int b = 0; b < M; b++) {
	int rem = min({a, b, c[i]});
	int ma = (c[i]-rem)/3;
	for (int j = 0; j <= ma; j++) {
	  int na = b-rem, nb = c[i]-rem-j*3;
	  if (nb < M)
	    ndp[na][nb] = max(ndp[na][nb], dp[a][b]+rem+j);
	}
      }
    copy_n((int*)ndp, M*M, (int*)dp);
  }
  int ans = 0;
  for (int a = 0; a < M; a++)
    for (int b = 0; b < M; b++)
      ans = max(ans, dp[a][b]);
  cout << ans << endl;
}