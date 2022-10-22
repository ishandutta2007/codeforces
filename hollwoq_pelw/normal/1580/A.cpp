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

const int N = 405;

int n, m, pre[N][N]; // number of 1
char s[N][N];

inline int get1(int sx, int ex, int sy, int ey) {
	return pre[ex][ey] - pre[sx - 1][ey] - pre[ex][sy - 1] + pre[sx - 1][sy - 1];
}

inline int get0(int sx, int ex, int sy, int ey) {
	return (ex - sx + 1) * (ey - sy + 1) - get1(sx, ex, sy, ey);
}

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> (s[i] + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + (s[i][j] - '0');
	int res = 15;
	for (int u = 1; u <= n; u++) {
		for (int d = u + 4; d <= n; d++) {
			for (int l = 1; l <= m; l++) {
				for (int r = l + 3; r <= m; r++) {
					int cur = get0(u + 1, d - 1, l, l);
					cur += get0(u, u, l + 1, r - 1);
					cur += get0(d, d, l + 1, r - 1);
					cur += get1(u + 1, d - 1, l + 1, r - 1);
					if (cur > res) break ;
					res = min(res, cur + get0(u + 1, d - 1, r, r));
				}
			}
		}
	}
	cout << res << '\n';
}