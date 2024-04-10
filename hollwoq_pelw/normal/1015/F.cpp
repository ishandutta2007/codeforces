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

#define int long long

const int N = 202, mod = 1e9 + 7;

inline void sadd(int &a, int b) {
	if ((a += b) >= mod) a -= mod;
}

int n, m, pf[N], dp[N][N][N], nxt[N][2];
string s;

void Hollwo_Pelw() {
	cin >> n >> s;
	m = s.size();
	nxt[0][0] = s[0] == '(', nxt[0][1] = s[0] == ')';
	for (int i = 1; i < m; i++) {
		int c = s[i] == ')', k = pf[i];
		nxt[i][c] = i + 1, nxt[i][c ^ 1] = nxt[k][c ^ 1];
		pf[i + 1] = nxt[k][c];
	}
	nxt[m][0] = nxt[m][1] = m;
	// for (int i = 0; i <= m; i++)
	// 	cout << nxt[i][0] << ' ' << nxt[i][1] << '\n';
	dp[0][0][0] = 1;
	for (int i = 0; i < n << 1; i++) {
		for (int j = 0; j <= m; j++) {
			int l = nxt[j][0], r = nxt[j][1];
			for (int k = i & 1; k <= n; k += 2) {
				if (k < n)
					sadd(dp[i + 1][l][k + 1], dp[i][j][k]);
				if (k > 0)
					sadd(dp[i + 1][r][k - 1], dp[i][j][k]);
			}
		}
	}
	cout << dp[n << 1][m][0];
}