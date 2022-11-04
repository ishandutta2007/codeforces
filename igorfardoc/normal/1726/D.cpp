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
vi ans;
vector<vector<pair<int, int>>> g;
vi used;
vi par;
vector<array<int, 3>> bad;

void dfs(int v, int p) {
	used[v] = 1;
	for(auto& u1 : g[v]) {
		int u = u1.first;
		int id = u1.second;
		if(u == p || used[u] == 2) continue;
		if(used[u] == 0) {
			par[u] = id;
			ans[id] = 1;
			dfs(u, v);
		} else {
			bad.push_back({v, u, id});
			ans[id] = 0;
		}
	}
	used[v] = 2;
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
		int n, m;
		cin >> n >> m;
		bad.clear();
		g.assign(n, {});
		used.assign(n, 0);
		ans.resize(m);
		par.resize(n);
		par[0] = -1;
		for(int i = 0; i < m; i++) {
			int v, u;
			cin >> v >> u;
			--v;
			--u;
			g[v].push_back({u, i});
			g[u].push_back({v, i});
		}
		dfs(0, -1);
		if(m == n + 2) {
			sort(bad.begin(), bad.end());
			do {
				if(bad[0][0] == bad[1][0] && bad[0][1] == bad[2][0] && bad[1][1] == bad[2][1]) {
					ans[par[bad[0][0]]] = 1 - ans[par[bad[0][0]]];
					ans[bad[0][2]] = 1 - ans[bad[0][2]];
					break;
				}
			} while(next_permutation(bad.begin(), bad.end()));
		}
		for(const auto& el : ans) {
			cout << el;
		}
		cout << '\n';
	}
}