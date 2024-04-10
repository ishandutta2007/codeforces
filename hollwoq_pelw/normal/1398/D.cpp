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
const int MAXN = 1e5 + 6 , MAXM = 1e4 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define int long long

int R, B, G, dp[202][202][202];

void Solve(){
    cin >> R >> B >> G;
    vector<int> a(R), b(B), c(G);
    cin >> a >> b >> c;
    sort(rall(a)); sort(rall(b)); sort(rall(c));
    int ans = 0;
    for (int i = 0; i <= R; i++){
        for (int j = 0; j <= B; j++){
            for (int k = 0; k <= G; k++){
                dp[i][j][k] = 0;
            }
        }
    }
    for (int i = 1; i <= R; i++){
        for (int j = 1; j <= B; j++){
            dp[i][j][0] = dp[i-1][j-1][0] + a[i-1] * b[j-1];
            ans = max(ans, dp[i][j][0]);
        }
    }

    for (int i = 1; i <= R; i++){
        for (int k = 1; k <= G; k++){
            dp[i][0][k] = dp[i-1][0][k-1] + a[i-1] * c[k-1];
            ans = max(ans, dp[i][0][k]);
        }
    }

    for (int k = 1; k <= G; k++){
        for (int j = 1; j <= B; j++){
            dp[0][j][k] = dp[0][j-1][k-1] + b[j-1] * c[k-1];
            ans = max(ans, dp[0][j][k]);
        }
    }

    for (int i = 1; i <= R; i++){
        for (int j = 1; j <= B; j++){
            for (int k = 1; k <= G; k++){
                dp[i][j][k] = max({dp[i-1][j-1][k] + a[i-1] * b[j-1],
                                    dp[i][j-1][k-1] + c[k-1] * b[j-1],
                                    dp[i-1][j][k-1] + a[i-1] * c[k-1]});
                ans = max(ans, dp[i][j][k]);
            }
        }
    }
    cout << ans << endl;
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

+===+===+===+===+===+== INP ==+===+===+===+===+===+


+===+===+===+===+===+== OUT ==+===+===+===+===+===+


\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.

*/