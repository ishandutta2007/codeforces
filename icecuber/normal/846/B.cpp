#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, k, m;
  cin >> n >> k >> m;
  vector<ll> a(k);
  for (ll&v : a) cin >> v;
  sort(a.begin(), a.end());
  a.push_back(0);
  k++;
  a.insert(a.begin(), 0);
  for (int i = 1; i <= k; i++)
    a[i] += a[i-1];

  vector<ll> dp((k+1)*n, 1e18);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    auto ndp = dp;
    for (int j = 0; j <= k; j++) {
      for (int l = dp.size()-1-j; l >= 0; l--)
	ndp[l+j] = min(ndp[l+j], dp[l]+a[j]);
    }
    dp = ndp;
  }
  cout << upper_bound(dp.begin(), dp.end(), m)-dp.begin()-1 << endl;
}