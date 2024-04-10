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
#define int long long

struct dst {
    int u, lw, d;
    dst () {}
    dst (int _u, int _lw, int _d)
        : u(_u), lw(_lw), d(_d) {
            
        }
    bool operator < (const dst & oth) const {
        return d > oth.d;
    }
};

int n, m;
vector<pii> adj[MAXN];
int dist[MAXN][55];

void Solve() {
    cin >> n >> m;
    for (int i = 1, u, v, w; i <= m; i++){
        cin >> u >> v >> w;
        adj[v].pb({u, w});
        adj[u].pb({v, w});
    }
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= 50; j++){
            dist[i][j] = linf;
        }
    }
    priority_queue<dst> pq;
    pq.push({1, 0, dist[1][0] = 0});
    while(!pq.empty()){
        auto [u, lw, d] = pq.top(); pq.pop();
        if (d != dist[u][lw]) continue;
        if (lw == 0){
            for (auto [v, w] : adj[u]){
                if (dist[v][w] > d + w*w){
                    pq.push({v, w, dist[v][w] = d + w*w});
                }
            }
        }else{
            for (auto [v, w] : adj[u]){
                if (dist[v][0] > d + w*w + 2 * lw * w){
                    pq.push({v, 0, dist[v][0] = d + w*w + 2 * lw * w});
                }
            }
        }
    }
    for (int i = 1; i <= n; i++){
        if (dist[i][0] == linf)
            dist[i][0] = -1;
        cout << dist[i][0] << ' ';
    }
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