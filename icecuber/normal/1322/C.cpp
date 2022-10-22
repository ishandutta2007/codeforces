#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<ll> val(n);
    for (ll&v : val) cin >> v;
    vector<vector<int>> node(n);
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      node[a].push_back(b);
    }
    vector<set<int>> group = {{}};
    vector<int> at(n);
    for (int i = 0; i < n; i++) {
      group[0].insert(i);
      at[i] = 0;
    }

    for (int ai = 0; ai < n; ai++) {
      if (node[ai].empty()) continue;
      map<int,int> m;
      for (int bi : node[ai]) {
	int&x = m[at[bi]];
	if (!x) {
	  x = group.size();
	  group.push_back({});
	}
	group[at[bi]].erase(bi);
	at[bi] = x;
	group[at[bi]].insert(bi);
      }
    }
    ll ans = 0;
    group.erase(group.begin());
    for (auto&s : group) {
      ll sum = 0;
      for (int bi : s) sum += val[bi];
      //cout << sum << ' ';
      ans = __gcd(ans, sum);
    }
    cout << ans << '\n';
  }
}