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
	FAST_IO("522D.inp", "522D.out");
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

const int N = 5e5 + 5, inf = 2e9;

struct inter_segtree {
	constexpr static int lg2(int n) { return 32 - __builtin_clz(n - 1); }

	inline int merge(int a, int b) {
		return a < b ? a : b;
	}

	int n, sz, st[1 << 20 | 5];

	inter_segtree(int n = N) {
		sz = 1 << lg2(n);
		for (int p = 1; p < sz + n; p++)
			st[p] = inf;
	}

	void update(int p, int v) {
		for (st[p += sz - 1] = v; p >>= 1; )
			st[p] = merge(st[p << 1], st[p << 1 | 1]);
	}

	int query(int l, int r) {
		int lval = inf, rval = inf;
		for (l += sz - 1, r += sz; l < r; l >>= 1, r >>= 1) {
			if (l & 1) lval = merge(lval, st[l ++]);
			if (r & 1) rval = merge(st[-- r], rval);
		}
		return merge(lval, rval);
	}
} segtree;

int n, m, a[N], nxt[N], res[N];
vector<pair<int, int>> qry[N];

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	map<int, int> last;
	for (int i = n; i; i--) {
		nxt[i] = last.count(a[i]) ? last[a[i]] : -1;
		last[a[i]] = i;
	}

	for (int l, r, i = 0; i < m; i++)
		cin >> l >> r, qry[l].emplace_back(r, i);

	for (int i = n; i; i--) {
		if (nxt[i] != -1) {
			segtree.update(nxt[i], nxt[i] - i);
		}
		for (auto vp : qry[i])
			res[vp.second] = segtree.query(i, vp.first);
	}

	for (int i = 0; i < m; i++)
		cout << (res[i] == inf ? -1 : res[i]) << '\n';
}