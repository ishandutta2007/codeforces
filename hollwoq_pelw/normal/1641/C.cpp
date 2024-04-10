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

struct query_t {
	int t, l, r, x;
} qq[N];

int n, q, lz[N << 2];
struct node_t {
	pair<int, int> mx1, mx2;
	node_t (pair<int, int> mx1 = {0, 1e9}, pair<int, int> mx2 = {0, 1e9})
		: mx1(mx1), mx2(mx2) {}
} st[N << 2];

#define tm (tl + tr >> 1)
#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

inline node_t merge(const node_t &a, const node_t &b) {
	if (a.mx1 > b.mx1)
		return node_t(a.mx1, max(a.mx2, b.mx1));
	if (a.mx1 < b.mx1)
		return node_t(b.mx1, max(b.mx2, a.mx1));
	return node_t(a.mx1, b.mx1);
}

void build(int id = 1, int tl = 1, int tr = n) {
	lz[id] = 1e9;
	if (tl == tr)
		return st[id] = node_t({1e9, tl}, {0, tl}), (void) 0;
	build(left), build(right);
	st[id] = merge(st[id << 1], st[id << 1 | 1]);
}

inline void apply(int id, int v) {
	st[id].mx1.first = min(st[id].mx1.first, v);
	st[id].mx2.first = min(st[id].mx2.first, v);
	lz[id] = min(lz[id], v);

	// cout << id << '\n';
	// cout << st[id].mx1.first << '\n';
	// cout << st[id].mx2.first << '\n';
}

inline void push(int id) {
	apply(id << 1, lz[id]), apply(id << 1 | 1, lz[id]);
}

void update(int l, int r, int v, int id = 1, int tl = 1, int tr = n) {
	if (l > tr || tl > r) return ;
	if (l <= tl && tr <= r) return apply(id, v);
	push(id), update(l, r, v, left), update(l, r, v, right);
	st[id] = merge(st[id << 1], st[id << 1 | 1]);
}

node_t query(int l, int r, int id = 1, int tl = 1, int tr = n) {
	if (l > tr || tl > r) return node_t();
	if (l <= tl && tr <= r) return st[id];
	return push(id), merge(query(l, r, left), query(l, r, right));
}

void Hollwo_Pelw() {
	cin >> n >> q;
	for (int i = 1, t, l, r, x; i <= q; i++) {
		cin >> t;
		if (t) {
			cin >> x;
			qq[i] = {1, 0, 0, x};
		} else {
			cin >> l >> r >> x;
			qq[i] = {0, l, r, x};
		}
	}

	build();

	for (int i = 1; i <= q; i++)
		if (!qq[i].t && !qq[i].x) // no sick
			update(qq[i].l, qq[i].r, i);

	map<int, int> bad;

	for (int i = 1; i <= q; i++) {
		if (!qq[i].t && qq[i].x) {
			// cout << "query\n";

			node_t v = query(qq[i].l, qq[i].r);

			if (!bad.count(v.mx1.second))
				bad[v.mx1.second] = 1e9;
			bad[v.mx1.second] = min(bad[v.mx1.second], max(i, v.mx2.first));
		}
	}

	for (int i = 1; i <= q; i++) {
		if (qq[i].t) {
			int x = qq[i].x;
			if (bad.count(x) && bad[x] <= i) {
				cout << "YES\n";
			} else {
				node_t v = query(x, x);
				if (v.mx1.first <= i)
					cout << "NO\n";
				else
					cout << "N/A\n";
			}
		}
	}
}