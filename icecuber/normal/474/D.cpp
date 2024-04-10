#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[100001], dp2[100001];
ll mod = 1e9+7;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t, k;
  cin >> t >> k;
  dp[0] = 1;
  dp2[0] = 1;
  for (int i = 1; i <= 100000; i++) {
    dp[i] = (dp[i-1]+(i>=k ? dp[i-k] : 0))%mod;
    dp2[i] = (dp2[i-1]+dp[i])%mod;
  }
  while (t--) {
    int a, b;
    cin >> a >> b;
    ll ans = dp2[b]-dp2[a-1];
    cout << (ans%mod+mod)%mod << endl;
  }

}