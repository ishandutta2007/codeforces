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

const int N = 6e5 + 5, L = 21;

vector<tuple<int, int, int>> edges;

int n, q, nnode, wval[N];
int par[N], h[N];
int ord[N << 1], tin[N], timer;
vector<int> adj[N];

struct disjoint_set {
	disjoint_set() {
		iota(par, par + N, 0);
	}
	inline int find(int u) {
		return par[u] == u ? u : par[u] = find(par[u]);
	}
	inline void merge(int u, int v, int w) {
		if ((u = find(u)) == (v = find(v)))
			return ;

		wval[++ nnode] = w;

		adj[nnode].push_back(v);
		adj[nnode].push_back(u);
		par[v] = nnode;
		par[u] = nnode;

	}
} dsu;

namespace LCA {

int lg[N << 1];

template<class T, const T& merge(const T&, const T&)> struct rmq {
	vector<T> st[L];
	rmq () {}
	rmq (const vector<T> &a) {
		st[0] = a; int n = a.size(); __build__(n);
	}
	rmq (T * __first, T * __last) {
		st[0] = vector<T> (__first, __last);
		int n = __last - __first; __build__(n);
	}

	inline void __build__(int n) {
		for (int j = 1; 1 << j <= n; j++) {
			st[j].resize(n - (1 << j) + 1);
			for (int i = 0; i + (1 << j) <= n; i++)
				st[j][i] = merge(st[j - 1][i], st[j - 1][i + (1 << j - 1)]);
		}
	}

	inline T query(int l, int r) {
		int j = lg[r - l + 1];
		// return merge(st[j][l], st[j][r - (1 << j) + 1]); // 0 base
		return merge(st[j][l - 1], st[j][r - (1 << j)]); // 1 base
	}
};

const int& min_dep(const int& a, const int& b) {
	return h[a] < h[b] ? a : b;
}

rmq<int, min_dep> __lca;

inline void pre_dfs(int u, int p = 0) {
	h[u] = h[p] + 1;
	ord[tin[u] = ++ timer] = u;
	for (auto v : adj[u])
		pre_dfs(v, u), ord[++ timer] = u;
}

inline void __init__ () {
	pre_dfs(nnode);
	for (int i = 2; i <= timer; i++) lg[i] = lg[i >> 1] + 1;
	__lca = rmq<int, min_dep> (ord + 1, ord + timer + 1);
}

inline int lca(int u, int v) {
	if (!u || !v) return u ^ v;
	u = tin[u], v = tin[v];
	if (u > v) swap(u, v);
	return __lca.query(u, v);
}

}

#define tm (tl + tr >> 1)
#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

int cur_lca[N << 1], true_lca[N << 1], lz[N << 1];

void build(int id = 1, int tl = 1, int tr = n) {
	if (tl == tr)
		return true_lca[id] = tl, (void) 0;
	build(left), build(right);
	true_lca[id] = LCA::lca(true_lca[id << 1], true_lca[id << 1 | 1]);
}

inline void apply(int id, int v) {
	lz[id] = v, cur_lca[id] = v == 1 ? true_lca[id] : 0;
}

inline void push(int id) {
	if (lz[id]) apply(id << 1, lz[id]), apply(id << 1 | 1, lz[id]), lz[id] = 0;
}

void update(int l, int r, int v, int id = 1, int tl = 1, int tr = n) {
	if (l > tr || tl > r) return ;
	if (l <= tl && tr <= r)
		return apply(id, v);
	push(id), update(l, r, v, left), update(l, r, v, right);
	cur_lca[id] = LCA::lca(cur_lca[id << 1], cur_lca[id << 1 | 1]);
}

void Hollwo_Pelw() {
	cin >> n >> q, nnode = n;
	for (int i = 1, u, v, w; i < n; i++) {
		cin >> u >> v >> w;
		edges.emplace_back(w, u, v);
	}
	sort(edges.begin(), edges.end());
	for (auto [w, u, v] : edges)
		dsu.merge(u, v, w);

	LCA::__init__();
	build();

	for (int t, l, r, x; q --; ) {
		cin >> t;
		if (t == 3) {
			cin >> x;
			int y = cur_lca[1];
			if (y == 0 || y == x)
				cout << -1 << '\n';
			else
				cout << wval[LCA::lca(x, y)] << '\n';
		} else {
			cin >> l >> r;
			update(l, r, t);
		}
	}
}