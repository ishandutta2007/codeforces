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

const int N = 2e5 + 5;

struct node {
	int lc, rc, lv, rv, len; int64_t res;
	node (int lc = 0, int rc = 0, int lv = 2e9, int rv = -2e9, int len = 0, int64_t res = 0)
		: lc(lc), rc(rc), lv(lv), rv(rv), len(len), res(res) {}
} st[N << 2];
 
node merge(const node &a, const node &b) {
	bool ok = a.rv <= b.lv;
	return node(
		a.lc + (a.lc == a.len && ok ? b.lc : 0),
		b.rc + (b.rc == b.len && ok ? a.rc : 0),
		a.lv,
		b.rv,
		a.len + b.len,
		a.res + b.res + (ok ? 1ll * a.rc * b.lc : 0)
	);
}
 
int n, q, sz = 1;
 
void Hollwo_Pelw() {
	cin >> n >> q;
	while (sz < n) sz <<= 1;
	
	for (int i = 0, a; i < n; i++)
		cin >> a, st[i + sz] = node(1, 1, a, a, 1, 1);
	for (int i = sz - 1; i; i--)
		st[i] = merge(st[i << 1], st[i << 1 | 1]);

	for (int t, l, r; q --; ) {
		cin >> t >> l >> r;
		l += sz - 1;
		if (t == 1) {
			for (st[l] = node(1, 1, r, r, 1, 1); l >>= 1; )
				st[l] = merge(st[l << 1], st[l << 1 | 1]);
		}
		else {
			node lval, rval;
			for (r += sz; l < r; l >>= 1, r >>= 1) {
				if (l & 1) lval = merge(lval, st[l ++]);
				if (r & 1) rval = merge(st[-- r], rval);
			}
			cout << merge(lval, rval).res << '\n';
		}
	}
}