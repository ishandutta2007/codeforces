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
#define print(val, stt)     return cout << val << endl, stt;
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

int n, m, mx[2020][2020], up[2020][2020], dw[2020][2020];
char s[2020][2020]; int ans, cnt;
void Solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> s[i][j];
            if (i == 1)
                up[1][j] = dw[n][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++){
        cnt = 0;
        for (int j = 1; j <= m; j++){
            if (j == 1 || s[i][j] == s[i][j-1]) cnt ++;
            else cnt = 1;
            mx[i][j] = cnt;
        }
        cnt = 0;
        for (int j = m; j >= 1; j--){
            if (j == m || s[i][j] == s[i][j+1]) cnt ++;
            else cnt = 1;
            mx[i][j] = min(cnt, mx[i][j]);
        }
    }

    for (int j = 1; j <= m; j++){
        for (int i = 1; i < n; i++){
            if (s[i][j] != s[i+1][j]) up[i+1][j] = 1;
            else up[i+1][j] = min(up[i][j], mx[i][j]) + 1;
        }
        for (int i = n; i > 1; i--){
            if (s[i][j] != s[i-1][j]) dw[i-1][j] = 1;
            else dw[i-1][j] = min(dw[i][j], mx[i][j]) + 1;
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            ans += min({mx[i][j], up[i][j], dw[i][j]});
        }
    }
    cout << ans;

}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
    //cin >> TC;
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