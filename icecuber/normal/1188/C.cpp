#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[1001][1001];
ll mod = 998244353;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, K;
  cin >> n >> K;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  sort(a.begin(), a.end());
  int m = 100000/(K-1)+2;
  ll ans = 0;
  for (int d = 1; d < m; d++) {
    for (int i = 0; i <= n; i++) dp[0][i] = 1;
    for (int k = 1; k <= K; k++) {
      int j = 0;
      for (int i = 1; i <= n; i++) {
	while (a[i-1]-a[j] >= d) j++;
	dp[k][i] = (dp[k][i-1]+dp[k-1][j])%mod;
      }
    }
    ans += dp[K][n];
  }
  cout << (ans%mod+mod)%mod << endl;
}