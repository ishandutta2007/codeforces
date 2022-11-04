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

pair<int, int> dfs(int v) {
	if(g[v].empty()) return {1, 1};
	int mx = 0;
	int ans = 0;
	for(int u : g[v]) {
		auto res = dfs(u);
		mx = max(mx, res.second + 1);
		ans += res.first;
	}
	return {max(ans, mx), mx};
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	g.resize(n);
	for(int i = 0; i < n - 1; i++) {
		int p;
		cin >> p;
		g[p - 1].push_back(i + 1);
	}
	cout << dfs(0).first;
}