#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double dp[1000];
double x[1000], y[1000], p[1000], t[1000];

ll sqr(ll x) {return x*x;}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> perm;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> t[i] >> p[i];
    perm.push_back(i);
  }
  sort(perm.begin(), perm.end(), [&](int a, int b) {return t[a]<t[b];});
  double ans = 0;
  for (int ii = 0; ii < n; ii++) {
    int i = perm[ii];
    for (int jj = 0; jj < ii; jj++) {
      int j = perm[jj];
      if (sqr(t[i]-t[j]) >= sqr(x[i]-x[j])+sqr(y[i]-y[j])) {
	dp[i] = max(dp[i], dp[j]);
      }
    }
    dp[i] += p[i];
    ans = max(ans, dp[i]);
  }
  cout << setprecision(20) << ans << endl;
}