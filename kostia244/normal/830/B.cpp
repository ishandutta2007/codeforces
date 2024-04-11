#pragma GCC optimize("trapv")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define pcnt(x) __builtin_popcount(x)
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 1e5 + 3, mod = 1e9 + 7;
#include <ext/pb_ds/assoc_container.hpp> 
#define left xjfaesjf
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int n;
ordered_set left;
multiset<int> values;
set<int> pos[maxn];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		left.insert(i);
		values.insert(t);
		pos[t].insert(i);
	}
	ll ans = 0, idx = 0;
	for(int i = n; i; i--) {
		int cur = *values.begin();
		values.erase(values.begin());
		auto it = pos[cur].lower_bound(idx);
		if(it==pos[cur].end()) {
			it = pos[cur].begin();
		}
		int t = left.order_of_key(*it) - left.order_of_key(idx);
		if(t<0) t += (int)left.size();
		ans += t;
		idx = *it;
		pos[cur].erase(it);
		left.erase(idx);
	}
	cout << ans+n;
}