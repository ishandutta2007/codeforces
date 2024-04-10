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
const int maxn = 2000;
ll a[maxn][maxn];

vector<vector<pair<int, int>>> g;


bool first_good(int v1, int v2, int check) {
	ll fir = a[v1][check];
	ll sec = a[v2][check];
	return fir > sec;
}

int dfs(int v, int check) {
	if(g[v].empty()) return v;
	for(auto& u1 : g[v]) {
		int u = u1.first;
		if(first_good(u, v, check)) return dfs(u, check);
	}
	return v;
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
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			cin >> a[i][j];
			a[j][i] = a[i][j];
		}
	}
	vector<pair<ll, int>> all;
	for(int i = 1; i < n; i++) {
		all.push_back({a[0][i], i});
	}
	sort(all.rbegin(), all.rend());
	for(const auto& el : all) {
		int i = el.second;
		int j = dfs(0, i);
		ll sum = a[j][j];
		ll ii = a[i][i] - sum;
		ll ij = a[i][j] - sum;
		ii -= 2 * ij;
		ll rs = ii / n;
		g[j].push_back({i, rs});
		cout << i + 1 << ' ' << j + 1 << ' ' << rs << '\n';
	}
}