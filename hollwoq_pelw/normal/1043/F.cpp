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

// 2 * 3 * 5 * 7 * 11 * 13 * 17 > 5e5
// => max ans = 7 + 1 = 8 ?

const int N = 3e5 + 5;

int64_t dp[N], ways[N];

int n, cnt[N];

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1, a; i <= n; i++)
		cin >> a, cnt[a] ++;
	for (int i = 1; i < N; i ++)
		for (int j = 2 * i; j < N; j += i)
			cnt[i] += cnt[j];
	fill(ways, ways + N, 1);
	for (int res = 1; res <= 7; res++) {
		for (int i = N - 1; i; i--) {
			dp[i] = (ways[i] *= cnt[i] - res + 1);
			for (int j = 2 * i; j < N; j += i)
				dp[i] -= dp[j];
		}
		if (dp[1])
			return cout << res, (void) 0;
	}
	cout << -1;
}