#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    map<int,vector<int>> pos;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      pos[a[i]].push_back(i);
    }
    vector<int> reach(n);
    for (int i = 0; i < n; i++) reach[i] = i;
    for (int i = 0; i < m; i++) {
      int l, r;
      cin >> l >> r;
      l--, r--;
      reach[r] = min(reach[r], l);
    }
    for (int i = n-2; i >= 0; i--) {
      reach[i] = min(reach[i], reach[i+1]);
    }
    vector<int> orig(n);
    for (int i = 0; i < n; i++) orig[i] = i;
    vector<array<int,2>> pa;
    for (int i = 0; i < n; i++) {
      const vector<int>&v = pos[a[i]];
      int j = lower_bound(v.begin(),v.end(), i)-v.begin();
      if (j && v[j-1] >= reach[i]) {
        int l = lower_bound(v.begin(),v.end(), reach[i])-v.begin();
        pa.push_back({v[l],i});
        if (j-l > 1) {
          pa.push_back({v[l+1],v[l+1]});
          pa.push_back({v[j-1],v[j-1]});
        }
      }
    }
    vector<vector<array<int,2>>> ind(n);
    for (int i = 0; i < (int)pa.size(); i++) {
      auto [l,r] = pa[i];
      ind[l].push_back({i,0});
      ind[r].push_back({i,1});
    }
    if (pa.empty()) {
      cout << 0 << endl;
      continue;
    }
    int ans = 1e9;
    multiset<int> active;
    for (int i = 0; i < n; i++) {
      for (auto [j,t] : ind[i]) {
        if (t == 1) {
          assert(active.count(pa[j][0]));
          active.erase(active.find(pa[j][0]));
        }
        active.insert(i);
      }
      if (active.size() == pa.size()) ans = min(ans, i+1-*active.begin());
    }
    cout << ans << endl;
  }
}