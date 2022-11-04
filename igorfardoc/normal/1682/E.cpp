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
vector<bool> used;
vi order;

void dfs(int v) {
	used[v] = true;
	for(int u : g[v]) {
		if(used[u]) continue;
		dfs(u);
	}
	order.push_back(v);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n, m;
	cin >> n >> m;
	g.resize(m);
	vi a(n);
	vi c(n);
	vvi b(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		--a[i];
	}
	vector<bool> used1(n, false);
	int now = 0;
	for(int i = 0; i < n; i++) {
		if(used1[i]) continue;
		int v = i;
		while(!used1[v]) {
			b[now].push_back(v);
			c[v] = now;
			used1[v] = true;
			v = a[v];
		}
		++now;
	}
	vector<vector<pair<int, int>>> to(n);
	vector<vector<array<int, 3>>> arr(n);
	for(int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		--v;
		--u;
		to[v].push_back({u, i});
		to[u].push_back({v, i});
		arr[c[v]].push_back({min(v, u), max(v, u), i});
	}
	vi pos(n);
	for(int i = 0; i < n; i++) {
		if(b[i].empty()) continue;
		for(int j = 0; j < b[i].size(); j++) {
			pos[b[i][j]] = j;
		}
		for(const auto& el : b[i]) {
			sort(to[el].begin(), to[el].end(), [&](const pair<int, int>& a, const pair<int, int>& b) {if((pos[a.first] > pos[el]) ^ (pos[b.first] > pos[el])) return pos[a.first] > pos[b.first];  return pos[a.first] < pos[b.first];});
			for(int j = 0; j < (int)to[el].size() - 1; j++) {
				g[to[el][j].second].push_back(to[el][j + 1].second);
				//cout << to[el][j].second << ' ' << to[el][j + 1].second << endl;
			}
		}
	}
	used.assign(m, false);
	for(int i = 0; i < m; i++) {
		if(!used[i]) dfs(i);
	}
	reverse(order.begin(), order.end());
	for(const auto& el : order) {
		cout << el + 1 << ' ';
	}
}