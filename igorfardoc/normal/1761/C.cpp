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
int n;
vvi g;
vector<bool> used;
vvi ans;

void dfs(int v, int u1) {
	used[v] = true;
	ans[v].push_back(u1);
	for(int u : g[v]) {
		if(!used[u]) dfs(u, u1);
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
		cin >> n;
		g.assign(n, {});
		ans.assign(n, {});
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				char c;
				cin >> c;
				if(c == '1') {
					g[i].push_back(j);
				}
			}
		}
		for(int i = 0; i < n; i++) {
			used.assign(n, false);
			dfs(i, i);
		}
		for(const auto& el : ans) {
			cout << el.size() << ' ';
			for(const auto& el1 : el) {
				cout << el1 + 1 << ' ';
			}
			cout << '\n';
		}
	}
}