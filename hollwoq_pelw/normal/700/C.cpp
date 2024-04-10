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

const int N = 1005, M = 30005, inf = 2e9 + 7;

int n, m, s, t, tin[N], low[N], timer;

struct edge {
	union { int u; int id; };
	int v, w;
} edges[M];

vector<edge> adj[N];

int vis[N], pre[N];

bool find_path(int u) {
	if (u == t) return 1;
	vis[u] = 1;
	for (auto ed : adj[u]) if (!vis[ed.v]) {
		pre[ed.v] = ed.id;
		if (find_path(ed.v))
			return 1;
	}
	return 0;
}

int res = inf, bi, bj, blk1, blk2;

bool tarjan(int u, int id) {
	tin[u] = low[u] = ++ timer;
	bool ok = u == t;
	for (auto ed : adj[u]) if (ed.id != blk1 && ed.id != id) {
		if (tin[ed.v]) {
			low[u] = min(low[u], tin[ed.v]);
		} else {
			bool chk = tarjan(ed.v, ed.id);
			low[u] = min(low[u], low[ed.v]);

			if (chk && low[ed.v] > tin[u]) {
				if (blk2 == 0 || edges[blk2].w > ed.w) blk2 = ed.id;
			}
			ok |= chk;
		}
	}
	return ok;
}

void solve() {
	memset(tin, 0, sizeof tin);
	memset(low, 0, sizeof low);
	timer = 0, blk2 = 0;
	if (tarjan(s, -1)) {
		if (!blk2) return ;
		// cout << blk1 << ' ' << blk2 << '\n';
		int cur = edges[blk1].w + edges[blk2].w;
		if (res > cur) bi = blk1, bj = blk2, res = cur;
	} else {
		// cout << blk1 << ' ' << blk2 << '\n';
		int cur = edges[blk1].w;
		if (res > cur) bi = blk1, bj = blk2, res = cur;
	}
}

void Hollwo_Pelw() {
	cin >> n >> m >> s >> t;

	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w, edges[i] = {u, v, w};
		adj[u].push_back({i, v, w}), adj[v].push_back({i, u, w});
	}

	if (!find_path(s))
		return cout << "0\n0\n", (void) 0;

	for (int x = t; x != s; ) {
		blk1 = pre[x], solve();
		x ^= edges[blk1].u ^ edges[blk1].v;
	}

	if (res == inf)
		return cout << "-1", (void) 0;

	cout << res << '\n' << (bi != 0) + (bj != 0) << '\n';
	if (bi) cout << bi << ' ';
	if (bj) cout << bj << ' ';
}