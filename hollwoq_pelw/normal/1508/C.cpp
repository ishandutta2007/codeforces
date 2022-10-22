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
const int MAXN = 2e5 + 5;
const int inf = 2e9;
const ll linf = 1e18;
#define int long long

struct dsu {
    int par[MAXN];
    dsu() {
        for (int i = 1; i < MAXN; i++)
            par[i] = i;
    }
    int find(int u) {
        return par[u] = (par[u] == u ? u : find(par[u]));
    }
    bool merge(int u, int v) {
        if ((u = find(u)) == (v = find(v)))
            return 0;
        par[u] = v; return 1;
    }
} all, ori;

int n, m, last, lef;
vector<int> adj[MAXN];
set<int> vert;

void dfs(int u) {
    // kuroni-chan baka! bakaaaaaaaaaaaa....!
    sort(all(adj[u]));
    vert.erase(u);
    for (int v = 1; ;) {
        auto it = vert.lower_bound(v);
        if (it == vert.end())
            return ;
        v = *it;
        if (!binary_search(all(adj[u]), v))
             all.merge(u, v), dfs(v), lef --;
        v ++;
    }
}

void Hollwo_Pelw() {
    cin >> n >> m;
    lef = n * (n - 1) / 2 - m;
    vector<pair<int, pii>> edges;
    for (int i = 0, u, v, w; i < m; i++){
        cin >> u >> v >> w;
        adj[u].eb(v);
        adj[v].eb(u);
        last ^= w;
        edges.pb({w, {u, v}});
    }
    for (int i = 1; i <= n; i++) vert.insert(i);
    for (int i = 1; i <= n; i++)
        if (vert.count(i))
            dfs(i);
    if (lef > 0) last = 0;
    sort(all(edges));
    int ans = 0;
    for (auto ed : edges){
        int w = ed.F, u = ed.S.F, v = ed.S.S;
        if (all.merge(u, v)) {
            ans += w;
            ori.merge(u, v);
        }else if(ori.merge(u, v)) {
            last = min(last, w);
        }
    }
    cout << ans + last;
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