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
// I/O
#define open(file, in, out) if (fopen(file in, "r")) {        \
                                freopen(file in, "r", stdin);  \
                                freopen(file out, "w", stdout); \
                            }
#define FAST_IO             std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define setpre(n)           fixed << setprecision(n)
bool endline = false;
template<class T>
istream& operator >> (istream& inp, vector<T>& v){
    for (auto& it : v) inp >> it;
    return inp;
}
template<class T>
ostream& operator << (ostream& out, vector<T>& v){
    for (auto& it : v) out << it << (endline ? "\n" : " ");
    return out;
}
template<class T, class U>
istream& operator >> (istream& inp, pair<T, U>& v){
    inp >> v.F >> v.S;
    return inp;
}
template<class T, class U>
ostream& operator << (ostream& out, pair<T, U>& v){
    out << v.F << ' ' << v.S;
    return out;
}
#define debug(x) cout << #x << " : " << endl << x << endl;
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
const int MAXN = 1e6 + 5 , MAXM = 3e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define left node << 1, tl, tm
#define right node << 1 | 1, tm + 1, tr
#define int long long

int a[MAXN], dp[MAXN][2];
int n, r1, r2, r3, d;
void Solve() {
    cin >> n >> r1 >> r2 >> r3 >> d;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        dp[i][0] = dp[i][1] = linf;
    }
    dp[1][0] = r1 * a[1] + r3;
    dp[1][1] = min(r2, r1 * (a[1] + 1));
    for (int i = 2; i <= n; i++){
        // 0 -> 0
        dp[i][0] = min(dp[i][0], dp[i - 1][0] + d + r1 * a[i] + r3);

		// 0 -> 1
		dp[i][1] = min(dp[i][1], dp[i - 1][0] + d + min(r2, r1 * (a[i] + 1)));
		
		// 1 -> 0
		dp[i][0] = min({
		    dp[i][0],
		    dp[i - 1][1] + 3 * d + r1 * (a[i] + 1) + r3,
		    dp[i - 1][1] + 3 * d + r2 + 2 * r1,
		    dp[i - 1][1] + 3 * d + r1 * (a[i] + 3)
		});
		// 1 -> 1
		dp[i][1] = min({
		    dp[i][1], 
		    dp[i - 1][1] + 3 * d + r1 + r2,
		    dp[i - 1][1] + 3 * d + r1 * (a[i] + 2)
		});
		if(i == n) {
			dp[i][0] = min(dp[i][0], dp[i - 1][1] + 2 * d + r1 * (a[i] + 1) + r3);
		}
    }
    cout << dp[n][0];
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
//    cin >> TC;
    while(TC--) Solve();
    return 0;
}
/*

\/-=====>>><<<-------- DEBUG -------->>><<<=====-\/
/\.............................................../\
+====================== INP ======================+

5 6
1 0 3 3
2 1 2
1 1 4 4
2 1 3
2 1 4
2 3 5


+====================== OUT ======================+


+======================*****======================+
\/...............................................\/
/\-=====>>><<<--------= END =-------->>><<<=====-/\

*/