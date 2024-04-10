#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


double p[51][51][51];
int a[50];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
    cin >> a[i];
  //p[i][j][k] = probability that, among the first i, largest queue is j, with k people left
  p[0][0][n] = 1;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= n; k++) {
	double x = 1./(m-i);
	double bern = pow(x,k), sum = 0;
	for (int l = k; l >= 0; l--) {
	  double& p_ = p[i+1][max(j,(l+a[i]-1)/a[i])][k-l];
	  p_ += p[i][j][k]*bern;
	  sum += bern;
	  if (l)
	    bern *= (1-x)*l/(x*(k+1-l));
	}
	//cout << x << ' ' << k << ' ' << sum << endl;
      }
    }
  }
  double ans = 0;
  for (int j = 0; j <= n; j++) {
    ans += j*p[m][j][0];
  }
  cout << setprecision(20) << ans << endl;
}