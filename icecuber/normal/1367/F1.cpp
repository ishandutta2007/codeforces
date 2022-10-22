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
    map<int,vector<int>> m;
    vector<int> rev;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      m[a].push_back(i);
      rev.push_back(a);
    }
    sort(rev.begin(), rev.end());
    rev.resize(unique(rev.begin(), rev.end())-rev.begin());
    reverse(rev.begin(), rev.end());

    int ans = n;
    map<int,int> good;
    for (int a : rev) {
      auto&v = m[a];
      good[a] = v.size();
      int last = v.back();
      auto it = m.upper_bound(a);
      if (it == m.end()) continue;
      if (it->second[0] > last) {
	good[a] = v.size()+good[it->first];
      } else {
	int extra = it->second.end()-lower_bound(it->second.begin(), it->second.end(), last);
	good[a] = v.size()+extra;
      }

      int base = lower_bound(v.begin(), v.end(), it->second[0])-v.begin();
      ans = min(ans, n-(base+good[it->first]));
    }
    for (auto [a, g] : good)
      ans = min(ans, n-g);
    cout << ans << endl;
  }
}