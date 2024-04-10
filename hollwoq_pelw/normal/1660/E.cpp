#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

void Hollwo_Pelw();

signed main(){
#ifndef hollwo_pelw_local
	if (fopen("hollwo_pelw.inp", "r"))
		assert(freopen("hollwo_pelw.inp", "r", stdin)), assert(freopen("hollwo_pelw.out", "w", stdout));
#else
	auto start = chrono::steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
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
}

const int N = 4005;

int n, p0[N][N], p1[N][N];
char a[N][N], c;

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		cin >> c, a[i][j] = a[i + n][j] = a[i][j + n] = a[i + n][j + n] = c;
	for (int i = 1; i <= 2 * n; i++)
		for (int j = 1; j <= 2 * n; j++) {
			p1[i][j] = p1[i - 1][j - 1] + (a[i][j] - '0');
			p0[i][j] = p0[i - 1][j] + p0[i][j - 1] - p0[i - 1][j - 1] + (a[i][j] - '0');
		}
	int res = 1e9;
	for (int i = n; i < 2 * n; i++)
		for (int j = n; j < 2 * n; j++) {
			int d = p1[i][j] - p1[i - n][j - n];
			int s = p0[i][j] - p0[i - n][j] - p0[i][j - n] + p0[i - n][j - n] - d;
			res = min(res, s + n - d);
		}
	cout << res << '\n';
}