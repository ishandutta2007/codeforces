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

const int N = 550, mod = 1e9 + 7;

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline void sadd(int &a, int b) { a = a + b >= mod ? a + b - mod : a + b; }

int n, m, ans, dp[2][N][N];
char a[N][N];

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];

	int len = n + m >> 1;

	dp[0][0][n] = 1;
	for (int i = 1; i <= len; i++) {
		memset(dp[i & 1], 0, sizeof dp[i & 1]);
		for (int sx = 1; sx <= n; sx ++) 
			for (int ex = sx; ex <= n; ex ++) { 

				int sy = i + 1 - sx, ey = m - (i - n + ex) + 1;

				if (sy <= 0 || sy > ey || ey > m) continue ;


				if (a[sx][sy] == a[ex][ey]) {
					sadd(dp[i & 1][sx][ex], dp[i & 1 ^ 1][sx][ex]);
					sadd(dp[i & 1][sx][ex], dp[i & 1 ^ 1][sx - 1][ex]);
					sadd(dp[i & 1][sx][ex], dp[i & 1 ^ 1][sx][ex + 1]);
					sadd(dp[i & 1][sx][ex], dp[i & 1 ^ 1][sx - 1][ex + 1]);
				}
				

				if (i == len)
					sadd(ans, dp[i & 1][sx][ex]);
			}
	}
	cout << ans;
}