#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int&v : a) cin >> v;
    int x;
    cin >> x;

    vector<int> dp(4, 0);
    for (int i = 0; i < n; i++) {
      vector<int> ndp(4, 1e9);
      //Leave
      ndp[0] = min({dp[0], dp[1], dp[2], dp[3]})+1;
      //Take
      ndp[1] = dp[0];
      if (!i || a[i-1]+a[i] >= 2*x)
        ndp[2] = dp[1];
      if ((i < 2 || a[i-2]+a[i-1]+a[i] >= 3*x) && (!i || a[i-1]+a[i] >= 2*x))
        ndp[3] = min(dp[2], dp[3]);
      swap(dp, ndp);
    }

    cout << n-min({dp[0],dp[1],dp[2],dp[3]}) << endl;
  }
}