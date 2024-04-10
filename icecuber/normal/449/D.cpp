#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int m = 20;
int dp[1<<m];
ll pow2[1<<m];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    dp[a]++;
  }
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < 1<<m; i++) {
      if (i>>j&1) {
	dp[i-(1<<j)] += dp[i];
      }
    }
  }
  ll mod = 1e9+7;
  pow2[0] = 1;
  for (int i = 0; i < n; i++)
    pow2[i+1] = pow2[i]*2%mod;
  ll ans = 0;
  for (int i = 0; i < 1<<m; i++) {
    (ans += pow2[dp[i]]*(__builtin_popcount(i)%2 ? -1 : 1)) %= mod;
  }
  cout << (ans+mod)%mod << endl;
}