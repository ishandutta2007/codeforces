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
vi a;
int k;
ll ans;

ll dfs(int v, int am) {
	vl all;
	ans += (ll)am * a[v];
	if(g[v].empty()) {
		return a[v];
	}
	for(int u : g[v]) {
		all.push_back(dfs(u, am / g[v].size()));
	}
	int extra = am % g[v].size();
	sort(all.rbegin(), all.rend());
	for(int i = 0; i < extra; i++) {
		ans += all[i];
	}
	return all[extra] + a[v];
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
		cin >> n >> k;
		g.assign(n, {});
		a.resize(n);
		for(int i = 0; i < n - 1; i++) {
			int p;
			cin >> p;
			--p;
			g[p].push_back(i + 1);
		}
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		ans = 0;
		dfs(0, k);
		cout << ans << '\n';
	}
}