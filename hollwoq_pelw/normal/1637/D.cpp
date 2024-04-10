/*
// is short or still long ???
hollwo_pelw's tecntlate(short)
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

const int N = 105;

int n, a[N], b[N], dp[N * N];

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];

	int sum = 0, tot = 0, res = 0;

	for (int i = 1; i <= n; i++) {
		tot += a[i] + b[i];
		sum += (n - 2) * (a[i] * a[i] + b[i] * b[i]);
	}

	// (sum_a + sum_b) ^ 2 + sum - 2 * sum_a * sum_b;
	memset(dp, 0, sizeof dp);
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = N * N; j --; ) {
			dp[j] = 0;
			if (j >= a[i] && dp[j - a[i]]) dp[j] = 1;
			if (j >= b[i] && dp[j - b[i]]) dp[j] = 1;
		}

	for (int i = 0; i < N * N; i++)
		if (dp[i]) res = max(res, i * (tot - i));

	cout << tot * tot + sum - 2 * res << '\n';
}