#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i], a[i] -= i;
  vector<int> b = a;
  sort(b.begin(), b.end());
  int m = unique(b.begin(), b.end())-b.begin();
  b.resize(m);
  vector<ll> dp(m,0);
  ll ans = 1e18;
  for (int i = 0; i < n; i++) {
    vector<ll> ndp = dp;
    ll pref_min = 1e18;
    for (int j = 0; j < m; j++) {
      pref_min = min(pref_min, dp[j]);
      ndp[j] = pref_min+abs(b[j]-a[i]);
      if (i == n-1) ans = min(ans, ndp[j]);
    }
    swap(dp,ndp);
  }
  cout << ans << endl;
}