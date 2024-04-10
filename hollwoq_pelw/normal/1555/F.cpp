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

const int N = 3e5 + 5, M = 5e5 + 5;

struct edge{
	int u, v, w, tp; // tp = add or not
} ed[M];

int n, m, par[N], d[N];

int find(int u) {
	return par[u] = (par[u] == u ? u : find(par[u]));
}

bool merge(int u, int v) {
	if ((u = find(u)) == (v = find(v)))
		return 0;
	return par[u] = v, 1;
}

vector<pair<int, int>> adj[N];

int sz[N], tin[N], nxt[N], timer;

void dfs(int u, int p) {
	par[u] = p, sz[u] = 1, nxt[u] = u;
	for (auto &vw : adj[u]) {
		if (vw.first == p) swap(vw, adj[u].back());
		if (vw.first == p) {
			adj[u].pop_back(); break ;
		}
		int v = vw.first, w = vw.second;
		d[v] = d[u] ^ w, dfs(v, u);

		if (sz[adj[u][0].first] < sz[v])
			swap(adj[u][0], vw);
	}
}

void dfs_hld(int u) {
	tin[u] = ++ timer;
	for (auto vw : adj[u]) {
		int v = vw.first, w = vw.second;
		if (vw == adj[u][0])
			nxt[v] = nxt[u];
		dfs_hld(v);
	}
}

int B1[N], B2[N];

inline void preadd(int *bit, int x, int v) {
	for (; x <= n; x += x & -x)
		bit[x] += v;
}

inline void add(int l, int r, int v) {
	preadd(B1, l, v);
	preadd(B1, r + 1, -v);
	preadd(B2, l, v * (l - 1));
	preadd(B2, r + 1, -v * r);
}

inline int sum(int *bit, int x) {
	int r = 0;
	for (; x; x -= x & -x)
		r += bit[x];
	return r;
}

inline int presum(int p) {
	return sum(B1, p) * p - sum(B2, p);
}

inline int sum(int l, int r) {
	return presum(r) - presum(l - 1);
}

void update(int u, int v) {
	while (1) {
		if (tin[u] > tin[v]) 
			swap(u, v);
		if (nxt[u] == nxt[v]) {
			add(tin[u] + 1, tin[v], 1);
			break ;
		}
		add(tin[nxt[v]], tin[v], 1);
		v = par[nxt[v]];
	}
}

int query(int u, int v) {
	int res = 0;
	while (1) {
		if (tin[u] > tin[v]) 
			swap(u, v);
		if (nxt[u] == nxt[v]) {
			res += sum(tin[u] + 1, tin[v]);
			break ;
		}
		res += sum(tin[nxt[v]], tin[v]);
		v = par[nxt[v]];
	}
	return res;
}

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) par[i] = i;
	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		ed[i] = {u, v, w, 0};
		if (merge(u, v)) {
			adj[u].emplace_back(v, w);
			adj[v].emplace_back(u, w);
			ed[i].tp = 1;
		}
	}

	
	for (int i = 1; i <= n; i++) 
		if (!tin[i]) dfs(i, 0), dfs_hld(i);

	for (int i = 1; i <= m; i++) if (!ed[i].tp) {
		int u = ed[i].u, v = ed[i].v;
		if (d[u] ^ d[v] ^ ed[i].w) {
			if (!query(u, v))
				ed[i].tp = 1, update(u, v);
		}
	}
	for (int i = 1; i <= m; i++)
		cout << (ed[i].tp ? "YES\n" : "NO\n");
}