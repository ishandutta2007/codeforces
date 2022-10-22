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

map<pair<int, int>, int> edge_ids;

int n, siz[N], par[N];
vector<int> adj[N];

int nxt[N], tin[N], timer;

void pre_dfs(int u, int p = 0) {
	par[u] = p;
	siz[u] = 1;
	nxt[u] = u;
	for (int &v : adj[u]) {
		if (v == p) swap(v, adj[u].back());
		if (v == p)
			return adj[u].pop_back();
		pre_dfs(v, u);
		siz[u] += siz[v];

		if (siz[v] > siz[adj[u][0]])
			swap(v, adj[u][0]);
	}
}

void dfs_hld(int u) {
	tin[u] = ++ timer;
	for (int &v : adj[u]) {
		if (v == adj[u][0])
			nxt[v] = nxt[u];
		dfs_hld(v);
	}
}

struct node_t {
	long long sum; int cnt;
	node_t (long long _sum = 0, int _cnt = 0)
		: sum(_sum), cnt(_cnt) {}
	
	node_t operator - (const node_t &o) {
		return node_t(sum - o.sum, cnt - o.cnt);
	}

	node_t operator + (const node_t &o) {
		return node_t(sum + o.sum, cnt + o.cnt);
	}
	
} st[N << 2], st_full[N << 2], res;

int lz[N << 2];

#define tm (tl + tr >> 1)
#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

inline void apply(int id) {
	st[id] = st_full[id] - st[id], lz[id] ^= 1;
}

inline void push(int id) {
	if (lz[id])
		apply(id << 1), apply(id << 1 | 1), lz[id] = 0;
}

void update_set(int p, node_t v, int id = 1, int tl = 1, int tr = n) {
	if (tl == tr)
		return st[id] = st_full[id] = v, lz[id] = 0, (void) 0;

	push(id);
	(p > tm ? update_set(p, v, right)
			: update_set(p, v, left));
	
	st[id] = st[id << 1] + st[id << 1 | 1];
	st_full[id] = st_full[id << 1] + st_full[id << 1 | 1];
}

void update_flip(int l, int r, int id = 1, int tl = 1, int tr = n) {
	if (tl > r || l > tr) return ;
	if (l <= tl && tr <= r) return apply(id);
	
	push(id);
	update_flip(l, r, left), update_flip(l, r, right);

	st[id] = st[id << 1] + st[id << 1 | 1];
	st_full[id] = st_full[id << 1] + st_full[id << 1 | 1];	
}

node_t query(int l, int r, int id = 1, int tl = 1, int tr = n) {
	if (tl > r || l > tr) return node_t();
	if (l <= tl && tr <= r) return st[id];
	return push(id), query(l, r, left) + query(l, r, right);
}

void flip_path(int v) {
	while (nxt[v]) {
		update_flip(tin[nxt[v]], tin[v]);
		v = par[nxt[v]];
	}
}

node_t query_path(int v) {
	node_t res = node_t(0);

	while (nxt[v]) {
		res = res + query(tin[nxt[v]], tin[v]);
		v = par[nxt[v]];
	}

	return res;
}

int tot_cnt, active[N];

void do_active(int u, int id = 0) {
	if (int p = par[u]) {
		id = edge_ids[{p, u}];

		res = res - query_path(p);
		flip_path(p);
		res = res + query_path(p);
	}

	active[u] = 1, ++ tot_cnt;

	res = res + node_t(id, 1);
	update_set(tin[u], node_t(id, 1));
}

int used[N], edge_cnt;

void dfs_solve(int u) {
	if (!active[u]) return ;

	siz[u] = 1;

	for (int v : adj[u]) {
		dfs_solve(v);
		siz[u] += siz[v];
	}

	if (siz[u] & 1)
		used[edge_ids[{u, par[u]}]] = 1, ++ edge_cnt;
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edge_ids[{u, v}] = edge_ids[{v, u}] = i;
	}

	pre_dfs(1);
	dfs_hld(1);

	fill(siz + 1, siz + n + 1, 0);

	do_active(1);

	for (int tp, v; cin >> tp && tp != 3; ) {
		if (tp == 1) {

			cin >> v, do_active(v);

			cout << (res.cnt * 2 == tot_cnt ? res.sum : 0) << endl;

		} else {

			edge_cnt = 0;
			fill(used + 1, used + n + 1, 0);

			if (res.cnt * 2 == tot_cnt)
				dfs_solve(1);

			cout << edge_cnt << ' ';
			for (int i = 1; i < n; i++)
				if (used[i]) cout << i << ' ';
			cout << endl;
		}

	}
}