/* 
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

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

int n, ans, dp[1 << 24];
char s[5];

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		int v = 0;
		for (int j = 0; j < 3; j++)
			v |= 1 << s[j] - 'a';
		dp[v] ++;
	}
	for (int i = 0; i < 24; i++)
		for (int j = 0; j < 1 << 24; j++)
			if (j >> i & 1) dp[j] += dp[j ^ 1 << i];
	for (int i = 0; i < 1 << 24; i++)
		ans ^= (n - dp[i]) * (n - dp[i]);
	cout << ans;
}