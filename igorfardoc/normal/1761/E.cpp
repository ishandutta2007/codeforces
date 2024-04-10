#include<bits/stdc++.h>
using namespace std;
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T, typename Cmp = less<T>> using ordered_set = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename Cmp = less_equal<T>> using ordered_multiset = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K, typename T, typename Cmp = less<K>> using ordered_map = tree<K, T, Cmp, rb_tree_tag,tree_order_statistics_node_update>;
// find_by_order(), order_of_key()
*/
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;

vvi g;
vvi all;
vi am;
vector<bool> used;

void dfs(int v) {
	used[v] = true;
	all.back().push_back(v);
	am.back() += g[v].size();
	for(int u : g[v]) {
		if(!used[u]) dfs(u);
	}
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		g.assign(n, {});
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				char c;
				cin >> c;
				if(c == '1') {
					g[i].push_back(j);
				}
			}
		}
		all.clear();
		am.clear();
		used.assign(n, false);
		for(int i = 0; i < n; i++) {
			if(!used[i]) {
				all.push_back({});
				am.push_back(0);
				dfs(i);
				am.back() /= 2;
			}
		}
		if(all.size() == 1) {
			cout << "0\n";
			continue;
		}
		bool ok = false;
		for(int i = 0; i < all.size(); i++) {
			int sz = all[i].size();
			if(sz * (sz - 1) / 2 != am[i]) {
				int mn = 100000;
				int mnid = -1;
				for(const auto& el : all[i]) {
					if(g[el].size() < mn) {
						mn = g[el].size();
						mnid = el;
					}
				}
				cout << "1\n";
				cout << mnid + 1 << '\n';
				ok = true;
				break;
			}
		}
		if(ok) continue;
		int mn = 100000;
		int mnid = -1;
		for(int i = 0; i < all.size(); i++) {
			if(all[i].size() < mn) {
				mn = all[i].size();
				mnid = i;
			}
		}
		if(all.size() == 2 || mn == 1) {
			cout << mn << '\n';
			for(const auto& el : all[mnid]) {
				cout << el + 1 << ' ';
			}
			cout << '\n';
			continue;
		}
		cout << "2\n";
		cout << all[0][0] + 1 << ' ' << all[1][0] + 1 << '\n';
	}
}