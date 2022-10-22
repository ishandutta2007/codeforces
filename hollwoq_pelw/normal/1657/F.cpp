#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

void Hollwo_Pelw();

signed main(){
#ifndef hollwo_pelw_local
	if (fopen("hollwo_pelw.inp", "r")){
		freopen("hollwo_pelw.inp", "r", stdin);
		freopen("hollwo_pelw.out", "w", stdout);
	}
#else
	auto start = chrono::steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << "\nExcution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

const int N = 4e5 + 5;

namespace two_sat {

vector<int> g0[N << 1], g1[N << 1], ord;
int n, res[N], vis[N << 1];

inline void add_clause(int i, bool f, int j, bool g) {
	// if (res[i] = f) then (res[j] = g)
	g0[i << 1 | f].push_back(j << 1 | g);
	g1[j << 1 | g].push_back(i << 1 | f);
}

void dfs0(int u) {
	vis[u] = 1;
	for (int v : g0[u])
		if (!vis[v]) dfs0(v);
	ord.push_back(u);
}

void dfs1(int u, int c) {
	vis[u] = c;
	for (int v : g1[u])
		if (!vis[v]) dfs1(v, c);
}

bool is_satisfied() {
	fill(vis, vis + (n << 1), 0);
	
	for (int i = 0; i < n << 1; i++)
		if (!vis[i]) dfs0(i);

	fill(vis, vis + (n << 1), 0);

	int cnt = 0;
	reverse(ord.begin(), ord.end());

	for (int u : ord)
		if (!vis[u]) dfs1(u, ++ cnt);

	// for (int i = 0; i < n; i++)
	// 	cout << vis[i << 1] << ' ' << vis[i << 1 | 1] << '\n';

	for (int i = 0; i < n; i++) {
		if (vis[i << 1] == vis[i << 1 | 1])
			return 0;
		res[i] = vis[i << 1] < vis[i << 1 | 1];
	}

	return 1;
}

} // namespace two_sat

int n, q, h[N], par[N], prv[N];
char choose[N][2];
string s[N];
vector<int> adj[N], path[N];

void pre_dfs(int u, int p) {
	h[u] = h[par[u] = p] + 1;

	for (int v : adj[u])
		if (v != p)
			pre_dfs(v, u);
}

void Hollwo_Pelw(){
	memset(prv, -1, sizeof prv);

	cin >> n >> q;
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	pre_dfs(1, 0);


	two_sat::n = q;

	for (int i = 0, u, v; i < q; i++) {
		cin >> u >> v >> s[i];
		path[i].resize(s[i].size());

		int l = 0, r = path[i].size();
		while (u != v) {
			if (h[u] >= h[v])
				path[i][l ++] = u, u = par[u];
			else
				path[i][-- r] = v, v = par[v];
		}
		path[i][l ++] = u;

		for (int j = 0; j < (int) s[i].size(); j++) {
			char c0 = s[i][j], c1 = s[i][(int) s[i].size() - j - 1];

			int p = path[i][j], k = prv[p];

			if (~k) {
				if (choose[p][0] != c0) {
					two_sat::add_clause(k, 0, i, 1);
					two_sat::add_clause(i, 0, k, 1);
				}
				if (choose[p][0] != c1) {
					two_sat::add_clause(k, 0, i, 0);
					two_sat::add_clause(i, 1, k, 1);
				}
				if (choose[p][1] != c0) {
					two_sat::add_clause(k, 1, i, 1);
					two_sat::add_clause(i, 0, k, 0);
				}
				if (choose[p][1] != c1) {
					two_sat::add_clause(k, 1, i, 0);
					two_sat::add_clause(i, 1, k, 0);
				}
			}

			prv[p] = i, choose[p][0] = c0, choose[p][1] = c1;

		}
	}

	if (!two_sat::is_satisfied())
		return cout << "NO\n", (void) 0;

	string res(n, 'a');

	for (int i = 0; i < q; i++) {
		if (two_sat::res[i])
			reverse(s[i].begin(), s[i].end());
		for (int j = 0; j < (int) s[i].size(); j++)
			res[path[i][j] - 1] = s[i][j];
	}

	cout << "YES\n" << res;
}