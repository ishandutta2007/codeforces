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

const int N = 3e5 + 5;

int n, q, sz[N], sub[N], par[N], rev[N], pos[N], nnode;

struct fenwick_tree {
	vector<int64_t> bit;
	int M;

	inline void __init__(int _M) {
		bit.resize(++ _M), M = _M;
	}

	inline void add(int p, int64_t v) {
		for (; p < M; p += p & -p)
			bit[p] += v;
	}

	inline int64_t query(int p) {
		int64_t r = 0;
		for (; p > 0; p -= p & -p)
			r += bit[p];
		return r;
	}

	inline int64_t query(int l, int r) {
		return query(r) - query(l - 1);
	}
} all, node[N];

void Hollwo_Pelw() {
	cin >> n >> q;
	{
		int cp = ++ nnode;
		for (int i = 1; i <= n; i++) {
			char c; cin >> c;
			if (c == '(') {
				int np = ++ nnode;
				par[np] = cp;
				pos[np] = ++ sub[cp];
				rev[i] = cp = np;
			} else {
				if (cp == 1) continue;
				rev[i] = cp;
				cp = par[cp];
			}
		}
	}
	all.__init__(nnode);
	for (int i = 1; i <= nnode; i++) {
		node[i].__init__(sub[i]);
		all.add(i, 1ll * sub[i] * (sub[i] + 1) / 2);
	}

	fill(sz + 1, sz + nnode + 1, 1);
	for (int i = nnode; i > 1; i--)
		sz[par[i]] += sz[i];

	for (int t, l, r; q --; ) {
		cin >> t >> l >> r;
		if (t == 1) {
			int u = rev[l], p = par[u];
			node[p].add(pos[u], 1);
			all.add(p, - sub[p]), sub[p] --;
		} else {
			// from u -> v
			int u = rev[l], v = rev[r], p = par[u];
			int64_t res = all.query(u, v + sz[v] - 1);
			int left = pos[v] - pos[u] + 1 - node[p].query(pos[u], pos[v]);
			cout << (res + 1ll * left * (left + 1) / 2) << '\n';
		}
	}
}