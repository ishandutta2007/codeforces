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
	cin >> testcases;
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

const int N = 2e5 + 5;

int n, cnt[N];

void Hollwo_Pelw() {
	cin >> n;
	fill(cnt + 1, cnt + n + 1, 0);
	for (int i = 1, x; i <= n; i++)
		cin >> x, cnt[x] ++;
	int res = 1e9;
	for (int f = 0, pf = 0, cf = 0; f <= 18; f++) {
		while (pf < n - 2 && (cf + cnt[pf + 1]) <= 1 << f)
			cf += cnt[++ pf];

		for (int s = 0, ps = pf, cs = 0; s <= 18; s++) {
			while (ps < n - 1 && (cs + cnt[ps + 1]) <= 1 << s)
				cs += cnt[++ ps];

			int oth = n - cf - cs;
			int l = oth == 1 ? 0 : 32 - __builtin_clz(oth - 1);
			res = min(res, (1 << f) + (1 << s) + (1 << l) - n);
		}
	}

	cout << res << '\n';
}