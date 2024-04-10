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
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << "\nExcution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

const int dx[] = {0, 1, 1};
const int dy[] = {1, 0, 1};

char a[105][105];

string s = "theseus";

void Hollwo_Pelw(){
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			for (int d = 0; d < 3; d++) {
				bool ok = 1;
				for (int k = 0; k < (int) s.size(); k++) {
					int x = i + k * dx[d], y = j + k * dy[d];
					if (x < 0 || y < 0 || x >= n || y >= n || a[x][y] != s[k]) ok = 0;
				}
				if (ok)
					return cout << "YES\n", (void) 0;
			}

		}

	cout << "NO\n";
}