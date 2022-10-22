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
	FAST_IO("D.inp", "D.out");
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

const int N = 5e5 + 5, M = 1e6;

// all different
int n, q, a[N];

struct node_t {
	int cnt, val;
	node_t(int _cnt = 0, int _val = 0)
		: cnt(_cnt), val(_val) {}
	friend node_t merge(const node_t& a, const node_t& b) {
		if (a.val == b.val)
			return node_t(a.cnt + b.cnt, a.val);
		return a.val < b.val ? a : b;
	}
} st[M << 2]; // number of differs

int lz[M << 2];

#define tm (tl + tr >> 1)
#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

inline void apply_add(int id, int v) {
	st[id].val += v, lz[id] += v;
}

inline void apply_cnt(int id, int v) {
	st[id].cnt += v;
}

inline void push(int id) {
	if (lz[id]) {
		apply_add(id << 1, lz[id]);
		apply_add(id << 1 | 1, lz[id]);
		lz[id] = 0;
	}
}

void update_add(int l, int r, int v, int id = 1, int tl = 0, int tr = M) {
	if (l > tr || tl > r) return ;
	if (l <= tl && tr <= r)
		return apply_add(id, v);
	push(id);

	update_add(l, r, v, left);
	update_add(l, r, v, right);

	st[id] = merge(st[id << 1], st[id << 1 | 1]);
}

void update_cnt(int p, int v, int id = 1, int tl = 0, int tr = M) {
	if (tl == tr)
		return apply_cnt(id, v);
	push(id);

	(p > tm ? update_cnt(p, v, right)
			: update_cnt(p, v, left));

	st[id] = merge(st[id << 1], st[id << 1 | 1]);
}

void do_update(int x, int y, int v) {
	if (x > y)
		update_add(y, x - 1, v);
}

void Hollwo_Pelw() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	a[0] = M + 1;

	for (int i = 0; i <= n; i++)
		do_update(a[i], a[i + 1], +1);
	for (int i = 1; i <= n; i++)
		update_cnt(a[i], +1);

	for (int p, v; q --; ) {
		cin >> p >> v;
		
		update_cnt(a[p], -1);
		do_update(a[p - 1], a[p], -1);
		do_update(a[p], a[p + 1], -1);

		a[p] = v;

		update_cnt(a[p], +1);
		do_update(a[p - 1], a[p], +1);
		do_update(a[p], a[p + 1], +1);

		cout << st[1].cnt << '\n';
	}
}