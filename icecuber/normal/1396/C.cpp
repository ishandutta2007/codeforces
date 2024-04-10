#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll bound(ll x) {
  if (x > 1e17) return (ll) 1e18;
  return x;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  ll r1, r2, r3, d;
  cin >> r1 >> r2 >> r3 >> d;
  vector<array<ll,2>> cost(n);
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    cost[i][0] = a*r1+r3;
    cost[i][1] = min((a+2)*r1, r2+r1);
  }
  ll base = (n-1)*d;
  ll ans = 1e18;
  for (int k : {0,1}) {
    vector<array<ll,2>> dp(n, array<ll,2>{(ll)1e18,(ll)1e18});
    dp[0][0] = base+cost[0][0];
    dp[0][1] = base+cost[0][1]+d*2;
    for (int i = 1; i < n; i++) {
      dp[i][0] = bound(min(dp[i-1][1], dp[i-1][0])+cost[i][0]);
      dp[i][1] = bound(dp[i-1][0]+cost[i][1]+cost[i-1][1]-cost[i-1][0]+d*2);
    }
    ans = min(ans, min(dp[n-1][0], dp[n-1][1]));
    cost[n-2][0] = cost[n-2][1];
    base += d;
  }
  cout << ans << endl;
}