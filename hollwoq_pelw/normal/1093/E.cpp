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

const int N = 2e5 + 5, M = N * 9;

int n, m, a[N], pa[N], b[N], pb[N], res[N];

struct query_t {
	int tp, x, y, v;
} query[M], tmp[M];

struct fenwick_tree {
	int bit[N], ver[N], vercnt;

	inline void update(int p, int v) {
		for (; p <= n; p += p & -p) {
			if (ver[p] ^ vercnt)
				ver[p] = vercnt, bit[p] = 0;
			bit[p] += v;
		}
	}

	inline int query(int p) {
		int r = 0;
		for (; p >  0; p -= p & -p) {
			if (ver[p] ^ vercnt)
				ver[p] = vercnt, bit[p] = 0;
			r += bit[p];
		}
		return r;
	}

	inline void clear() {
		++ vercnt;
	}
} bit;

int q, tot;

void solve_cdq(int l, int r) {
	if (l == r) return;

	int m = l + r >> 1;

	solve_cdq(l, m), solve_cdq(m + 1, r);

	int i = l, j = m + 1, k = l;

	while (i <= m && j <= r) {
		if (query[i].y <= query[j].y) {
			if (query[i].tp == 0) // update
				bit.update(query[i].x, query[i].v);
			tmp[k ++] = query[i ++];
		} else {
			if (query[j].tp != 0) // query
				res[query[j].tp] += query[j].v * bit.query(query[j].x);
			tmp[k ++] = query[j ++];
		}
	}

	while (i <= m) // no need update
		tmp[k ++] = query[i ++];

	while (j <= r) {
		if (query[j].tp != 0) // query
			res[query[j].tp] += query[j].v * bit.query(query[j].x);
		tmp[k ++] = query[j ++];
	}

	bit.clear();
	for (int x = l; x <= r; x++)
		query[x] = tmp[x];

}

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i], pa[a[i]] = i;
	for (int i = 1; i <= n; i++) cin >> b[i], pb[b[i]] = i;

	for (int i = 1; i <= n; i++)
		query[++ q] = {0, pa[i], pb[i], 1};
	
	for (int i = 1, op, la, ra, lb, rb, x, y; i <= m; i++) {
		cin >> op;
		if (op == 1) {
			cin >> la >> ra >> lb >> rb;
			++ tot, -- la, -- lb;
		
			if (ra && rb) query[++ q] = {tot, ra, rb, +1};
			if (la && rb) query[++ q] = {tot, la, rb, -1};
			if (ra && lb) query[++ q] = {tot, ra, lb, -1};
			if (la && lb) query[++ q] = {tot, la, lb, +1};
		
		} else {
			cin >> x >> y;
			
			query[++ q] = {0, pa[b[x]], x, -1};
			query[++ q] = {0, pa[b[y]], y, -1};
			
			swap(pb[b[x]], pb[b[y]]), swap(b[x], b[y]);

			query[++ q] = {0, pa[b[x]], x, +1};
			query[++ q] = {0, pa[b[y]], y, +1};
		
		}
	}

	solve_cdq(1, q);

	for (int i = 1; i <= tot; i++)
		cout << res[i] << '\n';
}