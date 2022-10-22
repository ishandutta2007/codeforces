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

const int N = 1e5 + 5;

#define tm (tl + tr >> 1)
#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

int n, q, col[N << 2];
long long st[N << 2], lz[N << 2];

void build(int id = 1, int tl = 1, int tr = n) {
	if (tl == tr)
		return col[id] = tl, (void) 0;
	build(left), build(right);
}

inline void apply(int id, int tl, int tr, int c, long long v) {
	// assert(col[id] > 0);
	assert(c > 0);
	col[id] = c;

	lz[id] += v;
	st[id] += v * (tr - tl + 1);
}

inline void push(int id, int tl, int tr) {
	if (lz[id])
		apply(left, col[id], lz[id]), apply(right, col[id], lz[id]), lz[id] = 0;
}

void update(int l, int r, int c, int id = 1, int tl = 1, int tr = n) {
	if (l > tr || tl > r) return ;
	if (l <= tl && tr <= r && col[id])
		return apply(id, tl, tr, c, abs(c - col[id]));
	push(id, tl, tr);
	update(l, r, c, left), update(l, r, c, right);
	st[id] = st[id << 1] + st[id << 1 | 1];
	col[id] = col[id << 1] == col[id << 1 | 1] ? col[id << 1] : 0;
}

long long query(int l, int r, int id = 1, int tl = 1, int tr = n) {
	if (l > tr || tl > r) return 0;
	if (l <= tl && tr <= r) return st[id];
	push(id, tl, tr);
	return query(l, r, left) + query(l, r, right);
}

void Hollwo_Pelw() {
	cin >> n >> q;
	build();

	for (int t, l, r, c; q --; ) {
		cin >> t >> l >> r;
		if (t == 2) {
			cout << query(l, r) << '\n';
		} else {
			cin >> c, update(l, r, c);
		}
	}
}