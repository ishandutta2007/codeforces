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
vi a;
vvi g;
vector<set<int>> s;
vi m;
int ans = 0;

void dfs(int v, int p) {
	bool ok = false;
	s[v].insert(a[v]);
	for(int u : g[v]) {
		if(u == p) continue;
		dfs(u, v);
		if(ok) {
			set<int> temp;
			swap(temp, s[u]);
			continue;
		}
		if(s[u].size() > s[v].size()) {
			swap(s[v], s[u]);
			swap(m[v], m[u]);
			m[v] ^= a[v];
			m[u] ^= a[v];
		}
		for(const auto& el : s[u]) {
			if(s[v].find(el ^ m[v] ^ m[u]) != s[v].end()) {
				//cout << v << ' ' << u << ' ' << m[v] << ' ' << m[u] << endl;
				ok = true;
				set<int> temp;
				swap(s[v], temp);
				++ans;
				break;
			}
		}
		if(!ok) {
			for(const auto& el : s[u]) {
				s[v].insert(el ^ m[v] ^ m[u] ^ a[v]);
			}
		}
		set<int> temp;
		swap(temp, s[u]);
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	cin >> n;
	a.resize(n);
	g.resize(n);
	s.resize(n);
	m.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n - 1; i++) {
		int v, u;
		cin >> v >> u;
		--v;
		--u;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(0, -1);
	cout << ans;
}