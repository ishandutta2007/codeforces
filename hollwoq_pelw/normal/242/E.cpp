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
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 1e5 + 5;

#define tm (tl + tr >> 1)
#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

int n, q, st[N << 2][20], lz[N << 2];

void build(int id = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		int a; cin >> a;
		for (int i = 0; i < 20; i++)
			st[id][i] = a >> i & 1;
		return ;
	}
	build(left), build(right);
	for (int i = 0; i < 20; i++)
		st[id][i] = st[id << 1][i] + st[id << 1 | 1][i];
}

inline void apply(int id, int tl, int tr, int v) {
	for (int i = 0; i < 20; i++) if (v >> i & 1)
		st[id][i] = tr - tl + 1 - st[id][i];
	lz[id] ^= v;
}

inline void push(int id, int tl, int tr) {
	if (lz[id]) apply(left, lz[id]), apply(right, lz[id]), lz[id] = 0;
}

void update(int l, int r, int v, int id = 1, int tl = 1, int tr = n) {
	if (l > tr || tl > r) return ;
	if (l <= tl && tr <= r) return apply(id, tl, tr, v);
	push(id, tl, tr), update(l, r, v, left), update(l, r, v, right);
	for (int i = 0; i < 20; i++)
		st[id][i] = st[id << 1][i] + st[id << 1 | 1][i];
}

inline long long calc(int id) {
	long long r = 0;
	for (int i = 0; i < 20; i++)
		r += (1ll * st[id][i]) << i;
	return r;
}

long long query(int l, int r, int id = 1, int tl = 1, int tr = n) {
	if (l > tr || tl > r) return 0;
	if (l <= tl && tr <= r) return calc(id);
	return push(id, tl, tr), query(l, r, left) + query(l, r, right);
}

void Hollwo_Pelw() {
	cin >> n, build(), cin >> q;
	for (int t, l, r, v; q--; ) {
		cin >> t >> l >> r;
		if (t == 1) {
			cout << query(l, r) << '\n';
		} else {
			cin >> v, update(l, r, v);
		}
	}
}