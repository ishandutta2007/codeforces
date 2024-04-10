#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<ll> a(n);
  for (ll&v : a) cin >> v;
  sort(a.begin(), a.end());
  vector<ll> acc(n+1,0);
  for (int i = 1; i <= n; i++)
    acc[i] = acc[i-1]+a[i-1];

  vector<int> offer(k+1,0);
  while (m--) {
    int x, y;
    cin >> x >> y;
    if (x <= k)
      offer[x] = max(offer[x], y);
  }

  vector<ll> dp(k+1,1e18);
  dp[0] = 0;
  for (int j = 1; j <= k; j++)
    for (int i = 1; i <= j; i++)
      dp[j] = min(dp[j], dp[j-i]+acc[j]-acc[j-i+offer[i]]);
  cout << dp[k] << endl;
}