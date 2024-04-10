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

const int N = 1e6 + 5;

int n, m, a[N], b[N];
char s[N], res[N];

inline int comp(int x, int y) {
	return x == 0 || y == 0 ? 0 : (x - 1) * m + y;
}

bool solve(int t, bool contruct = 0) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			b[comp(i, j)] = a[comp(i, j)] >= t ? t : 0;
	for (int i = n; i; i--) for (int j = m; j; j--) {
		if (i > 1) b[comp(i - 1, j)] = max(b[comp(i - 1, j)], b[comp(i, j)] - 1);
		if (j > 1) b[comp(i, j - 1)] = max(b[comp(i, j - 1)], b[comp(i, j)] - 1);
		if (i > 1 && j > 1) b[comp(i - 1, j - 1)] = max(b[comp(i - 1, j - 1)], b[comp(i, j)] - 1);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[comp(i, j)] && !b[comp(i, j)]) return 0;
	if (contruct) {
		t /= 2; cout << t << '\n';

		fill(res + 1, res + n * m + 1, '.');

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (a[comp(i, j)] >= 2 * t + 1)
					res[comp(i - t, j - t)] = 'X';

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) 
				cout << res[comp(i, j)];
			cout << '\n';
		}
	}
	return 1;
}

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> (s + (comp(i, 1)));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[comp(i, j)] = s[comp(i, j)] == '.' ? 0 : 
		min({a[comp(i - 1, j)], a[comp(i, j - 1)], a[comp(i - 1, j - 1)]}) + 1;
	
	int l = 0, r = min(n, m) / 2 + 1;
	while (r - l >= 2) {
		int m = l + r >> 1;
		(solve(2 * m + 1) ? l : r) = m;
	}
	solve(2 * l + 1, 1);
}