/*
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

void FAST_IO(string filein = "", string fileout = "", string fileerr = ""){
	if (fopen(filein.c_str(), "r")){
		freopen(filein.c_str(), "r", stdin);
		freopen(fileout.c_str(), "w", stdout);
#ifdef hollwo_pelw_local
		freopen(fileerr.c_str(), "w", stderr);
#endif
	}
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
#ifdef hollwo_pelw_local
	FAST_IO("input.inp", "output.out", "error.err");
	auto start = chrono::steady_clock::now();
#else
	FAST_IO("hollwo_pelw.inp", "hollwo_pelw.out");
#endif
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
	return 0;
}

const int N = 3e5 + 5;

int n, m, q, h[N], par[N], vis[N], val[N];
vector<int> adj[N];

void dfs(int u, int p) {
	vis[u] = 1;
	par[u] = p;
	
	for (int v : adj[u]) if (!vis[v]) {
		h[v] = h[u] + 1;
		dfs(v, u);
	}
}

int update(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	while (h[v] > h[u]) {
		val[v] ^= 1;
		v = par[v];
	}
	if (u == v) return u;
	while (u != v) {
		val[u] ^= 1;
		val[v] ^= 1;
		u = par[u];
		v = par[v];
	}
	return u;
}

void print(int u, int v, int l) {
	vector<int> a, b;
	while (u != l)
		a.push_back(u), u = par[u];
	while (v != l)
		b.push_back(v), v = par[v];
	reverse(b.begin(), b.end());

	cout << a.size() + b.size() + 1 << '\n';

	for (auto x : a) cout << x << ' ';
	cout << l << ' ';
	for (auto x : b) cout << x << ' ';
	cout << '\n';
}

int res, cnt[N];

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	cin >> q;
	
	vector<tuple<int, int, int>> query(q);
	for (auto &[u, v, w] : query) {
		cin >> u >> v;
		w = update(u, v);
	}

	for (int _ = 1; _ <= n; _++) if (val[_]) {
		cout << "NO\n";
		for (int i = 1; i <= n; i++)
			cnt[par[i]] += val[i];
		for (int i = 1; i <= n; i++) {
			res += cnt[i] / 2;
			if (!val[i])
				res += cnt[i] % 2;
		}
		cout << res;
		return ;
	}
	
	cout << "YES\n";
	for (auto [u, v, w] : query)
		print(u, v, w);
}