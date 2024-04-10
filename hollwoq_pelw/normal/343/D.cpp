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
#define debug(x)            cout << #x << " : " << endl << x << endl;
#define Ptest(x)            return cout << x << endl, (void) 0;
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
const int MAXN = 5e5 + 5 , MAXM = 3e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define left node << 1, tl, tm
#define right node << 1 | 1, tm + 1, tr
// #define int long long

int timer, ord[MAXN], S[MAXN], E[MAXN], par[MAXN];
vector<int> adj[MAXN];

void dfs(int u, int p){
    par[u] = p;
    ord[++timer] = u;
    S[u] = timer;
    for (auto v : adj[u])
        if (v != p)
            dfs(v, u);
    E[u] = timer;
}

int st[MAXN << 2], lz[MAXN << 2], n, q;
 
void add(int val, int node, int tl, int tr){
    st[node] = val * (tr - tl + 1);
    lz[node] = val;
}
 
void push(int node, int tl, int tr){
    int tm = (tl + tr) >> 1;
    if (lz[node] != -1){
        add(lz[node], left);
        add(lz[node], right);
    }
    lz[node] = -1;
}
 
int join(int x, int y){
    return x + y;
}
 
void build(int node = 1, int tl = 1, int tr = n){
    if (tl == tr){
        st[node] = 1;
        lz[node] = -1;
        return ;
    }
    int tm = (tl + tr) >> 1;
    build(left);
    build(right);
    st[node] = join(st[node << 1], st[node << 1 | 1]);
}
 
void upd(int l, int r, int val, int node = 1, int tl = 1, int tr = n){
    if (l > r || tl > r || l > tr)
        return ;
    if (l <= tl && tr <= r){
        add(val, node, tl, tr);
        return ;
    }
    push(node, tl, tr); int tm = (tl + tr) >> 1;
    upd(l, r, val, left);
    upd(l, r, val, right);
    st[node] = join(st[node << 1], st[node << 1 | 1]);
}
 
int query(int l, int r, int node = 1, int tl = 1, int tr = n){
    if (tl > r || l > tr || l > r) return 0;
    if (l <= tl && tr <= r) return st[node];
    push(node, tl, tr); 
    int tm = (tl + tr) >> 1;
    return join(query(l, r, left), 
                query(l, r, right));
}

void Solve() {
    for (int i = 1; i < MAXN << 2; i++)
        lz[i] = -1;
    cin >> n;
    for (int i = 2, u, v; i <= n; i++)
        cin >> u >> v, adj[u].pb(v), adj[v].pb(u);
    dfs(1, -1);
    build();
    cin >> q;
    while(q--){
        int t, u;
        cin >> t >> u;
        if (t == 1){
            if (par[u] != -1)
                if (query(S[par[u]], E[par[u]]))
                    upd(S[par[u]], S[par[u]], 1);
            upd(S[u], E[u], 0);
        }
        if (t == 2)
            upd(S[u], S[u], 1);
        if (t == 3)
            cout << (query(S[u], E[u]) == 0) << endl;
    }
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
    // cin >> TC;
    while(TC--) Solve();
    return 0;
}
/*

\/-=====>>><<<-------- DEBUG -------->>><<<=====-\/
/\.............................................../\
+====================== INP ======================+


+====================== OUT ======================+


+======================*****======================+
\/...............................................\/
/\-=====>>><<<--------= END =-------->>><<<=====-/\

*/