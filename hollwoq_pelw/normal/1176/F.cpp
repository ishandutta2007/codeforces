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
const int64_t inf = 1e18;

inline void smax(int64_t &a, int64_t b) {
	a = a > b ? a : b;
}

inline void do_swap(int &a, int &b) {
	if (a < b) swap(a, b);
}

int n, k;
int64_t cur[10], nxt[10];

inline void do_update(int j, int64_t x, int64_t y) {
	for (int i = 0; i < 10; i++) if (cur[i] >= 0 && x)
		smax(nxt[(i + j) % 10], cur[i] + x + (i + j >= 10) * y);
}

void Hollwo_Pelw() {
	cin >> n, memset(cur, -1, sizeof cur), cur[0] = 0;
	for (int x, d; n --; ) {
		int a1 = 0, a2 = 0, a3 = 0, b = 0, c = 0;
		for (cin >> k; k--;) {
			cin >> x >> d;
			if (x == 1) {
				do_swap(a3, d);
				do_swap(a2, a3);
				do_swap(a1, a2);
			} else if (x == 2) {
				do_swap(b, d);
			} else {
				do_swap(c, d);
			}
		}
		memcpy(nxt, cur, sizeof cur);
		// x = tot, y = max
		// update 1
		{
			int64_t x = max({a1, b, c}), y = x;
			do_update(1, x, y);
		}
		// update 2
		{
			int64_t x = 0, y = 0;
			if (a2) x = a1 + a2, y = a1;
			if (a1 && b > a2)
				x = a1 + b, y = max(b, a1);
			do_update(2, x, y);
		}
		// update 3
		{
			int64_t x = a3 == 0 ? 0 : 0ll + a1 + a2 + a3, y = a1;
			do_update(3, x, y);
		}
		memcpy(cur, nxt, sizeof nxt);
	}
	cout << *max_element(cur, cur + 10);
}