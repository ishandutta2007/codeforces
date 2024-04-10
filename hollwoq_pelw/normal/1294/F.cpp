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
pair<int, vector<int>> dp[MAXM][4];
vector<int> adj[MAXM];

void dfs(int u, int p){
    for (int i = 0; i < 4; i++)
        dp[u][i] = {-1e9, vector<int>()};
    dp[u][0].F = 0;
    for (auto v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        for (int j = 3; j >= 0; j--){
            for (int k = 1; j + k < 4; k++){
                if (dp[u][j].F + dp[v][k].F + (k < 3) > dp[u][j + k].F) {
                    dp[u][j + k].F = dp[u][j].F + dp[v][k].F + (k < 3);
                    dp[u][j + k].S = dp[u][j].S;
                    for (auto it: dp[v][k].S)
                        dp[u][j + k].S.pb(it);
                }
            }
        }
    }
    for (int j = 2; j >= 0; j--)
        if (dp[u][j].F > dp[u][j + 1].F) {
            dp[u][j + 1] = dp[u][j];
            dp[u][j + 1].S.pb(u);
        }
}

void Solve() {
    int n; cin >> n;
    for (int i = 1, a, b; i < n; i++){
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1, 1);
    cout << dp[1][3].F << endl;
    for (auto v : dp[1][3].S)
        cout << v << ' ';
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