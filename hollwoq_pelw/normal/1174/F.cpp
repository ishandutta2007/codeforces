/* 
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include<bits/stdc++.h>
using namespace std;

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
	FAST_IO(".inp", ".out");
#endif
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

#define int long long

const int N = 2e5 + 5;

int n, sz[N], dep[N], par[N];
vector<int> adj[N];
bool mark[N];

void pre_dfs(int u, int p) {
	for (auto v : adj[u]) if (v != p) {
		par[v] = u, dep[v] = dep[u] + 1;
		pre_dfs(v, u);
	}
}

int query(char c, int u) {
	cout << c << ' ' << u << endl;
	int res; cin >> res; return res;
}

int find_sz(int u, int p) {
	sz[u] = 1;
	for (auto v : adj[u]) if (v != p && !mark[v])
		sz[u] += find_sz(v, u);
	return sz[u];
}

int find_cen(int u, int p, int tot) {
	for (auto v : adj[u]) if (v != p && !mark[v])
		if (sz[v] > tot / 2) return find_cen(v, u, tot);
	return u;
}

int curdep;

int solve(int r) {
	int tot = find_sz(r, r);
	r = find_cen(r, r, tot);

	int d = query('d', r);
	if (!d) return r;

	mark[r] = 1;

	if (dep[r] + d == curdep)
		return solve(query('s', r));
	return solve(par[r]);

}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
	curdep = query('d', 1);
	pre_dfs(1, 1);
	int res = solve(1);
	cout << "! " << res << endl;
}