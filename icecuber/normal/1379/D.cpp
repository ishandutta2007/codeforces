#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, h, m, k;
  cin >> n >> h >> m >> k;
  m /= 2;
  vector<pair<ll,int>> a;
  for (int i = 0; i < n; i++) {
    ll hi, mi;
    cin >> hi >> mi;
    a.emplace_back(mi%m, i);
    a.emplace_back(mi%m+m, i);
  }
  sort(a.begin(), a.end());
  pair<ll,ll> ans = {1e9, -1};
  int j = 0;
  for (int i = 0; i < n*2; i++) {
    ll t = a[i].first;
    while (a[j].first <= t-k) j++;

    if (i >= n) {
      ans = min(ans, make_pair(ll(i-j), t%m));
    }
  }
  cout << ans.first << ' ' << ans.second << endl;
  for (int i = 0; i < n*2; i++) {
    ll t = a[i].first;
    ll r = ans.second+m, l = r-k;
    if (l < t && t < r)
      cout << a[i].second+1 << ' ';
  }
  cout << endl;
}