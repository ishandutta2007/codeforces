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

void FAST_IO(string filein = "", string fileout = ""){
    if (fopen(filein.c_str(), "r")){
        freopen(filein.c_str(), "r", stdin);
        freopen(fileout.c_str(), "w", stdout);
    }
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

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

// constant
const int allmod[3] = {(int) 1e9 + 7, 998244353, (int) 1e9 + 9};
const int mod = allmod[1];
const int MAXN = 5e5 + 5;
const int inf = 2e9;
const ll linf = 1e18;
// #define int long long

struct edge {
    int u, v, w;
    int nxt(int x) {
        return x ^ u ^ v;
    }
} e[MAXN];

int n, q;
vector<int> adj[MAXN];

pii find_diameter(int u, int p){
    pii res = {0, u};
    for (auto i : adj[u]) {
        int v = e[i].nxt(u);
        if (v == p) continue;
        pii tmp = find_diameter(v, u);
        tmp.F ++; res = max(res, tmp);
    }
    // cout << "subtree " << u << " : " << res << endl;
    return res;
}

struct Omg_This_Is_Something_LOL {
    int par[MAXN], alv[MAXN], dep[MAXN], r;
    int ord[MAXN], S[MAXN], E[MAXN], timer;
    
    void init(int _r){
        r = _r;
        dfs(r, -1);
        build();
        // for (int i = 1; i <= n; i++){
        //     cout << ord[i] << ' ';
        // }
        // cout << endl;
        // for (int i = 1; i <= n; i++){
        //     cout << S[i] << ' ' << E[i] << endl;
        // }
        // for (int i = 1; i <= n; i++){
        //     cout << "[" << query(i, i)[0] << ' ' << query(i, i)[1] << "] ";
        // }
        // cout << endl;
    }
    
    void dfs(int u, int p){
        par[u] = p;
        ord[++ timer] = u;
        S[u] = timer;
        for (auto i : adj[u]) {
            int v = e[i].nxt(u);
            if (v == p) continue;
            dep[v] = dep[u] + 1;
            alv[v] = alv[u] ^ e[i].w;
            dfs(v, u);
        }
        E[u] = timer;
    }
    
    #define left node << 1, tl, tm
    #define right node << 1 | 1, tm + 1, tr
    
    pii st[MAXN << 2];
    int lz[MAXN << 2];
    
    pii join(pii l, pii r){
        return pii(max(l.F, r.F), max(l.S, r.S));
    }
    
    void app(int node){
        swap(st[node].F, st[node].S);
        lz[node] ^= 1;
    }
    
    void push(int node){
        if (lz[node]) {
            app(node << 1);
            app(node << 1 | 1);
            lz[node] = 0;
        }
    }
    
    void build(int node = 1, int tl = 1, int tr = n){
        if (tl == tr) {
            st[node] = {dep[ord[tl]], 0};
            if (alv[ord[tl]])
                app(node);
            return ;
        }
        int tm = tl + tr >> 1; build(left), build(right);
        st[node] = join(st[node << 1], st[node << 1 | 1]);
    }
        
    void upd(int l, int r, int node = 1, int tl = 1, int tr = n){
        if (l > r || l > tr || tl > r) return ;
        if (l <= tl && tr <= r) return app(node);
        int tm = tl + tr >> 1; push(node);
        upd(l, r, left), upd(l, r, right);
        st[node] = join(st[node << 1], st[node << 1 | 1]);
    }
    
    int query_ans(int u, int v){
        if (dep[u] < dep[v]) swap(u, v);
        // process in substree u
        upd(S[u], E[u]);
        
        // cout << "Root " << r << "  flip subtree " << u << endl;
        // for (int i = 1; i <= n; i++){
        //     cout << "[" << query(i, i)[0] << ' ' << query(i, i)[1] << "] ";
        // }
        // cout << endl;
        
        return st[1].F;
    }
} rt1, rt2;

void Hollwo_Pelw() {
    cin >> n;
    for (int i = 1; i < n; i++){
        cin >> e[i].u >> e[i].v >> e[i].w;
        adj[e[i].u].pb(i);
        adj[e[i].v].pb(i);
    }
    int r1 = find_diameter(1, -1).S;
    int r2 = find_diameter(r1, -1).S;
    rt1.init(r1);
    rt2.init(r2);
    cin >> q;
    for (int i = 1, id; i <= q; i++){
        cin >> id;
        int u = e[id].u, v = e[id].v;
        cout << max(rt1.query_ans(u, v), rt2.query_ans(u, v)) << "\n";
    }
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