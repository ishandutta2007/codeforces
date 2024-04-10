#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
	ordered_set;
// find_by_order(size_t) -> iterator, order_of_key(val) -> size_t

ll tr(ll x) {
	return x*(x+1)/2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	map<int, vector<int>> mp;
	for (int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		mp[-y].push_back(x);
	}
	ordered_set os;
	ll sol = 0;
	for (auto& [y, vx] : mp) {
		sort(vx.begin(), vx.end());
		for (int x : vx)
			os.erase(x);
		for (int i=0; i<=(int)vx.size(); i++) {
			int b = 0;
			if (i == (int)vx.size()) {
				b = os.size() - os.order_of_key(vx[i-1]);
			} else if (i == 0) {
				b = os.order_of_key(vx[i]);
			} else {
				b = os.order_of_key(vx[i]) - os.order_of_key(vx[i-1]);
			}
			sol -= tr(b);
		}
		for (int x : vx)
			os.insert(x);
		sol += tr(os.size());
	}
	cout << sol << '\n';
}