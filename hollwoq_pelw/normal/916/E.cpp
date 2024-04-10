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

void FAST_IO(string filein = "", string fileout = ""){
    if (fopen(filein.c_str(), "r")){
        freopen(filein.c_str(), "r", stdin);
        freopen(fileout.c_str(), "w", stdout);
    }
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
    #ifdef hollwo_pelw_local
        FAST_IO("input.inp", "output.out");
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
const int MAXN = 1e5 + 5;
const int inf = 2e9;
const ll linf = 1e18;
#define int long long

int n, a[MAXN], root = 1, q;

struct segment_tree {
    #define left id << 1, tl, tm
    #define right id << 1 | 1, tm + 1, tr
    struct node {
        int val, lz;
        node () {}
        node (int _val, int _lz) 
            : val(_val), lz(_lz) {}
        friend node operator + (node l, node r) {
            return node(l.val + r.val, 0);
        }
    } st[MAXN << 2];
 
    void apply(int id, int tl, int tr, int v){
        st[id].val += (tr - tl + 1) * v;
        st[id].lz += v;
    }
 
    void push(int id, int tl, int tr) {
        if (st[id].lz){
            int tm = tl + tr >> 1;
            apply(left, st[id].lz);
            apply(right, st[id].lz);
        }
        st[id].lz = 0;
    }
 
    void upd(int l, int r, int v, int id, int tl, int tr){
        if (l > r || l > tr || tl > r)
            return ;
        if (l <= tl && tr <= r)
            return apply(id, tl, tr, v);
        push(id, tl, tr); int tm = tl + tr >> 1;
        upd(l, r, v, left), upd(l, r, v, right);
        st[id] = st[id << 1] + st[id << 1 | 1];
    }
 
    void upd(int l, int r, int v){
        upd(l, r, v, 1, 1, n);
    }
 
    int query(int l, int r, int id, int tl, int tr){
        if (l > r || l > tr || tl > r)
            return 0;
        if (l <= tl && tr <= r) 
            return st[id].val;
        push(id, tl, tr); int tm = tl + tr >> 1;
        return query(l, r, left) + query(l, r, right);   
    }
 
    int query(int l, int r) {
        return query(l, r, 1, 1, n);
    }
} st;

int S[MAXN], E[MAXN], ord[MAXN];
int dep[MAXN], par[MAXN][18], timer;

vector<int> adj[MAXN];

void dfs(int u, int p){
    S[u] = ++ timer;
    ord[timer] = u; 
    par[u][0] = p;
    for (int i = 1; i < 18; i++)
        par[u][i] = par[par[u][i - 1]][i - 1];
    for (auto v : adj[u]) if (v != p) {
        dep[v] = dep[u] + 1;
        dfs(v, u); 
    }
    E[u] = timer;
}

bool is_ancestor(int u, int v){ // u is ancestor of v
    return S[v] >= S[u] && E[u] >= E[v];
}

int lca(int u, int v){
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = 17; i >= 0; i--){
        if (!is_ancestor(par[u][i], v)){
            u = par[u][i];
        }
    }
    return par[u][0];
}

int nth_par(int u, int n){
    for (int i = 17; i >= 0; i--){
        if (n >> i & 1)
            u = par[u][i];
    }
    return u;
}

void Hollwo_Pelw(){
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1, u, v; i < n; i++)
        cin >> u >> v, adj[u].pb(v), adj[v].pb(u);
    dfs(1, 1);
    for (int i = 1; i <= n; i++)
        st.upd(i, i, a[ord[i]]);
    for (int i = 1, t, r, x; i <= q; i++){
        cin >> t;
        if (t == 1) {
            cin >> root;
        }else if (t == 2){
            int u, v;
            cin >> u >> v >> x;
            r = lca(u, v) ^ lca(root, u) ^ lca(root, v);
            if (is_ancestor(r, root)){
                st.upd(1, n, x);
                if (r != root){
                    r = nth_par(root, dep[root] - dep[r] - 1);
                    st.upd(S[r], E[r], -x);
                }
            }else{
                st.upd(S[r], E[r], x);
            }
        }else{
            cin >> r;
            if (is_ancestor(r, root)){
                x = st.query(1, n);
                if (r != root){
                    r = nth_par(root, dep[root] - dep[r] - 1);
                    x -= st.query(S[r], E[r]);
                }
            }else{
                x = st.query(S[r], E[r]);
            }
            cout << x << "\n";
        }
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