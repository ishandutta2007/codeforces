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

const int N = 2e5 + 5, M = 1e6 + 5, inf = 2e9;

int n, m;
 
struct disjoint_set_union {
	int par[N];
	disjoint_set_union () {
		iota(par, par + N, 0);
	}
	int find(int u){
		return par[u] = (par[u] == u ? u : find(par[u]));
	}

	bool merge(int u, int v){
		if ((u = find(u)) == (v = find(v)))
			return 0;
		return par[u] = v, 1;
	}
} dsu;
 
struct edge {
	int u, v, w, id;
	bool operator < (const edge & oth) const {
		return w < oth.w;
	}
};
 
vector<pair<int, int>> adj[N];
int par[N][19], mn[N][19];
int S[N], E[N], timer;
int sz[N], nxt[N];

void get_sz(int u, int p, int w){
	par[u][0] = p, mn[u][0] = w;
	for (int i = 1, v; i <= 18; i++){
		v = par[u][i - 1]; par[u][i] = par[v][i - 1];
		mn[u][i] = max(mn[v][i - 1], mn[u][i - 1]);
	}
	sz[u] = 1;
	nxt[u] = u;
	for (auto &v : adj[u]){
		if (v.first == p)
			swap(adj[u].back(), v);
		if (v.first == p) {
			adj[u].pop_back(); continue ;
		} 
		get_sz(v.first, u, v.second);
		sz[u] += sz[v.first];
		if (sz[v.first] > sz[adj[u][0].first])
			swap(adj[u][0], v);
	}
}
 
void dfs_hld(int u){
	S[u] = ++ timer;
	for (auto &v : adj[u]){
		if (v == adj[u][0])
			nxt[v.first] = nxt[u];
		dfs_hld(v.first);
	}
	E[u] = timer;
}
 
void init_hld(){
	get_sz(1, 1, -inf);
	dfs_hld(1);
}
 
bool is_ancestor(int u, int v){
	return S[u] <= S[v] && E[v] <= E[u];
}
 
int lca(int u, int v){
	if (is_ancestor(u, v))
		return u;
	if (is_ancestor(v, u))
		return v;
	for (int i = 18; i >= 0; i--){
		if (!is_ancestor(par[u][i], v))
			u = par[u][i];
	}
	return par[u][0];
}
 
int lift_val(int u, int p){
	if (u == p) return -inf;
	int res = -inf;
	for (int i = 18; i >= 0; i--){
		if (!is_ancestor(par[u][i], p)){
			res = max(res, mn[u][i]);
			u = par[u][i];
		}
	}
	return max(res, mn[u][0]);
}
 
int lift(int u, int p){
	for (int i = 18; i >= 0; i--)
		if (!is_ancestor(par[u][i], p))
			u = par[u][i];
	return u;
}

struct segment_tree {
	#define left id << 1, tl, tm
	#define right id << 1 | 1, tm + 1, tr
	int st[N << 2], lz[N << 2];
	segment_tree() {
	for (int i = 1; i < (N << 2); i++)
		st[i] = lz[i] = inf;
	}
	void apply(int id, int v) {
		lz[id] = min(lz[id], v), st[id] = min(st[id], v);
	}
	void push(int id){
		apply(id << 1, lz[id]);
		apply(id << 1 | 1, lz[id]);
	}
	void upd(int l, int r, int v, int id = 1, int tl = 1, int tr = n){
		if (l > r || l > tr || tl > r) return ;
		if (l <= tl && tr <= r) return apply(id, v);
		int tm = tl + tr >> 1; push(id);
		upd(l, r, v, left), upd(l, r, v, right);
		st[id] = min(st[id << 1], st[id << 1 | 1]);
	}
	int query(int p, int id = 1, int tl = 1, int tr = n){
		if (tl == tr) return st[id];
		int tm = tl + tr >> 1;
		push(id);
		if (p <= tm)
			return query(p, left);
		return query(p, right);
	}
} segtree;

void upd_path(int u, int p, int w){
	while (1) {
		if (nxt[u] == nxt[p])
			return segtree.upd(S[p], S[u], w);
		segtree.upd(S[nxt[u]], S[u], w);
		u = par[nxt[u]][0];
	}
}
 
int get_path(int u, int v, int w){
	int l = lca(u, v);
	if (l != u) upd_path(u, lift(u, l), w);
	if (l != v) upd_path(v, lift(v, l), w);
	return max(lift_val(u, l), lift_val(v, l));
}
 
int ans[N];

void Hollwo_Pelw() {
	cin >> n >> m;
	vector<edge> edges;
	for (int i = 1, u, v, w; i <= m; i++){
		cin >> u >> v >> w;
		edges.push_back({u, v, w, i});
	}
	sort(edges.begin(), edges.end());
	vector<edge> mst, query;
	for (auto ed : edges){
		int u = ed.u, v = ed.v, w = ed.w;
		if (dsu.merge(u, v)){
			adj[u].emplace_back(v, w);
			adj[v].emplace_back(u, w);
			mst.push_back(ed);
		}else{
			query.push_back(ed);
		}
	}
	init_hld();
	for (auto ed : query){
		ans[ed.id] = get_path(ed.u, ed.v, ed.w);
	}
	for (auto ed : mst){
		int u = ed.u, v = ed.v;
		if (par[v][0] == u)
			swap(u, v);
		ans[ed.id] = segtree.query(S[u]);
	}
	for (int i = 1; i <= m; i++)
		cout << (ans[i] == inf ? -1 : ans[i] - 1) << " ";
}