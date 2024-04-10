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

const int N = 2e5 + 5;

int bit[N << 1], res, n;
pair<int, int> a[N];

inline void add(int p, int x) {
	for (p += N; p < N << 1; p += p & -p)
		bit[p] = max(bit[p], x);
}

inline int query(int p) {
	int r = 0;
	for (p += N; p; p -= p & -p)
		r = max(r, bit[p]);
	return r;
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1, x; i <= n; i++)
		cin >> x, a[i] = {i - x, i};
	sort(a + 1, a + n + 1);

	for (int _ = 1, val, p; _ <= n; _++) {
		if (a[_].first < 0) continue ;
		p = a[_].second - a[_].first;
		res = max(res, val = query(p) + 1), add(p + 1, val);
	}

	cout << res;
}