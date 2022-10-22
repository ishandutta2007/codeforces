#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[5000], h[5000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  map<int,int> ma;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ma[a[i]];
  }
  int c = 0;
  for (auto&p : ma) h[c] = p.first, p.second = c++;

  vector<ll> dp(c,0);
  //dp[i][j] = minimum steps to fix until i, inclusive, if a[i] -> h[j]
  for (int i = 0; i < n; i++) {
    ll pref_min = i ? 1e18 : 0;
    vector<ll> ndp(c,0);
    for (int j = 0; j < c; j++) {
      pref_min = min(pref_min, dp[j]);
      ndp[j] = pref_min+abs(h[j]-a[i]);
    }
    swap(dp,ndp);
  }
  ll ans = 1e18;
  for (int j = 0; j < c; j++)
    ans = min(ans, dp[j]);
  cout << ans << endl;
}