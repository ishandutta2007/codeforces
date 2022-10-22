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
const int mod1 = 998244353, mod = 1e9+7;
const int MAXN = 100005, MAXM = 200010;
// code
//#define int long long

int dp[2020][2020];
int cntS[2020][26], cntT[2020][26];
void Solve() {
    string s, t; int n;
    cin >> n >> s >> t;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 26; j++){
            cntS[i+1][j] = cntS[i][j] + (s[i] == j + 'a');
            cntT[i+1][j] = cntT[i][j] + (t[i] == j + 'a');
        }
    }
    for (int i = 0; i < 26; i++){
        if (cntS[n][i] != cntT[n][i]) {
            cout << -1 << endl; return;
        }
    }

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 0;

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
            if (s[i] == t[j]){
                bool check = true;
                for (int k = 0; k < 26; k++){
                    check &= (cntS[i][k] <= cntT[j][k]);
                }
                if (check){
                    dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + 1);
                }
            }
        }
    }
    cout << n - dp[n][n] << endl;
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO;
    int TC = 1;
    cin >> TC;
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