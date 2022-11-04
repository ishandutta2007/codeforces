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
const int inf = 1000000000;
int dst[500][500];

int n, m;
void bfs(vector<vector<pair<int, int>>>& g, int v) {
	for(int i = 0; i < n; i++) {
		dst[v][i] = inf;
	}
	dst[v][v] = 0;
	queue<int> q;
	q.push(v);
	while(!q.empty()) {
		int v1 = q.front();
		q.pop();
		for(auto& u1 : g[v1]) {
			int u = u1.first;
			if(dst[v][u] == inf) {
				dst[v][u] = dst[v][v1] + 1;
				q.push(u);
			}
		}
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
		cin >> n >> m;
		vector<vector<pair<int, int>>> g(n);
		for(int i = 0; i < m; i++) {
			int v, u, w;
			cin >> v >> u >> w;
			--v;
			--u;
			g[v].push_back({u, w});
			g[u].push_back({v, w});
		}
		for(int i = 0; i < n; i++) {
			bfs(g, i);
		}
		ll ans = (ll)inf * inf;
		for(int v = 0; v < n; v++) {
			for(auto& u1 : g[v]) {
				int u = u1.first;
				int w = u1.second;
				int mn = min(dst[0][v] + dst[n - 1][u], dst[0][u] + dst[n - 1][v]);
				for(int i = 0; i < n; i++) {
					mn = min(mn, min(dst[i][v], dst[i][u]) + 1 + dst[0][i] + dst[i][n - 1]);
				}
				mn++;
				ans = min(ans, (ll)mn * w);
			}
		}
		cout << ans << '\n';
	}
}