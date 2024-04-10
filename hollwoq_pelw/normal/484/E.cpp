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

const int N = 1e5 + 5, L = 18;

struct node_t {
	int pre, suf, mx, f, lc, rc;
	node_t (int _pre = 0, int _suf = 0, int _mx = 0, bool _f = 0, int _lc = 0, int _rc = 0)
		: pre(_pre), suf(_suf), mx(_mx), f(_f), lc(_lc), rc(_rc) {}
} st[N * L << 1];

node_t merge(const node_t& l, const node_t& r, int lc = 0, int rc = 0) {
	return node_t(
		(l.f ? r.pre + l.mx : l.pre),
		(r.f ? l.suf + r.mx : r.suf),
		max({l.mx, r.mx, l.suf + r.pre}),
		l.f && r.f, lc, rc
	);
}

int n, q, nnode, h[N], root[N];
vector<int> upd_vc[N];

inline int new_merge(int lc, int rc) {
	return st[++ nnode] = merge(st[lc], st[rc], lc, rc), nnode;
}

#define left st[id].lc, tl, tm
#define right st[id].rc, tm + 1, tr

int update(int p, int id, int tl = 1, int tr = n) {
	if (tl == tr) {
		return st[++ nnode] = node_t(1, 1, 1, 1, 0, 0), nnode;
	} else {
		int lc = st[id].lc, rc = st[id].rc, tm = tl + tr >> 1;
		(p > tm ? rc = update(p, right)
				: lc = update(p, left));
		return new_merge(lc, rc);
	}
}

node_t query(int l, int r, int id, int tl = 1, int tr = n) {
	if (l > tr || tl > r) return node_t(0, 0, 0, 1, 0, 0);
	if (l <= tl && tr <= r) return st[id];
	int tm = tl + tr >> 1;
	return merge(query(l, r, left), query(l, r, right));
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> h[i];

	vector<int> list_val(h + 1, h + n + 1);
	{
		sort(list_val.begin(), list_val.end());
		list_val.erase(unique(list_val.begin(), list_val.end()), list_val.end());
		for (int i = 1; i <= n; i++)
			h[i] = lower_bound(list_val.begin(), list_val.end(), h[i]) - list_val.begin();
	}

	for (int i = 1; i <= n; i++)
		upd_vc[h[i]].push_back(i);

	for (int i = (int) list_val.size() - 1; i; --i) {
		int cur = root[i + 1];
		for (auto v : upd_vc[i])
			cur = update(v, cur);
		root[i] = cur;
	}

	cin >> q;
	for (int l, r, w; q --; ) {
		cin >> l >> r >> w;
		// binary search
		int tl = 1, tr = list_val.size() - 1, res = 0;
		while (tl <= tr) {
			int tm = tl + tr >> 1;
			if (query(l, r, root[tm]).mx >= w)
				res = tm, tl = tm + 1;
			else
				tr = tm - 1;
		}
		cout << list_val[res] << '\n';
	}
}