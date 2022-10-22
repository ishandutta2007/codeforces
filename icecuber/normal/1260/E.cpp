#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int l = 0;
  while (1<<l < n) l++;
  vector<ll> a(n);
  int f = -1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == -1) f = i;
  }
  assert(f != -1);
  for (int i = 0; i <= f; i++)
    a[i] = 0;

  vector<ll> dp(l+1,1e18);
  dp[0] = 0;
  for (int i = n-1; i; i--) {
    vector<ll> ndp(l+1,1e18);
    int slack = 0;
    for (int j = 0; j <= l; j++) {
      //Not bribe
      if (slack > n-i-1)
	ndp[j] = min(ndp[j], dp[j]);

      if (j == l) break;

      slack += (1<<l-j-1);

      //Bribe
      if (j+1 <= l && slack > n-i-1)
	ndp[j+1] = min(ndp[j+1], dp[j]+a[i]);

    }
    dp = ndp;
  }
  cout << dp[l] << endl;
}