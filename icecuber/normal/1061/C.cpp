#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9+7;
int a[100000];
ll dp[100001];
int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    vector<int> d0, d1;
    for (int j = 1; j*j <= a[i]; j++) {
      if (a[i]%j == 0) {
	d0.push_back(j);
	if (j*j != a[i])
	  d1.push_back(a[i]/j);
      }
    }
    for (int d : d1) {
      if (d <= 100000)
	(dp[d] += dp[d-1]) %= mod;
    }
    reverse(d0.begin(), d0.end());
    for (int d : d0) {
      if (d <= 100000)
	(dp[d] += dp[d-1]) %= mod;
    }
  }
  ll sum = 0;
  for (int i = 1; i <= 100000; i++)
    sum = (sum+dp[i])%mod;
  cout << sum << endl;
}