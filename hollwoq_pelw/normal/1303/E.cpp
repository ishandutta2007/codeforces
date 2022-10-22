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
//#define int long long

vector<vector<int>> nxt;
string s, t;
bool calc(string a, string b) {
    vector<vector<int>> dp(sz(a) + 1, vector<int>(sz(b) + 1, inf));
    dp[0][0] = 0;
    for(int i = 0; i < sz(a) + 1; i++) for(int j = 0; j < sz(b) + 1; j++) {
        if(dp[i][j] > sz(s))
            continue;
        
        int len = dp[i][j];
        if(i < sz(a) && nxt[len][a[i] - 'a'] < inf) {
            dp[i + 1][j] = min(dp[i + 1][j], nxt[len][a[i] - 'a'] + 1);
        }
        if(j < sz(b) && nxt[len][b[j] - 'a'] < inf) {
            dp[i][j + 1] = min(dp[i][j + 1], nxt[len][b[j] - 'a'] + 1);
        }
    }
    return dp[sz(a)][sz(b)] < inf;
}

void Solve() {
    cin >> s >> t;
    nxt.assign(sz(s) + 1, vector<int>(26, inf));
    for(int i = sz(s) - 1; i >= 0; i--) {
        nxt[i] = nxt[i + 1];
        nxt[i][s[i] - 'a'] = i;
    }
    
    for(int i = 0; i < sz(t); i++) {
        if(calc(t.substr(0, i), t.substr(i))){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;    
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
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