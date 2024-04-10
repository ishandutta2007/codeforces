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
const int MAXN = 2e5 + 6 , MAXM = 5e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define int long long

int n, dp[MAXN][5];
string s, t = "abc";

void add(int i, char c){
    for (int j = 0; j <= 3; j++){
        if (j < 3 && c == t[j]){
            (dp[i + 1][j + 1] += dp[i][j]) %= mod;
        }
        (dp[i + 1][j] += dp[i][j]) %= mod;
    }
}

void Solve () {
    cin >> n >> s;
    dp[0][0] = 1;
    for (int i = 0; i < n; i++){
        if (s[i] != '?'){
            add(i, s[i]);
        }else{
            for (int k = 0; k < 3; k++)
                add(i, t[k]);
        }
    }
    cout << dp[n][3];
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

5 5 4

1 2 4 2 1
4 2 2 1 1 -> 4 2

3 5 1 2 4
5 4 3 2 1 -> 5 4

1 5 7 1 2
7 5 2 1 1 -> 7 5

3 8 7 1 2
8 7 3 2 1 -> 8 7

8 4 7 1 6
8 7 6 4 1 -> 8 7

++++ FAKE_ANS = 57 = 1 (mod 4)

+====================== OUT ======================+




+======================*****======================+
\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.

*/