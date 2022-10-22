#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#include <bits/extc++.h>
using namespace __gnu_pbds;
template<class T>
using os_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T, class S>
using os_map = tree<T, S, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int,int>> range;
    for (int i = 0; i < n; i++) {
      int l, r;
      cin >> l >> r;
      range.emplace_back(l, r);
    }
    sort(range.begin(), range.end());

    os_map<int,int> st;
    auto insert = [&](int l, int r) {
      if (st.size()) {
	auto it = st.upper_bound(r);
	vector<int> toerase;
	while (it != st.begin()) {
	  --it;
	  if (it->second < l) break;
	  l = min(l, it->first);
	  r = max(r, it->second);
	  toerase.push_back(it->first);
	}
	for (int l_ : toerase)
	  st.erase(l_);
      }
      st[l] = r;
    };
    vector<int> cnt = {0}, reach = {-(int)2e9};
    for (auto [l,r] : range) {
      insert(l, r);
      cnt.push_back(st.size());
      reach.push_back(st.rbegin()->second);
    }
    int ans = cnt[n-1];
    st.clear();
    for (int i = n-1; i > 0; i--) {
      auto [l,r] = range[i];
      insert(l, r);
      int score = cnt[i-1] + (int)st.size() - st.order_of_key(reach[i-1]+1);
      ans = max(ans, score);
    }
    cout << ans << endl;
  }
}