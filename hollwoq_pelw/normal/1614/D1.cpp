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

const int N = 2e7 + 5;

int n, cnt[N], pr[N / 10], f;
int64_t dp[N];
bool npr[N];

void Hollwo_Pelw() {
	for (int i = 2; i < N; i++) if (!npr[i]) {
		pr[++ f] = i;
		if (i <= 4000) 
			for (int j = i * i; j < N; j += i) npr[j] = 1;
	}

	cin >> n;
	for (int i = 1, a; i <= n; i++)
		cin >> a, cnt[a] ++;

	for (int i = 1; i <= f; i++)
		for (int j = (N - 1) / pr[i]; j; j--)
			cnt[j] += cnt[pr[i] * j];
		
	for (int i = N - 1; i; i--) if (cnt[i]) {
		dp[i] = 1ll * cnt[i] * i;
		for (int j = 1; j <= f && pr[j] * i < N; j ++)
			dp[i] = max(dp[i], dp[i * pr[j]] + 
				(int64_t) (cnt[i] - cnt[i * pr[j]]) * i);
	}

	cout << dp[1] << '\n';
}