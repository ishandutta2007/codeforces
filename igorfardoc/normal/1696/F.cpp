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
const int maxn = 100;
vi a[maxn][maxn];
vi c[maxn][maxn];
vi b[maxn][maxn];
vi dst;
vvi g;
int n;

void dfs(int v, int p, int d) {
	dst[v] = d;
	for(int u : g[v]) {
		if(u == p) continue;
		dfs(u, v, d + 1);
	}
}

void calc_b() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			b[i][j].clear();
		}
	}
	for(int i = 0; i < n; i++) {
		dst.resize(n);
		dfs(i, -1, 0);
		for(int j = 0; j < n; j++) {
			for(int k = j + 1; k < n; k++) {
				if(dst[j] == dst[k]) {
					b[j][k].push_back(i);
					b[k][j].push_back(i);
				}
			}
		}
	}
}

void res_dfs(int v, int p) {
	if(p != -1) {
		cout << v + 1 << ' ' << p + 1 << '\n';
	}
	for(int u : g[v]) {
		if(u == p) continue;
		res_dfs(u, v);
	}
}

bool check() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i][j].size() != b[i][j].size()) return false;
			for(int k = 0; k < a[i][j].size(); k++) {
				if(a[i][j][k] != b[i][j][k]) return false;
			}
		}
	}
	return true;
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
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				a[i][j].clear();
				c[i][j].clear();
			}
		}
		for(int i = 0; i < n - 1; i++) {
			for(int j = 1; j < n - i; j++) {
				string s;
				cin >> s;
				for(int k = 0; k < n; k++) {
					if(s[k] == '1') {
						a[i][i + j].push_back(k);
						a[i + j][i].push_back(k);
						c[k][i].push_back(i + j);
						c[k][i + j].push_back(i);
					}
				}
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				sort(a[i][j].begin(), a[i][j].end());
			}
		}
		bool ans = false;
		for(int i = 1; i < n; i++) {
			g.assign(n, {});
			vi p(n, -1);
			p[i] = 0;
			p[0] = i;
			vi q;
			q.push_back(0);
			q.push_back(i);
			g[i].push_back(0);
			g[0].push_back(i);
			int sz = 2;
			bool ok = true;
			while(!q.empty()) {
				int v = q.back();
				q.pop_back();
				for(int u : c[v][p[v]]) {
					if(p[u] != -1) {
						ok = false;
						break;
					}
					p[u] = v;
					q.push_back(u);
					++sz;
					g[v].push_back(u);
					g[u].push_back(v);
				}
				if(!ok) break;
			}
			if(!ok || sz != n) continue;
			calc_b();
			if(check()) {
				cout << "Yes\n";
				ans = true;
				res_dfs(0, -1);
				break;
			}
		}
		if(!ans) {
			cout << "No\n";
		}

	}
}