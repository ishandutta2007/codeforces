/*
 /+===================================================+\
//+---------------------------------------------------+\\
|.|\\...>>>>>>> Hollwo_Pelw's 2nd template<<<<<<<...//|.|
\\+---------------------------------------------------+//
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

void FAST_IO(string filein, string fileout);
void Hollwo_Pelw();

signed main(){
    FAST_IO("input.inp", "output.out");
    int testcases = 1;
    // cin >> testcases;
    for (int test = 1; test <= testcases; test++){
        // cout << "Case #" << test << ": ";
        Hollwo_Pelw();
    }
    return 0;
}

void FAST_IO(string filein = "", string fileout = ""){
    if (fopen(filein.c_str(), "r")){
        freopen(filein.c_str(), "r", stdin);
        freopen(fileout.c_str(), "w", stdout);
    }
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

// constant
const int allmod[3] = {(int) 1e9 + 7, 998244353, (int) 1e9 + 9};
const int mod = allmod[1];
const int MAXN = 2e5 + 6;
const int inf = 2e9;
const ll linf = 1e18;
#define int long long

struct edge {
    int u, v, w, id, chk;
    bool operator < (const edge & oth) const {
        return w < oth.w;
    }
    int nxt(int x){
        return x ^ u ^ v;
    }
} ed[MAXN];

struct disjoint_set {
    int par[MAXN];
    
    disjoint_set () {
        for (int i = 1; i < MAXN; i++)
            par[i] = i;
    }
    
    int find(int u) {
        return par[u] = (par[u] == u ? u : find(par[u]));
    }
    
    bool join(int u, int v){
        u = find(u), v = find(v);
        if (u == v) return 0;
        par[u] = v; return 1;
    }
} dsu;

int n, m, res[MAXN], ans;
vector<int> adj[MAXN];

int par[MAXN][20], mx[MAXN][20], dep[MAXN];

void build(int u, int ff){
    int p, w;
    if (ff == -1)
        p = 1, w = -inf;
    else 
        p = ed[ff].nxt(u), w = ed[ff].w;
    par[u][0] = p, mx[u][0] = w;
    for (int i = 1, v; i < 20; i++){
        v = par[u][i - 1]; par[u][i] = par[v][i - 1];
        mx[u][i] = max(mx[u][i - 1], mx[v][i - 1]);
    }
    for (auto i : adj[u]) if (i != ff) {
        int v = ed[i].nxt(u);
        // cout << v << " is child of " << u << endl;
        dep[v] = dep[u] + 1;
        build(v, i);
    }
}

int query(int u, int v){
    // cout << "??? " << u << ' ' << v << endl;
    int res = -inf;
    if (dep[v] > dep[u])
        swap(u, v);
    for (int i = 19; i >= 0; i--){
        if (dep[par[u][i]] < dep[v])
            continue;
        res = max(res, mx[u][i]);
        u = par[u][i];
    }
    if (u == v) return res;
    for (int i = 19; i >= 0; i--){
        if (par[u][i] != par[v][i]) {
            res = max({res, mx[u][i], mx[v][i]});
            u = par[u][i], v = par[v][i];
        }
    }
    // cout << max({res, mx[u][0], mx[v][0]}) << endl;
    return max({res, mx[u][0], mx[v][0]});
}


void Hollwo_Pelw() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        cin >> ed[i].u >> ed[i].v >> ed[i].w;
        ed[i].id = i;
    }
    sort(ed + 1, ed + m + 1);
    for (int i = 1; i <= m; i++){
        if (dsu.join(ed[i].u, ed[i].v)) {
            ans += ed[i].w;
            ed[i].chk = 1;
            adj[ed[i].u].pb(i);
            adj[ed[i].v].pb(i);
        }
    }
    build(1, -1);
    for (int i = 1; i <= m; i++){
        if (ed[i].chk) 
            res[ed[i].id] = ans;
        else 
            res[ed[i].id] = ans + ed[i].w - query(ed[i].u, ed[i].v);
    }
    for (int i = 1; i <= m; i++)
        cout << res[i] << "\n";
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