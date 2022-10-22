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
	if (fopen("grapevine.inp", "r")){
		freopen("grapevine.inp", "r", stdin);
		freopen("grapevine.out", "w", stdout);
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

const int N = 1e5 + 5;

vector<pair<int, int>> adj[N];
int n, q, cpar[N], cdep[N], siz[N], mark[N];

struct segment_tree {
#define tm ((tl + tr) >> 1)
#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

	const long long inf = 1e18;

	vector<long long> st, lz, tg;
	int n = 0;

	void resize(int _n) {
		n = _n;
		st.resize(n << 2);
		lz.resize(n << 2);
		tg.assign(n << 2, inf);
	}

	inline void apply(int id, long long v) {
		if (tg[id] != inf)
			tg[id] += v;
		st[id] += v, lz[id] += v;
	}

	inline void push(int id) {
		if (lz[id]) apply(id << 1, lz[id]), apply(id << 1 | 1, lz[id]), lz[id] = 0;
	}

	void update(int l, int r, long long v, int id, int tl, int tr) {
		if (l > tr || tl > r) return ;
		if (l <= tl && tr <= r) return apply(id, v);
		push(id), update(l, r, v, left), update(l, r, v, right);
		st[id] = min(st[id << 1], st[id << 1 | 1]);
		tg[id] = min(tg[id << 1], tg[id << 1 | 1]);
	}

	inline void update(int l, int r, long long v) {
		update(l, r, v, 1, 1, n);
	}

	void toggle(int p, int id, int tl, int tr) {
		if (tl == tr) {
			tg[id] = tg[id] == inf ? st[id] : inf;
		} else {
			push(id);
			(p > tm ? toggle(p, right)
					: toggle(p, left));
			st[id] = min(st[id << 1], st[id << 1 | 1]);
			tg[id] = min(tg[id << 1], tg[id << 1 | 1]);
		}
	}

	inline void toggle(int p) {
		toggle(p, 1, 1, n);
	}

	long long query(int p, int id, int tl, int tr) {
		if (tl == tr)
			return st[id];
		push(id);
		return p > tm ? query(p, right) : query(p, left);
	}

	inline long long query(int p) {
		return query(p, 1, 1, n);
	}
};

#define for_cen(v, w, u) for (auto [v, w] : adj[u]) if (!mark[v])

inline long long comp(int u, int v) {
	return u < v ? 1ll * u * N + v : 1ll * v * N + u;
}
map<long long, int> edges;

int tin[18][N], tout[18][N];

struct LCA {
	int n, cdep, timer;

	segment_tree st;

	void pre_dfs(int u, int p) {
		tin[cdep][u] = ++ timer;
		for_cen(v, w, u) if (v != p) {
			pre_dfs(v, u);

			st.update(tin[cdep][v], tout[cdep][v], w);
		}

		tout[cdep][u] = timer;
	}

	inline void update(int u, int v, int w) {
		if (tin[cdep][u] > tin[cdep][v]) 
			swap(u, v);
		st.update(tin[cdep][v], tout[cdep][v], w);
	}

	inline void toggle(int u) {
		st.toggle(tin[cdep][u]);
	}

	inline long long query(int u) {
		return st.query(tin[cdep][u]) + st.tg[1];
	}

	void __init__(int _n, int _cdep, int r) {
		n = _n, cdep = _cdep, st.resize(n + 5);
		pre_dfs(r, 0), tout[cdep][0] = timer;
	}

} root[N];

inline int find_sz(int u, int p) {
	siz[u] = 1;
	for_cen(v, w, u) if (v != p)
		siz[u] += find_sz(v, u);
	return siz[u];
}

inline int find_cen(int u, int p, const int &tot) {
	for_cen(v, w, u) if (v != p)
		if (siz[v] > tot / 2) return find_cen(v, u, tot);
	return u;
}

void centroid_decomp(int r, int p) {
	int tot = find_sz(r, r);
	r = find_cen(r, r, tot);
	cdep[r] = cdep[cpar[r] = p] + 1;

	// cout << "root = " << r << '\n';
	root[r].__init__(tot, cdep[r], r);

	mark[r] = 1;
	for_cen(v, w, r)
		centroid_decomp(v, r);
}

void update(int u, int v, int w) {
	long long add = w - edges[comp(u, v)];
	edges[comp(u, v)] = w;

	if (cdep[u] > cdep[v])
		swap(u, v);
	for (int p = u; p; p = cpar[p])
		root[p].update(u, v, add);
}

void toggle(int u) {
	for (int p = u; p; p = cpar[p])
		root[p].toggle(u);
}

long long query(int u) {
	long long r = 1e18;
	for (int p = u; p; p = cpar[p])
		r = min(r, root[p].query(u));
	return r == 1e18 ? -1 : r;
}

void Hollwo_Pelw(){
	cin >> n >> q;
	for (int i = 1, u, v, w; i < n; i++) {
		cin >> u >> v, w = 1;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
		edges[comp(u, v)] = w;
	}

	centroid_decomp(1, 0);

	toggle(1);

	for (int t, u, v, w; q --; ) {
		cin >> t;
		if (t == 1) {
			cin >> u;
			toggle(u);
		}
		if (t == 2) {
			cin >> u;
			cout << query(u) << '\n';
		}
		if (t == 3) {
			cin >> u >> v >> w;
			update(u, v, w);
		}
	}
}