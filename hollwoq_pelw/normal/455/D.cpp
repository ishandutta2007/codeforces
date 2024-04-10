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

const int N = 1e5 + 5, SZ = 600, BLK = 200, reb = 1000;

int n, q, a[N];
short cnt[BLK][N];

int vals[BLK][SZ + reb + 10], szval[BLK];

#define tl(id) id * SZ
#define tr(id) min((id + 1) * SZ, n) - 1

inline void __build__() {
	for (int id = 0; tl(id) < n; id++) {
		for (int i = tl(id); i <= tr(id); i++) {
			cnt[id][a[i]] ++;
			vals[id][szval[id] ++] = a[i];
		}		
	}
}

inline void __rebuild__() {
	for (int id = 0, bsz = 0; tl(id) < n; id++) {
		for (int i = 0; i < szval[id]; i++)
			a[bsz ++] = vals[id][i], cnt[id][vals[id][i]] = 0;
		szval[id] = 0;
	}
	__build__();
}

inline int __erase__(int pos) {
	for (int id = 0; tl(id) < n; id++) {
		if (pos < szval[id]) {
			int v = vals[id][pos];
			cnt[id][v] --;

			for (int i = pos; i < szval[id]; i++)
				vals[id][i] = vals[id][i + 1];
			
			szval[id] --;
			return v;
		}
		pos -= szval[id];
	}
	return 0;
}

inline void __insert__(int pos, int v) {
	for (int id = 0; tl(id) < n; id++) {
		if (pos < szval[id]) {
			cnt[id][v] ++;
			
			for (int i = szval[id]; i > pos; i--)
				vals[id][i] = vals[id][i - 1];
			vals[id][pos] = v;
			
			szval[id] ++;
			return ;
		}
		pos -= szval[id];
	}
}

inline int __query__ (int pos, int k) {
	for (int id = 0, res = 0; tl(id) < n; id++) {
		if (pos < szval[id]) {
			for (int i = 0; i <= pos; i++)
				res += vals[id][i] == k;
			return res;
		}
		pos -= szval[id], res += cnt[id][k]; 
	}
	return 0;
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], -- a[i];
	
	__build__();

	cin >> q;
	for (int _ = 0, ans = 0, t, l, r, k, updcnt = 0; _ < q; _++) {
		cin >> t >> l >> r;
		l = (ans + l - 1) % n;
		r = (ans + r - 1) % n;
		if (l > r) swap(l, r);

		if (t == 1) {
			if (l != r) __insert__(l, __erase__(r));
		} else {
			cin >> k, k = (ans + k - 1) % n;
			cout << (ans = __query__(r, k) - __query__(l - 1, k)) << '\n';
		}
		if (++ updcnt >= reb)
			updcnt = 0, __rebuild__();
	}
}