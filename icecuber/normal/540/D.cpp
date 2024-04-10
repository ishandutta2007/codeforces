#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef long double ld;
ld dp[101][101][101][3];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int r, s, p;
  cin >> r >> s >> p;
  for (int i = 0; i <= r; i++)
    for (int j = 0; j <= s; j++)
      for (int k = 0; k <= p; k++) {
	int c[3] = {i,j,k};
	ld sum = 0;
	for (int l = 0; l < 3; l++) {
	  if (i+j==0 || i+k==0 || j+k==0) {
	    dp[i][j][k][l] = i+j+k == c[l];
	  } else {
	    ld is = (ld)1/(i*j+i*k+j*k);
	    //cout << is << endl;
	    if (i)
	      dp[i][j][k][l] += dp[i-1][j][k][l]*(i*k)*is;
	    if (j)
	      dp[i][j][k][l] += dp[i][j-1][k][l]*(i*j)*is;
	    if (k)
	      dp[i][j][k][l] += dp[i][j][k-1][l]*(j*k)*is;
	  }
	  //cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << dp[i][j][k][l] << endl;
	  sum += dp[i][j][k][l];
	}
	//cout << i << ' ' << j << ' ' << k << ' ' << sum << endl;
      }
  cout << setprecision(20);
  for (int i = 0; i < 3; i++)
    cout << dp[r][s][p][i] << ' ';
  cout << endl;
}