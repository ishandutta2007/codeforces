#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
    }
    ll dp[3] = {0,b[0],b[0]*2};
    for (int i = 1; i < n; i++) {
      ll ndp[3];
      for (int j = 0; j < 3; j++) {
	ndp[j] = 2e18;
	for (int k = 0; k < 3; k++) {
	  if (a[i]+j != a[i-1]+k)
	    ndp[j] = min(ndp[j], dp[k]+b[i]*j);
	}
      }
      swap(dp,ndp);
    }
    cout << min({dp[0],dp[1],dp[2]}) << '\n';
  }
}