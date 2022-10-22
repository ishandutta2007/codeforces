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

const int N = 1005;

int n, q, bit[4][N][N];

inline int comp(int x, int y) {
	return (x & 1) << 1 | (y & 1);
}

inline void update(int x, int y, int64_t v) {
	int t = comp(x, y);
	
	for (int i = x; i <= n; i += i & -i)
		for (int j = y; j <= n; j += j & -j)
			bit[t][i][j] ^= v;
}

inline int64_t query(int x, int y) {
	int t = comp(x, y);
	
	int64_t r = 0;
	for (int i = x; i; i -= i & -i)
		for (int j = y; j; j -= j & -j)
			r ^= bit[t][i][j];
	return r;
}

inline int64_t query(int sx, int sy, int ex, int ey) {
	return query(ex, ey) ^ query(ex, sy - 1) ^ query(sx - 1, ey) ^ query(sx - 1, sy - 1);
}

inline void update(int sx, int sy, int ex, int ey, int64_t v) {
	update(sx, sy, v), update(sx, ey + 1, v), update(ex + 1, sy, v), update(ex + 1, ey + 1, v);
}

void Hollwo_Pelw() {
	cin >> n >> q;
	for (int t, sx, sy, ex, ey; q--;) {
		cin >> t >> sx >> sy >> ex >> ey;
		if (t == 1) {
			cout << query(sx, sy, ex, ey) << '\n';
		} else {
			int64_t v; cin >> v;
			update(sx, sy, ex, ey, v);
		}
	}
}