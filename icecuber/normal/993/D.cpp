#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second

ll a[50], b[50];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];

  ll fail = 0, pass = 2e8*1e3;
  while (abs(pass-fail) > 1) {
    ll t = pass+fail>>1;
    vector<pair<ll,ll>> p(n);
    for (int i = 0; i < n; i++) {
      p[i] = {a[i],t*b[i]-a[i]*1000};
    }
    sort(p.rbegin(), p.rend());

    //dp[i][k] = max score, up to i, with k open second tasks
    vector<vector<ll>> dp(n+1, vector<ll>(n+1,-1e18));
    dp[0][0] = 0;
    for (int i = 0; i < n;) {
      int j = i;
      while (j < n && p[i].x == p[j].x) j++;
      //if (pass == 2e11)
      //cout << i << ' ' << j << endl;

      for (int k = 0; k <= n; k++) {
	if (dp[i][k] < -1e17) continue;
	//if (dp[i][k] > -1e17)
	//  cout << i << ' ' << k << ' ' << dp[i][k] << endl;
	ll acc = 0;
	//Number of tasks to place in new computers
	for (int l = 0; l <= j-i; l++) {
	  int newk = k+l-(j-i-l);
	  if (newk >= l && newk <= n) {
	    //cout << i << ' ' << k << ", " << j << ' ' << newk << ' '<< l << ' ' << acc << endl;
	    ll&d = dp[j][newk];
	    d = max(d, dp[i][k]+acc);
	  }
	  if (i+l < j)
	    acc += p[i+l].y;
	}
      }
      i = j;
    }

    //cout << fail << ' ' << pass << ' ' << dp[n][0] << endl;
    int ok = 0;
    for (int k = 0; k <= n; k++)
      if (dp[n][k] >= 0) ok = 1;

    if (ok) pass = t;
    else fail = t;
  }
  cout << pass << endl;
}