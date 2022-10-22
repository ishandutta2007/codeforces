#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll a, b;
  cin >> a >> b;
  ll sum = a+b;
  vector<pair<ll,ll>> rec;
  for (ll i = 1; i*i <= sum; i++) {
    if (sum%i) continue;
    rec.push_back({sum/i,i});
    //cout << i << ' ' << sum/i << endl;
  }
  reverse(rec.begin(), rec.end());
  ll ans = 1e18;
  for (ll i = 1; i*i <= a; i++) {
    if (a%i) continue;
    auto p = *lower_bound(rec.begin(), rec.end(), make_pair(a/i,i));
    if (p.second >= i)
      ans = min(ans, (p.first+p.second)*2);
  }
  for (ll i = 1; i*i <= b; i++) {
    if (b%i) continue;
    auto p = *lower_bound(rec.begin(), rec.end(), make_pair(b/i,i));
    if (p.second >= i)
      ans = min(ans, (p.first+p.second)*2);
  }
  cout << ans << endl;
}