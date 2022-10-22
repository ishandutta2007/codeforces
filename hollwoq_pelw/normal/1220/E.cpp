/*
 /+===================================================+\
//+---------------------------------------------------+\
|.|\...>>>>>>> Hollwo_Pelw's 2nd template<<<<<<<...//|.|
\+---------------------------------------------------+//
 \+===================================================+/
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
// I/O
#define setpre(n)           fixed << setprecision(n)
#define Ptest(x)            return cout << x << endl, (void) 0;
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
void debug(){
    cout << endl;
}
template <typename H, typename... T>
void debug(H a, T... b){
    cout << a << ' ';
    debug(b...);
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

void FAST_IO(string filein = "", string fileout = "", string fileerr = ""){
    if (fopen(filein.c_str(), "r")){
        freopen(filein.c_str(), "r", stdin);
        freopen(fileout.c_str(), "w", stdout);
        #ifdef hollwo_pelw_local
            freopen(fileerr.c_str(), "w", stderr);
        #endif
    }
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
    #ifdef hollwo_pelw_local
        FAST_IO("input.inp", "output.out", "error.err");
        auto start = chrono::steady_clock::now();
    #else
        FAST_IO(".inp", ".out");
    #endif
    int testcases = 1;
    // cin >> testcases;
    for (int test = 1; test <= testcases; test++){
        // cout << "Case #" << test << ": ";
        Hollwo_Pelw();
    }
    #ifdef hollwo_pelw_local
        auto end = chrono::steady_clock::now();
        cout << endl;
        cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
    #endif
    return 0;
}

// constant
const int allmod[3] = {(int) 1e9 + 7, 998244353, (int) 1e9 + 9};
const int mod = allmod[0];
const int MAXN = 2e5 + 5;
const int inf = 2e9;
const ll linf = 1e18;
const ld eps = 1e-9;
#define int long long

int n, m, w[MAXN], sz[MAXN], root;
vector<int> adj[MAXN], g[MAXN];
int dp[MAXN];

int par[MAXN], tin[MAXN], low[MAXN], timer;
set<pii> bridges;

int find(int u){
    return par[u] = (par[u] == u ? u : find(par[u]));
}

bool merge(int u, int v){
    u = find(u), v = find(v);
    if (u == v) return 0;
    par[u] = v; 
    sz[v] += sz[u];
    w[v] += w[u];
    return 1;
}

void dfs(int u, int p){
    tin[u] = low[u] = ++timer;
    for (auto v : g[u]){
        if (v == p) continue;
        if (tin[v]){
            low[u] = min(low[u], tin[v]);
        }else{
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u]){
                // cout << u << ' ' << v << endl;
                bridges.insert({u, v});
            }else{
                // cout << u << ' ' << v << endl;
                merge(u, v);
            }
        }
    }
}

void ndfs(int u, int p){
    dp[u] = w[u];
    for (auto v : adj[u]) if (v != p){
        ndfs(v, u);
        if (sz[v] > 1){
            dp[u] += dp[v];
            dp[v] = 0;
            sz[u] += sz[v];
        }
    }
}

int ans, d[MAXN];

void dfsdfs(int u, int p, int t){
    d[u] = dp[u] + t;
    ans = max(ans, d[u]);
    for (auto v : adj[u]) if (v != p){
        dfsdfs(v, u, d[u]);
    }
}

void Hollwo_Pelw(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> w[i], par[i] = i, sz[i] = 1;
    }
    vector<int> edges;
    for (int i = 1, u, v; i <= m; i++){
        cin >> u >> v, g[u].pb(v), g[v].pb(u);
    }
    dfs(1, -1);
    cin >> root;
    root = find(root);
    for (auto uv : bridges){
        int u = find(uv.F), v = find(uv.S);
        adj[u].pb(v), adj[v].pb(u);
    }
    ndfs(root, -1);
    // for (int i = 1; i <= n; i++)
    //     cout << w[i] << ' ';
    dfsdfs(root, -1, 0);
    cout << ans;
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