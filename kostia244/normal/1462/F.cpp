#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxn = 1<<18, mod = 1e9 + 7;
#include <bits/extc++.h> /** keep-include */
using namespace __gnu_pbds;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
    tree_order_statistics_node_update>;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;cin >> t;
	while(t--) {
		int n;
		Tree<pair<int, int>> en, st;
		cin >> n;
		vector<array<int, 2>> s(n);
		int x = 0;
		for(auto &[l, r] : s) {
			cin >> l >> r;
			en.insert({l, x++});
			st.insert({r, x++});
		}
		int ans = 0;
		for(auto &[l, r] : s) {
			int c = n;
			c -= st.order_of_key({l, -1});
			c -= en.size() - en.order_of_key({r, 1<<30});
			ans = max(ans, c);
		}
		cout << n-ans << '\n';
	}
}