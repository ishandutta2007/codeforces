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

int n, k, a[N], cnt[N], b[N];

inline void solve(int l, int r, int pr = 0) {
	for (int i = 1; i <= n; i++)
		b[i] = b[i - 1] + (l <= a[i] && a[i] <= r ? 1 : -1);
	
	int c = 0;
	for (int i = 1, p = 1; i <= n && p < k; i++) {
		if (b[i] == p) {
			cout << c + 1 << ' ' << i << '\n';
			c = i, ++ p;
		}
	}
	cout << c + 1 << ' ' << n << '\n';
}

void Hollwo_Pelw() {
	cin >> n >> k;
	fill(cnt + 1, cnt + n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> a[i], cnt[a[i]] ++;

	int c = 0, bx = 1, by = n;

	for (int x = 1, y = 1; x <= n; x++) {
		while (y <= n && c - (n - c) < k)
			c += cnt[y], y ++;
			
		if (c - (n - c) >= k) {
			if (y - x < by - bx + 1)
				bx = x, by = y - 1;
		}

		c -= cnt[x];
	}
	
	cout << bx << ' ' << by << '\n';
	solve(bx, by, 1);
}