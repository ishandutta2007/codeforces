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
const int MAXN = 2e5 + 6 , MAXM = 2e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
// #define int long long
int n, vl[MAXN], ans;
vector<int> adj[MAXN];
map<int, int> dp[MAXN];
void dfs(int u, int p){
    for (auto v : adj[u]){
        if (v == p) continue;
        dfs(v, u);
        if (__gcd(vl[u], vl[v]) == 1)
            continue;
        for (auto [x, p1] : dp[u]){
            for (auto [y, p2] : dp[v]){
                if (__gcd(x, y) != 1)
                    ans = max(ans, p1 + p2);
            }
        }
        for (auto [x, p] : dp[v]){
            int tmp = __gcd(x, vl[u]);
            if (tmp != 1){
                dp[u][tmp] = max(dp[u][tmp], p + 1);
            }
        }
    }
}

void Solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> vl[i];
        if (vl[i] != 1){
            dp[i][vl[i]] = 1;
            ans = 1;
        }
    }
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v; 
        adj[u].pb(v); 
        adj[v].pb(u);
    }
    dfs(1, 1); 
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
1 - 2 - 3 - 5 - 7 - 11 - 13 - 17 - 19 - 23 - 29 - 31 - 37 - 41 - 43 - 47 - 53
0   1   2   3   4   5    6    7    8    9    10   11   12   13   14   15   16 => 65000 * 100
./-=====>>><<<-------- DEBUG -------->>><<<=====-\.
/.................................................\
       1*
        \
         5
        / \
       4   6
        \
         3
          \
           2*

+====================== INP ======================+


+====================== OUT ======================+


\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.

*/