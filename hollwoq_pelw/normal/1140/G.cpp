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

#define min __min__
inline long long min(long long a, long long b) { return a < b ? a : b; }

const int N = 3e5 + 5;

struct edge {
	int v; long long w[2];
	edge (int _v, long long _w1, long long _w2) 
		: v(_v) { w[0] = _w1, w[1] = _w2; }
};

struct matrix {
	long long a[2][2];

	matrix () {
		memset(a, 0, sizeof a);
	}

	long long* operator [] (int x) {return a[x];}
	const long long* operator [] (int x) const {return a[x];}

	friend matrix operator + (const matrix &a, const matrix &b) {
		matrix r;
		for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++)
			r[i][j] = min(a[i][0] + b[0][j], a[i][1] + b[1][j]);
		return r;
	}
} spr[N][19];

int n, h[N], par[N][19];
vector<edge> adj[N];

long long dist[N], x;
priority_queue<pair<long long, int>> pq;

void precalc_dist() {
	long long d; int u;
	while (!pq.empty()) {
		d = pq.top().first, u = pq.top().second, pq.pop();
		if (d != -dist[u]) continue ;
		for (auto ed : adj[u]) {
			long long nd = -d + ed.w[0] + ed.w[1];
			if (dist[ed.v] > nd)
				pq.emplace(- (dist[ed.v] = nd), ed.v);
		}
	}
}

void dfs(int u, int p) {
	h[u] = h[par[u][0] = p] + 1;
	for (int i = 1, v; i <= 18; i++) {
		par[u][i] = par[v = par[u][i - 1]][i - 1];
		spr[u][i] = spr[u][i - 1] + spr[v][i - 1];
	}

	for (auto ed : adj[u]) if (ed.v != p) {
		matrix &r = spr[ed.v][0];
		r[0][0] = min(ed.w[0], ed.w[1] + dist[ed.v] + dist[u]);
		r[0][1] = min(ed.w[0] + dist[u], ed.w[1] + dist[ed.v]);
		r[1][0] = min(ed.w[1] + dist[u], ed.w[0] + dist[ed.v]);
		r[1][1] = min(ed.w[1], ed.w[0] + dist[ed.v] + dist[u]);
		dfs(ed.v, u);
	}
}

inline int get_lca(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	for (int i = 18; ~i; i--)
		if (h[v] - h[u] >> i & 1) v = par[v][i];
	if (u == v) return u;
	for (int i = 18; ~i; i--)
		if (par[u][i] ^ par[v][i])
			u = par[u][i], v = par[v][i];
	return par[u][0];
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> x, pq.emplace(- (dist[i] = x), i);
	for (int i = 1; i < n; i++) {
		int u, v; long long w1, w2; cin >> u >> v >> w1 >> w2;
		adj[u].emplace_back(v, w1, w2), adj[v].emplace_back(u, w1, w2);
	}
	precalc_dist(), dfs(1, 0);
	
	int q; cin >> q;
	for (int x, y, u, v, lca; q --; ) {
		cin >> x >> y, u = x + 1 >> 1, v = y + 1 >> 1;
		lca = get_lca(u, v);
		matrix res1, res2;
		res1[0][1] = res1[1][0] = dist[u];
		res2[0][1] = res2[1][0] = dist[v];
		for (int i = 18; ~i; i--)
			if (h[u] - h[lca] >> i & 1) res1 = res1 + spr[u][i], u = par[u][i];
		for (int i = 18; ~i; i--)
			if (h[v] - h[lca] >> i & 1) res2 = res2 + spr[v][i], v = par[v][i];
		// x -> 0, 1 // y -> 0, 1 => reverse 0, 1 -> y
		swap(res2[1][0], res2[0][1]);
		cout << (res1 + res2)[x & 1 ^ 1][y & 1 ^ 1] << '\n';
	}
}