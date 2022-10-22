/*
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include<bits/stdc++.h>
using namespace std;

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

const int N = 1e6 + 5, Q = 3e5 + 5;

struct seg {
	int l, r, w;
	bool operator < (const seg &o) const {
		return w < o.w;
	}
} qr[Q];

#define min __min__
inline int min(int a, int b) {return a < b ? a : b;}

#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

int n, q, st[N << 2], lz[N << 2], res = 1e9;

inline void apply(int id, int v) {
	lz[id] += v, st[id] += v;
}

inline void push(int id) {
	apply(id << 1, lz[id]), apply(id << 1 | 1, lz[id]), lz[id] = 0;
}

void update(int l, int r, int v, int id = 1, int tl = 1, int tr = n) {
	if (l > tr || tl > r) return ;
	if (l <= tl && tr <= r)
		return apply(id, v);
	int tm = tl + tr >> 1;
	push(id), update(l, r, v, left), update(l, r, v, right);
	st[id] = min(st[id << 1], st[id << 1 | 1]);
}

inline void do_update(int p, int v) {
	update(qr[p].l, qr[p].r, v);
}

void Hollwo_Pelw() {
	cin >> q >> n, --n;
	for (int i = 0, l, r, w; i < q; i++)
		cin >> l >> r >> w, qr[i] = {l, --r, w};
	sort(qr, qr + q);
	for (int i = 0, j = 0; i < q; i++) {
		while (j < q && !st[1]) 
			do_update(j ++, 1);
		if (st[1]) res = min(res, qr[j - 1].w - qr[i].w);
		do_update(i, -1);
	}
	cout << res;
}