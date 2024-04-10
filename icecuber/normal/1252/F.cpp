#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++) {
      int m, p;
      cin >> m >> p;
      v.emplace_back(m,p);
    }
    sort(v.begin(), v.end());
    int taken = 0;
    multiset<int> cands;
    ll ans = 0;
    for (int i = n-1; i >= 0; i--) {
      cands.insert(v[i].second);
      if (i && v[i-1].first == v[i].first) continue;
      int need = v[i].first-i;
      while (need > taken) {
	assert(cands.size());
	ans += *cands.begin();
	cands.erase(cands.begin());
	taken++;
      }
    }
    cout << ans << '\n';
  }
}