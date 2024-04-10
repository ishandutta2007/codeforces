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
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 1e5 + 5;

int n, m, q, h[N], par[18][N];
bool vis[N];

vector<pair<int, int>> adj[N];
set<int> vers;

int64_t d[N], dist[45][N];

void dfs(int u, int p) {
	par[0][u] = p;
	for (int i = 1; i < 18; i++)
		par[i][u] = par[i - 1][par[i - 1][u]];
	vis[u] = 1;

	for (auto vw : adj[u]) {
		int v = vw.first, w = vw.second;
		if (!vis[v]) {
			h[v] = h[u] + 1;
			d[v] = d[u] + w;
			dfs(v, u);
		} else if (v != p) {
			vers.insert(v);
		}
	}
}

inline int lca(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	for (int i = 17; ~i; i--)
		if (h[v] - h[u] >> i & 1)
			v = par[i][v];
	if (u == v) return u;
	for (int i = 17; ~i; i--)
		if (par[i][u] ^ par[i][v])
			u = par[i][u], v = par[i][v];
	return par[0][u];
}

const int64_t inf = 1e18;

priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> pq;

void dijkstra(int s, int64_t *dst) {
	fill(dst + 1, dst + n + 1, inf);
	pq.emplace(dst[s] = 0, s);
	while (!pq.empty()) {
		int u = pq.top().second; int64_t d = pq.top().first; pq.pop();
		if (dst[u] != d) continue ;

		for (auto vw : adj[u]) {
			int v = vw.first, w = vw.second;
			if (dst[v] > d + w)
				pq.emplace(dst[v] = d + w, v);
		}
	}
}

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int u, v, w; m --; )
		cin >> u >> v >> w, adj[u].emplace_back(v, w), adj[v].emplace_back(u, w);
	dfs(1, 0);

	int cur = 0;
	for (auto v : vers)
		dijkstra(v, dist[++ cur]);

	cin >> q;
	for (int u, v; q --; ) {
		cin >> u >> v;
		int64_t res = d[u] + d[v] - 2 * d[lca(u, v)];
		for (int i = 1; i <= cur; i++)
			res = min(res, dist[i][u] + dist[i][v]);
		cout << res << '\n';
	}
}