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

#define int long long

const int N = 2e5 + 5;
const double eps = 1e-6;

int p, lx, rx, n, q, pre[N];
double l[N], r[N];

inline double solve(double v) {
	int pos = upper_bound(l + 1, l + n + 1, v + eps) - l - 1;
	return  pos ? pre[pos - 1] + min(r[pos], v) - l[pos] : 0;
}

void Hollwo_Pelw() {
	cin >> p >> lx >> rx;
	cin >> n, p = -p;
	for (int i = 1, ll, rr; i <= n; i++) {
		cin >> ll >> rr;
		l[i] = ll, r[i] = rr;
		pre[i] = pre[i - 1] + rr - ll;
	}
	// binary search for wut
	cout << fixed << setprecision(9);
	cin >> q;
	for (int x, y; q --; ) {
		cin >> x >> y;
		// (x, y) -> (py, lx) => y = 0
		// cx = (p * x + lx * y) / (y + p)
		double cl = 1.0 * (p * x + lx * y) / (y + p);
		double cr = 1.0 * (p * x + rx * y) / (y + p);
		// cout << cl << ' ' << cr << '\n';
		cout << (solve(cr) - solve(cl)) * (y + p) / y << '\n';
		// cout << 1.0 * (cr - cl - solve(cl, cr, y + p)) / (y + p) << '\n';
	}
}