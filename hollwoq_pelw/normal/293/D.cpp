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

const int N = 1e5 + 5, off = 1e6 + 1, M = 2e6 + 5;

int n, x[N], y[N], cnt[M];
double res, up[M], dw[M];

double solve() {
	int bound_lf = M, bound_rt = -M;
	fill(dw, dw + M, bound_lf);
	fill(up, up + M, bound_rt);

	for (int i = 1; i <= n; i++) {
		int cx = x[i], nx = x[i == n ? 1 : i + 1];
		int cy = y[i], ny = y[i == n ? 1 : i + 1];
		bound_lf = min(bound_lf, cx);
		bound_rt = max(bound_rt, cx);
		if (cx == nx) {
			
			up[cx] = max(up[cx], 1.0 * max(cy, ny));
			dw[cx] = min(dw[cx], 1.0 * min(cy, ny));

		} else {
			if (nx < cx) swap(nx, cx), swap(ny, cy);

			for (int i = cx; i <= nx; i++) {
				double cury = 1.0 * (ny - cy) / (nx - cx) * (i - cx) + cy;
				up[i] = max(up[i], cury);
				dw[i] = min(dw[i], cury);
			}
		}
	}

	int64_t tot = 0;
	for (int i = bound_lf; i <= bound_rt; i++) {
		int cur_up = (int) (up[i]); // round down
		int cur_dw = (int) (dw[i] - (1e-6)) + 1; // round up
		tot += (cnt[i] = cur_up - cur_dw + 1);
	}

	double ans = 0, s[3] = {0, 0, 0}, add;
	// keep \sum x^2, \sum x, \sum 1
	for (int i = bound_lf; i <= bound_rt; i++) {
		int v = i - bound_lf, c = cnt[i];
		ans += (s[2] - 2.0 * s[1] * 	v + s[0] * v * v) * c;
		double add = c;
		for (int i = 0; i < 3; i ++)
			s[i] += add, add *= v;
	}

	return ans / (1.0 * tot * (tot - 1));
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i] >> y[i], x[i] += off, y[i] += off;
	res += solve(); swap(x, y); res += solve();
	cout << fixed << setprecision(9) << res;
}