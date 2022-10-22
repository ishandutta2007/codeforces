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
int N, K;
vector<int> adj[MAXM];
bool soc[MAXM];
int siz[MAXM];

void pre(int u, int p){
    siz[u] = soc[u];
    for (auto v:adj[u]){
        if (v != p){
            pre(v, u);
            siz[u] += siz[v];
        }
    }
}
void sub(int u, int p, vector<int> &vec){
    if (soc[u]){
        soc[u] = false;
        vec.eb(u);
    }
    for (auto v:adj[u]){
        if (v != p){
            sub(v, u, vec);
        }
    }
}
void dfs(int u, int p){
    int bad = -1;
    for (auto v:adj[u]){
        if (v != p){
            if (siz[v] > K){
                bad = v;
                break;
            }
        }
    }
    if (bad != -1){
        dfs(bad, u);
        return ;
    }
    cout << 1 << endl << u << endl;
    vector<int> ans;
    if (soc[u]) ans.eb(u);
    for (auto v:adj[u]){
        if (v != p){
            sub(v, u, ans);
        }
    }
    for (int i = 1; i <= N; i++){
        if (i != u && soc[i]){
            ans.eb(i);
        }
    }
    for (int i = 0; i < K; i++){
        cout << ans[i] << ' ' << ans[i+K] << ' ' << u << endl;
    }
}

void Solve(){
    cin >> N >> K;
    for (int i = 1, u, v; i < N; i++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 1, x; i <= 2*K; i++){
        cin >> x; soc[x] = true;
    }
    pre(1, 1);
    dfs(1, 1);
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