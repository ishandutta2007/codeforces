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

#define int long long
const int N = 2e5 + 5;

int n, q, a[N], res;

#define tm (tl + tr >> 1)
#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

int st[N << 2], tg[N << 2], lz[N << 2];

inline void apply(int id, int tl, int tr, int v) {
	st[id] = (tr - tl + 1) * v, tg[id] = lz[id] = v;
}

inline void merge(int id) {
	st[id] = st[id << 1] + st[id << 1 | 1];
	tg[id] = tg[id << 1] > tg[id << 1 | 1] ? tg[id << 1 | 1] : tg[id << 1];
}

inline void push(int id, int tl, int tr) {
	if (!lz[id]) return ;
	st[id << 1] = (tm - tl + 1) * lz[id];
	st[id << 1 | 1] = (tr - tm) * lz[id];

	lz[id << 1] = lz[id << 1 | 1] = tg[id << 1] = tg[id << 1 | 1] = lz[id];

	lz[id] = 0;
}

void build(int id = 1, int tl = 1, int tr = n) {
	if (tl == tr)
		return apply(id, tl, tr, a[tl]);
	build(left), build(right), merge(id);
}

void update(int l, int r, int v, int id = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr) return ;
	if (l <= tl && tr <= r)
		return apply(id, tl, tr, v);
	push(id, tl, tr);
	update(l, r, v, left), update(l, r, v, right), merge(id);
}

int get_pos(int v, int id = 1, int tl = 1, int tr = n) {
	if (tl == tr) return tl; push(id, tl, tr);
	return tg[id << 1] < v ? get_pos(v, left) : get_pos(v, right);
}

void query(int l, int r, int &v, int &rt, int id = 1, int tl = 1, int tr = n) {
	if (l > r || l > tr || tl > r || st[id] == 0 || tg[id] > v) return ;
	if (l <= tl && tr <= r && st[id] <= v) {
		rt += tr - tl + 1, v -= st[id];
		return ;
	}
	push(id, tl, tr);
	query(l, r, v, rt, left), query(l, r, v, rt, right);
}

#undef tm
#undef left
#undef right

void Hollwo_Pelw() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	build();
	for (int i = 1, t, p, v; i <= q; i++) {
		cin >> t >> p >> v;
		if (t == 1) {
			update(get_pos(v), p, v);
		} else {
			int res = 0; 
			query(p, n, v, res);
			cout << res << '\n';
		}
	}
}