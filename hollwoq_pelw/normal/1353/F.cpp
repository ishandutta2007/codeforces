/*
 /+==================================================+\
//+--------------------------------------------------+\\
|.|\\...>>>>>>> Hollwo_Pelw(ass) 's code <<<<<<<...//|.|
\\+--------------------------------------------------+//
 \+==================================================+/
*/
#include <bits/stdc++.h>
using namespace std;
// type
typedef long long ll;
typedef long double ld;
// loop
//#define For(i, l, r)        for (int i = l; i < r; i++)
//#define ForE(i, l, r)       for (int i = l; i <= r; i++)
//#define Ford(i, r, l)       for (int i = r; i > l; i--)
//#define FordE(i, r, l)      for (int i = r; i >= l; i--)
//#define Fora(i, a)          for (auto i : a)
// I/O
#define open(file, in, out) if (fopen(file in, "r")) {        \
                                freopen(file in, "r", stdin);  \
                                freopen(file out, "w", stdout); \
                            }
#define FAST_IO             std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define setpre(n)           fixed << setprecision(n)
// pair
#define F                   first
#define S                   second
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pdd                 pair<ld, ld>
// vector & !!?(string)
#define eb                  emplace_back
#define pb                  push_back
#define all(a)              a.begin(), a.end()
#define rall(a)             a.rbegin(), a.rend()
#define sz(a)               a.size()
#define len(a)              a.length()
// geometry calculate
#define pi                  acos(-1.0)
#define g_sin(a)            sin(a*pi/180)
#define g_cos(a)            cos(a*pi/180)
#define g_tan(a)            tan(a*pi/180)
// set val
#define ms0(a)              memset(a,        0, sizeof(a));
#define ms1(a)              memset(a,        1, sizeof(a));
#define msn1(a)             memset(a,       -1, sizeof(a));
#define msinf(a)            memset(a, 0x3f3f3f, sizeof(a));
// constant
const int mod1 = 998244353, mod = 1e9 + 7;
const int MAXN = 1e6 + 6 , MAXM = 2e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define int long long
int n, m, a[101][101], dp[101][101], vl[101][101];
int calc_l(int i, int j){
	for (int x = 0; x <= i; x++) for (int y = 0; y <= j; y++) vl[x][y] = a[x][y] - a[i][j] + (i + j) - (x + y);
	dp[0][0] = vl[0][0];
	if (vl[0][0] < 0) return linf;
	for (int x = 0; x <= i; x++){
		for (int y = 0; y <= j; y++){
			if ((x == 0) && (y == 0)) continue;
			dp[x][y] = linf;
			if (vl[x][y] < 0) continue;
			if (x > 0) dp[x][y] = min(dp[x][y], dp[x - 1][y]);
			if (y > 0) dp[x][y] = min(dp[x][y], dp[x][y - 1]);
			dp[x][y] += vl[x][y];
		}
	}
	return dp[i][j];
}
int calc_r(int i, int j){
	for (int x = i; x < n; x++)
        for (int y = j; y < m; y++)
            vl[x][y] = a[x][y] - a[i][j] + (i + j) - (x + y);
	dp[i][j] = vl[i][j];
	if (vl[n-1][m-1] < 0) return linf;
	for (int x = i; x < n; x++){
		for (int y = j; y < m; y++){
			if ((x == i) && (y == j)) continue;
			dp[x][y] = linf;
			if (vl[x][y] < 0) continue;
			if (x > i) dp[x][y] = min(dp[x][y], dp[x - 1][y]);
			if (y > j) dp[x][y] = min(dp[x][y], dp[x][y - 1]);
			dp[x][y] += vl[x][y];
		}
	}
	return dp[n - 1][m - 1];
}

void Solve(){
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
            cin >> a[i][j];
		}
	}

	int ans = 2*linf;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)
            ans = min(ans, calc_l(i, j) + calc_r(i, j));
	}
	cout << ans << endl;
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
    cin >> TC;// TC = 1;
    while(TC--) Solve();
    return 0;
}
/*

./-=====>>><<<-------- DEBUG -------->>><<<=====-\.
/.................................................\

+====================== INP ======================+


+====================== OUT ======================+


\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.
*/