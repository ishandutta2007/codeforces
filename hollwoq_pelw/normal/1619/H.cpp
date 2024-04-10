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

const int N = 1e5 + 5, BLK = 80;

int n, q, rev[N], jmp[N], big_jmp[N];

inline void update(int x) {
	int c = x;
	for (int j = 0; j < BLK; j++)
		c = rev[c];
	big_jmp[c] = x;
	for (int j = 0; j < BLK; j++, c = jmp[c])
		big_jmp[jmp[c]] = jmp[big_jmp[c]];
}

void Hollwo_Pelw() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> jmp[i], rev[jmp[i]] = i;
	for (int i = 1; i <= n; i++) {
		big_jmp[i] = i;
		for (int j = 0; j < BLK; j++)
			big_jmp[i] = jmp[big_jmp[i]];
	}

	for (int t, x, y; q --; ) {
		cin >> t >> x >> y;
		if (t == 1) {
			swap(rev[jmp[x]], rev[jmp[y]]);
			swap(jmp[x], jmp[y]);

			update(x), update(y);

		} else {
			while (y) {
				if (y >= BLK) {
					y -= BLK;
					x = big_jmp[x];
				} else {
					y --;
					x = jmp[x];
				}
			}
			cout << x << '\n';
		}
	}
}