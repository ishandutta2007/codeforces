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
const int MAXN = 1e5 + 5 , MAXM = 3e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define left node << 1, tl, tm
#define right node << 1 | 1, tm + 1, tr
// #define int long long

bool vis[MAXN];
vector<int> adj[MAXN], g[MAXN];
int sz[MAXN], tot_sz;

void get_sz(int u, int p){
    sz[u] = 1;
    for (auto v : g[u]) if (v != p && !vis[v]){
        get_sz(v, u);
        sz[u] += sz[v];
    }
}

int find_cen(int u, int p){
    for (auto v : g[u]) if (v != p && !vis[v]){
        if (sz[v] > tot_sz / 2) return find_cen(v, u);
    }
    return u;
}

int get_cen(int u){
    get_sz(u, -1);
    tot_sz = sz[u];
    return find_cen(u, -1);
}

void centroid(int u){
    vis[u] = 1;
    for (auto v : g[u]) if (!vis[v]){
        int nxt_cen = get_cen(v);
        adj[u].pb(nxt_cen);
        centroid(nxt_cen);
    }
}

const int LG = 22;
int n, a[MAXN];
long long ans, cnt[MAXN][LG][2];
// void get_count(int u){
//     for (auto v : adj[u]){
//         get_count(v);
//         for (int bt = 0; bt < LG; bt++){
//             int val = a[u] >> bt & 1;
//             for (int f = 0; f < 2; f++)
//                 cnt[u][bt][f] += cnt[v][bt][f ^ val];
//         }
//     }
//     for (int bt = 0; bt < LG; bt++){
//         cnt[u][bt][a[u] >> bt & 1] ++;
//     }
// }

void dfs(int u, int bt, int p){
    int val = a[u] >> bt & 1;
    cnt[u][bt][val] ++;
    for (auto v : g[u]) if (v != p){
        dfs(v, bt, u);
        for (int f = 0; f < 2; f++){
            ans += 1ll * cnt[v][bt][f ^ 1] * cnt[u][bt][f] * (1ll << bt);
            // cout << "sub " << v << " of " << u << " : " << 1ll * cnt[v][bt][f ^ 1] * cnt[u][bt][f] * (1ll << bt) << endl;
        }
        for (int f = 0; f < 2; f++){
            cnt[u][bt][f] += cnt[v][bt][val ^ f];
        }
    }
}

void Solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], ans += a[i];
    for (int i = 1, u, v; i < n; i++)
        cin >> u >> v, g[u].pb(v), g[v].pb(u);
    // int root = get_cen(1);
    // centroid(root);
    // for (int i = 1; i <= n; i++){
    //     cout << "Node " << i << " : ";
    //     for (auto v : adj[i])
    //         cout << v << ' ';
    //     cout << endl;
    // }
    // get_count(root);
    for (int i = 0; i < LG; i++){
        dfs(1, i, 1);
    }
    cout << ans;
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
//    cin >> TC;
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