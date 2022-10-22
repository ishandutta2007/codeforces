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

const int N = 1e5 + 5, inf = 1e18;

int n, k, a[N], cnt[N], dp[22][N];

int tl = 1, tr = 0, cost;

void getcost(int l, int r){
	while (tl > l) cost += cnt[a[-- tl]] ++;
	while (tr < r) cost += cnt[a[++ tr]] ++;
	while (tl < l) cost -= -- cnt[a[tl ++]];
	while (tr > r) cost -= -- cnt[a[tr --]];
	// cout << l << ' ' << r << ' ' << cost << endl;
}

void solve(int i, int l, int r, int opl, int opr){
	if (l > r) return ;
	int m = l + r >> 1, opm;
	dp[i][m] = inf;
	for (int j = min(m, opr); j >= opl; j--){
		getcost(j, m);
		if (dp[i][m] > dp[i - 1][j - 1] + cost)
			dp[i][m] = dp[i - 1][j - 1] + cost, opm = j;
	}
	solve(i, l, m - 1, opl, opm), solve(i, m + 1, r, opm, opr);
}

void Hollwo_Pelw() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
		dp[0][i] = inf;
	for (int i = 1; i <= k; i++) {
		solve(i, 1, n, 1, n);
		// for (int j = 1; j <= n; j++)
		// 	cout << dp[i][j] << " \n"[j == n];
	}
	cout << dp[k][n];
}