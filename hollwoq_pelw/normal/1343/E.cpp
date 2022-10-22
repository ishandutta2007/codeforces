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
const int MAXN = 1e5 + 6 , MAXM = 2e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define int long long

int n, m, a, b, c;
vector<vector<int>> adj;

void bfs(int x, vector<int>& d){
    vector<int> vis(n, 0); vis[x] = 1;
    queue<int> qq; qq.push(x); d[x] = 0;
    while(qq.size()){
        int u = qq.front(); qq.pop();
        for (auto v : adj[u]) if (!vis[v]){
            vis[v] = 1;
            d[v] = d[u] + 1;
            qq.push(v);
        }
    }
}

void Solve () {
    cin >> n >> m >> a >> b >> c; a--, b--, c--;
    vector<int> p(m), ps(m+1, 0); cin >> p; sort(all(p));
    for (int i = 0; i < m; i++) ps[i+1] = ps[i] + p[i];
    adj.assign(n, vector<int>());
    for (int i = 0, u, v; i < m; i++){
        cin >> u >> v; u--, v--; 
        adj[u].pb(v); adj[v].pb(u);
    }
    vector<int> da(n), db(n), dc(n);
    bfs(a, da); bfs(b, db); bfs(c, dc);
    int ans = linf;
    for (int i = 0; i < n; i++){
        int x = db[i], y = da[i] + db[i] + dc[i];
        if (y > m) continue;
        ans = min(ans, ps[x] + ps[y]);
    }
    cout << ans << endl;
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
    cin >> TC;
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