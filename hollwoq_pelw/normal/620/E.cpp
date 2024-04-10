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
const int MAXN = 4e5 + 5 , MAXM = 3e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define left node << 1, tl, tm
#define right node << 1 | 1, tm + 1, tr
// #define int long long

int timer, ord[MAXN], S[MAXN], E[MAXN];
int n, q, c[MAXN];
ll st[MAXN << 2];
int lz[MAXN << 2];
vector<int> adj[MAXN];

void dfs(int u, int p){
    ord[++timer] = u;
    S[u] = timer;
    for (auto v : adj[u])
        if (v != p)
            dfs(v, u);
    E[u] = timer;
}

void build(int node = 1, int tl = 1, int tr = n){
    if (tl == tr){
        st[node] = 1ll << (c[ord[tl]] - 1);
        return ;
    }
    int tm = tl + tr >> 1;
    build(left), build(right);
    st[node] = st[node << 1] | st[node << 1 | 1];
}

void app(int node, int v){
    st[node] = 1ll << (v - 1);
    lz[node] = v;
}

void push(int node){
    if (lz[node]){
        app(node << 1, lz[node]);
        app(node << 1 | 1, lz[node]);
        lz[node] = 0;
    }
}

void upd(int l, int r, int v, int node = 1, int tl = 1, int tr = n){
    if (l > r || l > tr || tl > r) return ;
    if (l <= tl && tr <= r){
        app(node, v);
        return ;
    }
    push(node); int tm = tl + tr >> 1;
    upd(l, r, v, left), upd(l, r, v, right);
    st[node] = st[node << 1] | st[node << 1 | 1];
}

ll query(int l, int r, int node = 1, int tl = 1, int tr = n){
    if (l > r || l > tr || tl > r) return 0;
    if (l <= tl && tr <= r) return st[node];
    push(node); int tm = tl + tr >> 1;
    return query(l, r, left) | query(l, r, right);
}

void Solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 2, u, v; i <= n; i++)
        cin >> u >> v, adj[u].pb(v), adj[v].pb(u);
    dfs(1, 1);
    build();
    while(q--){
        int t, u, val;
        cin >> t >> u;
        if (t == 1){
            cin >> val;
            upd(S[u], E[u], val);
        }else{
            cout << __builtin_popcountll(query(S[u], E[u])) << endl;
        }
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