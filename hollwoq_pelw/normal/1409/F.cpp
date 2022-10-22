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
const int MAXN = 3e5 + 6 , MAXM = 5e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define int long long

int N, K, dp[202][202][202];
string s, t;

void Solve () {
    cin >> N >> K >> s >> t;
    for (int i = 0; i < 202; i++){
        for (int j = 0; j < 202; j++){
            for (int k = 0; k < 202; k++){
                dp[i][j][k] = -linf;
            }
        }
    }
    dp[0][0][0] = 0;
    for (int i = 1; i <= N; i++){
        for (int j = 0; j <= K; j++){
            for (int k = 0; k <= i; k++){
                // not use operator
                int lj = j, lk = k - (s[i-1] == t[0]); 
                if (lj >= 0 && lk >= 0)
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][lj][lk] + lk * (s[i - 1] == t[1]));
                // turn this to t[0]
                lj = j - 1, lk = k - 1;
                if (lj >= 0 && lk >= 0)
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][lj][lk] + lk * (t[0] == t[1]));
                // turn this to t[1]
                lj = j - 1, lk = k - (t[0] == t[1]);
                if (lj >= 0 && lk >= 0)
                    dp[i][j][k] = max(dp[i][j][k], dp[i-1][lj][lk] + lk);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= K; i++){
        for (int j = 0; j <= N; j++){
            ans = max(ans, dp[N][i][j]);
        }
    }
    cout << ans;
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
//    cin >> TC;
    while(TC--) Solve();
    return 0;
}
/*

./-=====>>><<<-------- DEBUG -------->>><<<=====-\.
/.................................................\
+====================== INP ======================+




+====================== OUT ======================+




+======================*****======================+
\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.

*/