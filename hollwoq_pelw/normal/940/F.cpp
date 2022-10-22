/* 
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops,no-stack-protector")

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
	FAST_IO(".inp", ".out");
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

const int N = 1e5 + 5, bl = 3000;

int n, q, nqa, nqc, nl = 1, nr = 0, a[N], blk[N];

struct query {
	int l, r, c, id;
	bool operator < (const query& oth) const {
		if (blk[l] != blk[oth.l]) return blk[l] < blk[oth.l];
		if (blk[r] != blk[oth.r]) return blk[r] < blk[oth.r];
		return blk[r] - blk[l] & 1 ? c < oth.c : c > oth.c;
	}
} qa[N];

struct update {
	int p, prv, nxt;
} qc[N];

map<int, int> comp;
int tot, cnt[N << 1], ct[N], ans[N];

inline int cmp(int x) {
	return comp.count(x) ? comp[x] : comp[x] = ++ tot;
}

inline void add(int x) {
	ct[cnt[x]] --, cnt[x] ++, ct[cnt[x]] ++;
}

inline void del(int x) {
	ct[cnt[x]] --, cnt[x] --, ct[cnt[x]] ++;
}

inline void upd(int p, bool t) {
	int v = t ? qc[p].nxt : qc[p].prv; p = qc[p].p;
	if (nl <= p && p <= nr) del(a[p]), add(v); a[p] = v;
}

void Hollwo_Pelw() {
	cin >> n >> q;
	for (int i = 1, x; i <= n; i++)
		cin >> x, a[i] = cmp(x), blk[i] = (i - 1) / bl;
	for (int i = 1, t, x, y; i <= q; i++) {
		cin >> t >> x >> y;
		if (t == 1) ++ nqa, qa[nqa] = {x, y, nqc, nqa};
		else y = cmp(y), ++ nqc, qc[nqc] = {x, a[x], y}, a[x] = y;
	}

	sort(qa + 1, qa + nqa + 1);
	for (int _ = 1; _ <= nqa; _++) {
		int l = qa[_].l, r = qa[_].r, c = qa[_].c, id = qa[_].id;

		ans[id] = 1;
		
		while (nqc > c) upd(nqc --, 0);
		while (nqc < c) upd(++ nqc, 1);

		while (nl > l) add(a[-- nl]);
		while (nr < r) add(a[++ nr]);
		while (nl < l) del(a[nl ++]);
		while (nr > r) del(a[nr --]);

		while (ct[ans[id]]) ++ ans[id];
	}

	for (int i = 1; i <= nqa; i++)
		cout << ans[i] << '\n';
}