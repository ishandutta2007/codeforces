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
bool ok;
vector<bool> tp;

bool dfs1(int v, int p) {
	int am0 = 0;
	int am1 = 0;
	for(int u : g[v]) {
		if(u == p) continue;
		bool val = dfs1(u, v);
		if(val) {
			++am1;
		} else {
			++am0;
		}
	}
	if(v == 0) {
		if(am0 - am1 > 1 || am0 - am1 < 0) ok = false;
	}
	if(am1 == am0 || am1 == am0 + 1) {
		tp[v] = false;
		return false;
	}
	if(am1 == am0 - 1 || am1 == am0 - 2) {
		tp[v] = true;
		return true;
	}
	ok = false;
	return false;
}

void solve(int v, int p) {
	vi am0;
	vi am1;
	for(const auto& u : g[v]) {
		if(u == p && p == -1) continue;
		int tp1 = tp[u];
		if(u == p) tp1 = tp[v];
		if(tp1) {
			am1.push_back(u);
		} else {
			am0.push_back(u);
		}
	}
	int now = 1 - g[v].size() % 2;
	for(int j = 0; j < g[v].size(); j++) {
		int curr;
		if(now == 0) {
			curr = am0.back();
			am0.pop_back();
		} else {
			curr = am1.back();
			am1.pop_back();
		}
		if(curr == p) {
			cout << p + 1 << ' ' << v + 1 << '\n';
		} else {
			solve(curr, v);
		}
		now = now ^ 1;
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
		tp.resize(n);
		for(int i = 0; i < n - 1; i++) {
			int v, u;
			cin >> v >> u;
			--v;
			--u;
			g[v].push_back(u);
			g[u].push_back(v);
		}
		ok = true;
		dfs1(0, -1);
		if(!ok) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		solve(0, -1);
	}
}