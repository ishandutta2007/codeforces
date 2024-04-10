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
const int MAXN = 1e5 + 6;
const int inf = 2e9;
const ll linf = 1e18;
const ld eps = 1e-9;
// #define int long long

inline int mul(int a, int b){
    return 1ll * a * b % mod;
}

int binpow(int a, int x){
    int r = 1;
    while(x) {
        if (x&1) r = mul(r, a);
        x >>= 1; a = mul(a, a);
    }
    return r;
}

int n, p[(int) 1e7 + 5], res[MAXN];

struct __initial__ {
    __initial__() {
        for (int i = 1; i <= 1e7; i++)
            p[i] = i;
        for (int i = 2; i <= 1e7; i++){
            if (p[i] == i){
                for (long long j = 1ll * i * i; j <= 1e7; j += i)
                    p[j] = i;
            }
        }
    }
} __init__;

vector<int> adj[MAXN];
int tin[MAXN], tout[MAXN], timer;

int par[MAXN][18];

void dfs(int u, int p){
    tin[u] = ++ timer;

    par[u][0] = p;
    for (int i = 1; i <= 17; i++)
        par[u][i] = par[par[u][i - 1]][i - 1];

    for (auto v : adj[u]) if (v != p) {
        dfs(v, u);
    }

    tout[u] = timer;
}

bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int lca(int u, int v){
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;

    for (int i = 17; i >= 0; i--)
        if (!is_ancestor(par[u][i], v))
            u = par[u][i];

    return par[u][0];
}

struct upd_query {
    int id, c;
    upd_query() {}
    upd_query(int _id, int _c)
        : id(_id), c(_c) {}
    bool operator < (upd_query & oth) {
        return c > oth.c;
    }
};

map<int, vector<upd_query>> upd_queries;

struct query {
    int u, v, c, id;
    query() {}
    query(int _u, int _v, int _c, int _id)
        : u(_u), v(_v), c(_c), id(_id) {}
    bool operator < (query & oth) {
        return c > oth.c;
    }
};

map<int, vector<query>> queries;

int bit[MAXN];

inline void _add(int x, int v){
    for (; x < MAXN; x += x & (-x))
        bit[x] += v;
}

inline void add(int u, int v){
    _add(tin[u], v), _add(tout[u] + 1, -v);
}

inline int _get(int x) {
    int r = 0;
    for (; x; x -= x & (-x))
        r += bit[x];
    return r;
}

inline int get(int u, int v){
    return _get(tin[v]) - _get(tin[u]);
}

void process(int p, vector<query> & q){
    vector<upd_query> uq = upd_queries[p];
    if (uq.empty()) return ;
    sort(all(q)), sort(all(uq));
    int j = 0;
    for (auto qq : uq){
        add(qq.id, qq.c);
    }
    for (auto qq : q) {
        int x = qq.c;
        if (x != uq[0].c){
            while (j < uq.size() && uq[j].c > x) j++;
            for (int i = 0; i < j; i++)
                add(uq[i].id, x - uq[i].c), uq[i].c = x;
        }
        res[qq.id] = mul(res[qq.id], binpow(p, get(qq.u, qq.v)));
    }
    for (auto qq : uq){
        add(qq.id, -qq.c);
    }
}

void Hollwo_Pelw() {
    cin >> n;
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v, adj[u].pb(v), adj[v].pb(u);
    }
    for (int i = 1, a; i <= n; i++){
        cin >> a;
        while (a > 1) {
            int x = p[a], c = 0;
            while (a % x == 0)
                a /= x, c++;
            upd_queries[x].emplace_back(i, c);
        }
    }
    {
        tin[0] = timer;
        dfs(1, 0);
        tout[0] = timer;
    }
    int q; cin >> q;
    for (int i = 1, u, v, a; i <= q; ++i){
        cin >> u >> v >> a;
        int l = lca(u, v);
        while (a > 1) {
            int x = p[a], c = 0;
            while (a % x == 0)
                a /= x, c++;
            queries[x].emplace_back(par[l][0], v, c, i);
            queries[x].emplace_back(l, u, c, i);
        }
        res[i] = 1;
    }
    for (auto qq : queries){
        process(qq.F, qq.S);
    }
    for (int i = 1; i <= q; i++)
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