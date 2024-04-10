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

const int N = 2e5 + 5, L = 18;

struct query_t {
	int t1, t2, y1, a, b, y2;
	query_t (int _t1 = 0, int _t2 = 0, int _y1 = 0, int _a = 0, int _b = 0, int _y2 = 0)
		: t1(_t1), t2(_t2), y1(_y1), a(_a), b(_b), y2(_y2) {}
} q[N];

struct node_t {
	int64_t b; int a, lc, rc;
	node_t(int _a = 0, int64_t _b = 0, int _lc = 0, int _rc = 0)
		: a(_a), b(_b), lc(_lc), rc(_rc) {}
	inline int64_t f(int x) {
		return b + 1ll * a * x;
	}
} st[N * L << 1];

int n, m, nnode, root[N << 1];

struct update_t {
	int p, a, b;
	update_t(int _p = 0, int _a = 0, int _b = 0)
		: p(_p), a(_a), b(_b) {}
};

vector<update_t> upd_vc[N << 1];

node_t merge(const node_t& l, const node_t& r, int lc = 0, int rc = 0) {
	return node_t(l.a + r.a, l.b + r.b, lc, rc);
}

inline int new_merge(int lc, int rc) {
	return st[++ nnode] = merge(st[lc], st[rc], lc, rc), nnode;
}

#define tm (tl + tr >> 1)
#define left st[id].lc, tl, tm
#define right st[id].rc, tm + 1, tr

int update(int p, int a, int b, int id, int tl = 1, int tr = n) {
	if (tl == tr) {
		return st[++ nnode] = node_t(a, b, 0, 0), nnode;
	} else {
		int lc = st[id].lc, rc = st[id].rc;
		(p > tm ? rc = update(p, a, b, right)
				: lc = update(p, a, b, left));
		return new_merge(lc, rc);
	}
}

node_t query(int l, int r, int id, int tl = 1, int tr = n) {
	if (l > tr || tl > r) return node_t();
	if (l <= tl && tr <= r) return st[id];
	return merge(query(l, r, left), query(l, r, right));
}

void Hollwo_Pelw() {
	cin >> n;
	vector<int> allp(1, 1e9);
	for (int t1, t2, y1, a, b, y2, i = 1; i <= n; i++) {
		cin >> t1 >> t2 >> y1 >> a >> b >> y2;
		q[i] = {t1, t2, y1, a, b, y2};
		allp.push_back(t1);
		allp.push_back(t2);
	}

	{
		sort(allp.begin(), allp.end());
		allp.erase(unique(allp.begin(), allp.end()), allp.end());
		for (int i = 1; i <= n; i++) {
			auto [t1, t2, y1, a, b, y2] = q[i];
			t1 = lower_bound(allp.begin(), allp.end(), t1) - allp.begin();
			t2 = lower_bound(allp.begin(), allp.end(), t2) - allp.begin();
			upd_vc[allp.size() - 1].emplace_back(i, 0, y2);
			upd_vc[t2].emplace_back(i, a, b);
			upd_vc[t1].emplace_back(i, 0, y1);
		}
	}

	for (int i = (int) allp.size() - 1; ~i; i--) {
		int cur = root[i + 1];
		for (auto [p, a, b] : upd_vc[i])
			cur = update(p, a, b, cur);
		root[i] = cur;
	}

	cin >> m;
	for (int64_t l, r, x, res = 0; m --; ) {
		cin >> l >> r >> x, x = (x + res) % 1000000000;
		int ver = lower_bound(allp.begin(), allp.end(), x) - allp.begin();
		cout << (res = query(l, r, root[ver]).f(x)) << '\n';
	}
}