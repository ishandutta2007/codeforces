#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, x;
  cin >> n >> x;
  vector<ll> dp(5,0);
  x--;
  ll acc = 0;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    acc += a;
    dp[1] = max(dp[1], dp[0]-acc);
    dp[2] = max(dp[2], dp[1]-x*acc);
    dp[3] = max(dp[3], dp[2]+x*acc);
    dp[4] = max(dp[4], dp[3]+acc);
  }
  cout << dp[4] << endl;
}