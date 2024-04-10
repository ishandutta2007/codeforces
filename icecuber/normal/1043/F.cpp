#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int m = 300001;
ll mod = 1e9+7;

ll in[m];
int mu[m];
int isprime[m];
ll dp[m];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    for (int i = 1; i*i <= a; i++) {
      if (a%i==0) {
	in[i]++;
	if (i*i != a) in[a/i]++;
      }
    }
  }
  for (int i = 1; i < m; i++)
    mu[i] = 1;
  for (int i = 2; i < m; i++)
    isprime[i] = 1;
  for (int i = 2; i < m; i++) {
    if (!isprime[i]) continue;
    for (int j = i; j < m; j += i)
      isprime[j] = 0, mu[j] *= -1;
    if (1ll*i*i < m)
      for (int j = i*i; j < m; j += i*i)
	mu[j] = 0;
  }
  for (int i = 0; i < m; i++)
    dp[i] = in[i];

  int ans = 1;
  while (ans < 10) {
    ll ones = 0;
    for (int i = 0; i < m; i++)
      (ones += mu[i]*dp[i]) %= mod;
    if (ones) {
      cout << ans << endl;
      return 0;
    }

    for (int i = 0; i < m; i++)
      dp[i] = dp[i]*in[i]%mod;
    ans++;
  }
  cout << -1 << endl;
}