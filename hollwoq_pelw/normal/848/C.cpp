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

const int N = 1e5 + 5, M = 7e5 + 5;

struct query_t {
	int tp, l, r, v;
	query_t (int _tp = 0, int _l = 0, int _r = 0, int _v = 0)
		: tp(_tp), l(_l), r(_r), v(_v) {}
} query[M], tmp[M];

int n, m, q, qans, a[N];
set<int> pos[N];

struct fenwick_tree {
	int64_t bit[N];
	int ver[N], vercnt;

	inline void add(int p, int x) {
		for (; p > 0; p -= p & -p) {
			if (ver[p] ^ vercnt)
				bit[p] = 0, ver[p] = vercnt;
			bit[p] += x;
		}
	}
	
	inline int64_t query(int p) {
		int64_t r = 0;
		for (; p <= n; p += p & -p) {
			if (ver[p] ^ vercnt)
				bit[p] = 0, ver[p] = vercnt;
			r += bit[p];
		}
		return r;
	}

	inline void clear() {
		++ vercnt;
	}
} bit;

int64_t res[N];

void solve(int l, int r) {
	if (l >= r) return ;
	int m = l + r >> 1;

	solve(l, m), solve(m + 1, r);
	// merge sort by (a.r < b.r) and do query
	int i = l, j = m + 1, k = l;

	while (i <= m && j <= r) {
		if (query[i].r <= query[j].r) {
			if (query[i].tp == 0)
				bit.add(query[i].l, query[i].v * (query[i].r - query[i].l));
			tmp[k ++] = query[i ++];
		} else {
			if (query[j].tp == 1)
				res[query[j].v] += bit.query(query[j].l);
			tmp[k ++] = query[j ++];
		}
	}

	while (i <= m) {
		tmp[k ++] = query[i ++];
	}

	while (j <= r) {
		if (query[j].tp == 1)
			res[query[j].v] += bit.query(query[j].l);
		tmp[k ++] = query[j ++];
	}

	bit.clear();
	for (int x = l; x <= r; x++)
		query[x] = tmp[x];
}

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (pos[a[i]].size())
			query[++ q] = {0, *pos[a[i]].rbegin(), i, 1};
		pos[a[i]].insert(i);
	}
	for (int i = 1, tp, x, y; i <= m; i++) {
		cin >> tp >> x >> y;
		if (tp == 1) {
			// do erase
			{
				auto it = pos[a[x]].find(x);
				if (it != pos[a[x]].begin()) {
					query[++ q] = {0, *prev(it), *it, -1};
					if (it != -- pos[a[x]].end())
						query[++ q] = {0, *prev(it), *next(it), 1};
				}
				if (it != -- pos[a[x]].end())
					query[++ q] = {0, *it, *next(it), -1};
				pos[a[x]].erase(it);
			}
			a[x] = y;
			{
				pos[a[x]].insert(x);
				auto it = pos[a[x]].find(x);
				if (it != pos[a[x]].begin()) {
					query[++ q] = {0, *prev(it), *it, 1};
					if (it != -- pos[a[x]].end())
						query[++ q] = {0, *prev(it), *next(it), -1};
				}
				if (it != -- pos[a[x]].end())
					query[++ q] = {0, *it, *next(it), 1};
			}
		} else {
			query[++ q] = {1, x, y, ++ qans};
		}
	}
	solve(1, q);
	for (int i = 1; i <= qans; i++)
		cout << res[i] << '\n';
}