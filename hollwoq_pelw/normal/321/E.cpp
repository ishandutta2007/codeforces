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
	FAST_IO(".inp", ".out");
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

const int N = 4004, inf = 2e9;

#define min __min__

inline int min (int a, int b) {
	return a > b ? b : a;
}

inline bool chkmin(int &a, int b) {
	return a > b ? a = b, 1 : 0;
}

int a[N][N], n, k, dp[N], ldp[N];

int cost(int l, int r) {
	return a[r][r] - a[l - 1][r] - a[r][l - 1] + a[l - 1][l - 1];
}

void solve(int l, int r, int opl, int opr) {
	if (l > r) return ;
	int m = l + r >> 1, opm = -1;
	for (int i = opl; i <= min(opr, m); i++)
		if (chkmin(dp[m], ldp[i - 1] + cost(i, m))) opm = i;
	solve(l, m - 1, opl, opm);
	solve(m + 1, r, opm, opr);
}

void Hollwo_Pelw() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
		char c; cin >> c, a[i][j] = c - '0' + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
	}
	
	for (int i = 1; i <= n; i++)
		dp[i] = cost(1, i);

	int ans = inf;
	for (int i = 2; i <= k; i++) {
		for (int j = 1; j <= n; j++)
			ldp[j] = dp[j], dp[j] = inf;
		solve(1, n, 1, n);
	}
	cout << (dp[n] >> 1);
}