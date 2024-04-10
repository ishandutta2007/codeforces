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

const int N = 2e5 + 5;

int n, m, comp[N], cc, q;
vector<pair<int, int>> adj[N], radj[N];

vector<int> ord, cur;
int64_t dist[N], rdist[N], g[N];

void dfs_ord(int u) {
	comp[u] = 1;
	for (auto [v, w] : adj[u])
		if (!comp[v]) dfs_ord(v);
	ord.push_back(u);
}

void dfs_rev(int u) {
	comp[u] = cc;
	cur.push_back(u);
	for (auto [v, w] : radj[u])
		if (!comp[v]) dfs_rev(v);
}

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int a, b, l; m --; )
		cin >> a >> b >> l, adj[a].emplace_back(b, l), radj[b].emplace_back(a, l);
	for (int i = 1; i <= n; i++)
		if (!comp[i]) dfs_ord(i);
	reverse(ord.begin(), ord.end());
	
	fill(dist + 1, dist + n + 1, -1);
	fill(rdist + 1, rdist + n + 1, -1);
	fill(comp + 1, comp + n + 1, 0);

	for (auto r : ord) if (!comp[r]) {
		++ cc, dfs_rev(r);
		queue<int> q;
		{
			dist[r] = 0, q.push(r);
			while (!q.empty()) {
				int u = q.front(); q.pop();
				for (auto [v, w] : adj[u]) {
					if (dist[v] == -1 && comp[v] == cc)
						dist[v] = dist[u] + w, q.push(v);
				}
			}
		}
		{
			rdist[r] = 0, q.push(r);
			while (!q.empty()) {
				int u = q.front(); q.pop();
				for (auto [v, w] : radj[u]) {
					if (rdist[v] == -1 && comp[v] == cc)
						rdist[v] = rdist[u] + w, q.push(v);
				}
			}
		}

		// cout << "cur comp = " << cc << '\n';
		// for (auto u : cur)
		// 	cout << u << ' ' << dist[u] << ' ' << rdist[u] << '\n';

		for (int u : cur) for (auto [v, w] : adj[u])
			if (comp[v] == cc) g[cc] = __gcd(g[cc], dist[u] + rdist[v] + w);
		cur.clear();
	}

	cin >> q;
	for (int u, s, t; q --; ) {
		cin >> u >> s >> t;
		int64_t gg = g[comp[u]];
		if (gg == 0) {
			cout << (s == 0 ? "YES\n" : "NO\n");
		} else {
			cout << (s % __gcd(gg, (int64_t) t) ? "NO\n" : "YES\n");
		}
	}
}