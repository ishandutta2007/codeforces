#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<ll,ll>> a(n);
  for (int i = 0; i < n; i++) cin >> a[i].first;
  for (int i = 0; i < n; i++) cin >> a[i].second;
  sort(a.begin(), a.end());
  int cur = -1;
  vector<vector<pair<ll,ll>>> group = {};
  for (int i = 0; i < n; i++) {
    if (a[i].first >= cur) {
      group.push_back({});
      cur = a[i].first;
    }
    group.back().push_back(a[i]);
    cur++;
  }
  ll ans = 0;
  for (auto&v : group) {
    //for (auto [c,t] : v) cout << c << '/' << t << ' ';
    //cout << endl;
    int start = v[0].first;
    int len = v.size();
    sort(v.begin(), v.end(), [](pair<ll,ll> x, pair<ll,ll> y) {
	return make_pair(x.second, -x.first) > make_pair(y.second, -y.first);});
    set<int> left;
    for (int i = start; i < start+len; i++)
      left.insert(i);
    for (auto [c,t] : v) {
      auto it = left.lower_bound(c);
      ans += (*it-c)*t;
      left.erase(it);
    }
  }
  cout << ans << endl;
}