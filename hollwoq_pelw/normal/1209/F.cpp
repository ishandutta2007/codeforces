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
const int MAXN = 1e6 + 6;
const int inf = 2e9;
const ll linf = 1e18;
#define int long long

int n, m, cnt;
vector<pii> adj[MAXN];

void add_edge(int u, int v, int i){
    if (i < 10){
        adj[u].emplace_back(i, v);
        adj[v].emplace_back(i, u);
        return ;
    }

    vector<int> dig;
    while (i)
        dig.push_back(i % 10), i /= 10;
    reverse(all(dig));
    int sz = dig.size();

    adj[u].emplace_back(dig[0], cnt + 1);
    adj[v].emplace_back(dig[0], cnt + 1);
    for (int i = 1; i < sz - 1; i++)
        adj[cnt + i].emplace_back(dig[i], cnt + i + 1);
    adj[cnt + sz - 1].emplace_back(dig.back(), u);
    adj[cnt + sz - 1].emplace_back(dig.back(), v);
    cnt += sz - 1;
}

int d[MAXN], res[MAXN], vis[MAXN];

void bfs() {
    queue<int> q;
    q.push(1);
    vis[1] = 1;

    while (!q.empty()){
        int u = q.front(); q.pop();
        // cerr << u << ' ' << d[u] << endl;
        for (auto v : adj[u]) 
            if (!vis[v.S]) {
                d[v.S] = d[u] + 1;
                q.push(v.S);
                vis[v.S] = 1;
            }
    }
    for (int i = 1; i <= cnt; i++) vis[i] = 0;
}

vector<int> dig[MAXN];

void dfs(int dd) {
    for (int dg = 0; dg < 10; dg++){
        for (auto u : dig[dd]){
            for (auto wv : adj[u]) {
                int w = wv.F, v = wv.S;
                if (d[v] == d[u] + 1 && !vis[v] && w == dg){
                    vis[v] = 1; dig[dd + 1].push_back(v);
                    res[v] = (res[u] * 10 + w) % mod;
                }
            }
        }
        if (!dig[dd + 1].empty()) dfs(dd + 1);
    }
    dig[dd].clear();
}

void Hollwo_Pelw() {
    cin >> n >> m; cnt = n;
    for (int i = 1, u, v; i <= m; i++){
        cin >> u >> v;
        add_edge(u, v, i);
    }
    // for (int i = 1; i <= cnt; i++)
    //     cout << adj[i] << endl;
    vis[1] = 1;
    dig[0].push_back(1);
    bfs(), dfs(0);
    for (int i = 2; i <= n; i++)
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