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
#define int long long

int siz[MAXN], unh[MAXN], hap[MAXN], p[MAXN];
vector<int> adj[MAXN]; int n, m;

void dfs0(int u, int pr){
    siz[u] = p[u];
    for (auto v:adj[u]){
        if (v != pr){
            dfs0(v, u);
            siz[u] += siz[v];
        }
    }
}

bool dfs(int u, int pr){
    int uh = 0;
    bool x = true;
    for (auto v:adj[u]){
        if (v != pr){
            x &= dfs(v, u);
            uh += unh[v];
        }
    }
    if (uh > siz[u] || uh < unh[u] - p[u]){
        x = false;
    }
    return x;
}

void Solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> p[i];
        adj[i].clear();
    }
    for (int i = 1; i <= n; i++){
        cin >> hap[i];
    }
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs0(1, 1);
    for (int i = 1; i <= n; i++){
        if ((siz[i] - hap[i]) % 2 != 0 || siz[i] < abs(hap[i])){
            cout << "NO\n";
            return;
        }
        unh[i] = (siz[i] - hap[i]) / 2;
    }
    if (dfs(1, 1)){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
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