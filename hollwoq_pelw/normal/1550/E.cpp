/* 
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

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

inline bool chkmin(int &a, int b) {
	return a > b ? a = b, 1 : 0;
}

int n, k, nxt[1 << 18][17], dp[1 << 17], lst[17];
char s[1 << 18];

bool check(int v) {
	if (v * k > n) return 0;
	for (int i = 0; i < 17; i++) lst[i] = 0;
	memset(nxt, 0x3f, sizeof nxt);
	memset(dp , 0x3f, sizeof dp );

	for (int i = 1, c, j; i <= n; i++) {
		if (s[i] != '?') 
			lst[s[i] - 'a'] = i;

		for (j = 0, c = -1; j < k && c != -2; j++) 
			if (lst[j] && i - lst[j] + 1 <= v) { // v - 1 nearest pos
				c = (c == -1 ? j : -2);
			}

		if (i >= v && c != -2) 
			for (j = 0; j < 17; j++)
				if (c == -1 || j == c) nxt[i - v][j] = i;
	}
	for (int i = n - 1; ~i; i--)
		for (int j = 0; j < 17; j++)
			nxt[i][j] = min(nxt[i][j], nxt[i + 1][j]);
	dp[0] = 0;
	for (int mask = 0; mask < 1 << k; mask++) if (dp[mask] <= n) {
		for (int i = 0; i < k; i++) if (!(mask >> i & 1))
			chkmin(dp[mask ^ 1 << i], nxt[dp[mask]][i]);
	}
	return dp[(1 << k) - 1] <= n;
}

void Hollwo_Pelw() {
	cin >> n >> k >> (s + 1);
	int l = 1, r = n, ans = 0;
	while (l <= r) {
		int m = l + r >> 1;
		(check(m) ? ans = m, l = m + 1 : r = m - 1);
	}
	cout << ans;
}