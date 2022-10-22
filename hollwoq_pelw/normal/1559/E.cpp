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

const int N = 1e5 + 5, mod = 998244353;

int n, tl[55], tr[55];

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a < b ? a - b + mod : a - b; }

int dp[55][N], pre[55][N];

int get(int i, int l, int r) {
	if (r < 0) return 0; if (l < 0) l = 0; 
	return sub(pre[i][r], l ? pre[i][l - 1] : 0);
}

int solve(int m, int g) {
	m /= g;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= m; j++)
			dp[i][j] = pre[i][j] = 0;
	for (int i = 1; i <= n; i++) {
		int l = (tl[i] - 1) / g + 1, r = tr[i] / g;
		if (l > r) return 0;
		for (int j = 0; j <= m; j++)
			pre[i - 1][j] = add(j ? pre[i - 1][j - 1] : 0, dp[i - 1][j]);
		for (int j = 0; j <= m; j++)
			dp[i][j] = get(i - 1, j - r, j - l);
	}
	int ans = 0;
	for (int i = 1; i <= m; i++)
		ans = add(ans, dp[n][i]);
	return ans;
}

int m, res[N];

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> tl[i] >> tr[i];
	for (int i = 1; i <= m; i++)
		res[i] = solve(m, i); // gcd = i; ??
	for (int i = m; i >= 1; i--) {
		for (int j = 2 * i; j <= m; j += i)
			res[i] = sub(res[i], res[j]);
	}
	cout << res[1];
}