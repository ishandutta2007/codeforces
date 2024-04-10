#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9+7;
ll add(ll&a, ll b) {
  a += b;
  if (a >= mod)
    a -= mod;
}

ll dp[1001][10001];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    add(dp[i][5000],1);
    int a;
    cin >> a;
    for (int j = 0; j <= 10000; j++) {
     if (j+a <= 10000)
	add(dp[i+1][j+a], dp[i][j]);
      if (j-a >= 0)
	add(dp[i+1][j-a], dp[i][j]);
    }
    add(ans, dp[i+1][5000]);
  }
  cout << ans << endl;
}