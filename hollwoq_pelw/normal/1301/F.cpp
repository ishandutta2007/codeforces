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
const int MAXN = 1e6 + 99;
const int inf = 2e9;
const ll linf = 1e18;
const ld eps = 1e-9;
// #define int long long

int c[MAXN], dist[44][MAXN], d[44];
vector<int> adj[MAXN], cell[44];
int n, m, k;

void bfs(int col){
    queue<int> q;
    for (auto x : cell[col]){
        dist[col][x] = 0;
        q.push(x);
    }
    for (int i = 1; i <= k; i++)
        d[i] = 0;
    while (!q.empty()){
        int x = q.front(); q.pop();
        if (!d[c[x]]) {
            d[c[x]] = 1;
            for (auto v : cell[c[x]]){
                if (dist[col][v] == -1){
                    dist[col][v] = dist[col][x] + 1;
                    q.push(v);
                }
            }
        }
        for (auto v : adj[x]) {
            if (dist[col][v] == -1){
                dist[col][v] = dist[col][x] + 1;
                q.push(v);
            }
        }
    }
    // for (int i = 0; i < n * m; i++)
    //     cout << dist[col][i] << " \n"[(i + 1) % m == 0];
    // cout << "\n";
}

void Hollwo_Pelw() {
    cin >> n >> m >> k;
    for (int i = 0; i < n * m; i++){
        for (int j = 1; j <= k; j++)
            dist[j][i] = -1;
        cin >> c[i];
        if (i % m != 0)
            adj[i].pb(i - 1);
        if ((i + 1) % m != 0)
            adj[i].pb(i + 1);
        if (i >= m)
            adj[i].pb(i - m);
        if (i + m < m * n)
            adj[i].pb(i + m);
        cell[c[i]].pb(i);
        // cout << adj[i] << "\n";
    }
    for (int i = 1; i <= k; i++){
        bfs(i);
    }
    int q; cin >> q;
    while (q--){
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        int ans = abs(r1 - r2) + abs(c1 - c2);
        int u = (r1 - 1) * m + c1 - 1;
        int v = (r2 - 1) * m + c2 - 1;
        for (int i = 1; i <= k; i++){
            // cout << 1 + dist[i][u] + dist[i][v] << endl;
            ans = min(ans, 1 + dist[i][u] + dist[i][v]);
        }
        // cout << "ans = ";
        cout << ans << "\n";
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