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

const int N = 3e5 + 5;

int n, p, a[N], lmin[N], lmax[N], rmin[N], rmax[N];
long long res = 0;

// COUNTING
int _cnt[N << 2], * cnt;
int _ver[N << 2], * ver;
int vercnt;

inline void clear() { vercnt ++; }

inline void upd(int p, int v) {
	if (ver[p] ^ vercnt)
		ver[p] = vercnt, cnt[p] = 0;
	cnt[p] += v;
}

inline int get(int p) {
	if (ver[p] ^ vercnt)
		ver[p] = vercnt, cnt[p] = 0;
	return cnt[p];	
}

void solve(int l, int r) {
	if (l == r)
		return ++ res, (void) 0;
	int m = l + r >> 1;

	solve(l, m), solve(m + 1, r);

	for (p = m, lmin[m + 1] = N; p >= l; p --)
		lmin[p] = min(lmin[p + 1], a[p]);

	for (p = m, lmax[m + 1] = 0; p >= l; p --)
		lmax[p] = max(lmax[p + 1], a[p]);
	
	for (p = m + 1, rmin[m] = N; p <= r; p ++)
		rmin[p] = min(rmin[p - 1], a[p]);

	for (p = m + 1, rmax[m] = 0; p <= r; p ++)
		rmax[p] = max(rmax[p - 1], a[p]);

	// max left, min left
	for (int i = m, j = m + 1; i >= l; i --) {
		if (lmax[i] < rmax[j] || lmin[i] > rmin[j]) continue ;
		while (j < r && rmax[j + 1] < lmax[i] && rmin[j + 1] > lmin[i]) j ++;

		if (j - i == lmax[i] - lmin[i]) res ++;
	}
	// max right, min right
	for (int i = m, j = m + 1; j <= r; j ++) {
		if (lmax[i] > rmax[j] || lmin[i] < rmin[j]) continue ;
		while (i > l && rmax[j] > lmax[i - 1] && rmin[j] < lmin[i - 1]) i --;

		if (j - i == rmax[j] - rmin[j]) res ++;
	}
	// max left, min right
	clear();
	for (int i = m, cl = m + 1, cr = m; i >= l; i --) {
		while (cr < r && rmax[cr + 1] < lmax[i])
			++ cr, upd(cr + rmin[cr], + 1);
		while (cl <= cr && lmin[i] < rmin[cl])
			upd(cl + rmin[cl], - 1), ++ cl;
		res += get(i + lmax[i]);
	}
	// min left, max right
	clear();
	for (int i = m, cl = m + 1, cr = m; i >= l; i --) {
		while (cr < r && rmin[cr + 1] > lmin[i]) {
			++ cr, upd(cr - rmax[cr], + 1);
		}
		while (cl <= cr && lmax[i] > rmax[cl])
			upd(cl - rmax[cl], - 1), ++ cl;
		res += get(i - lmin[i]);
	}
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1, x; i <= n; i++)
		cin >> x >> a[x];
	cnt = _cnt + (N << 1);
	ver = _ver + (N << 1);

	solve(1, n);
	
	cout << res << '\n';
}