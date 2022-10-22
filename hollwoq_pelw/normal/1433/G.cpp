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
const int MAXN = 3e5 + 6 , MAXM = 5e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define int long long

int d[1010][1010], n, m, k;
vector<pii> q, edge, adj[1010];

void calc(int s){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({d[s][s] = 0, s});
    while(pq.size()){
        auto [dd, u] = pq.top(); pq.pop();
        if (dd != d[s][u]) continue;
        for (auto [v, w] : adj[u]){
            if (d[s][v] > d[s][u] + w){
                pq.push({d[s][v] = d[s][u] + w, v});
            }
        }
    }
}

void Solve () {
    cin >> n >> m >> k;
    for (int i = 0, x, y, w; i < m; i++){
        cin >> x >> y >> w;
        edge.eb(x, y);
        adj[x].eb(y, w);
        adj[y].eb(x, w);
    }
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            d[i][j] = linf;
        calc(i);
//        for (int j = 1; j <= n; j++)
//            cout << d[i][j] << ' ';
//        cout << endl;
    }
    
    q.resize(k); cin >> q;
    
    int ans = linf;
    for (auto [x, y] : edge){
        int cur = 0;
        for (auto [a, b] : q){
            cur += min({d[a][x] + d[y][b], d[a][y] + d[x][b], d[a][b]});
        }
        ans = min(ans, cur);
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

./-=====>>><<<-------- DEBUG -------->>><<<=====-\.
/.................................................\
+====================== INP ======================+

5 5 4

1 2 4 2 1
4 2 2 1 1 -> 4 2

3 5 1 2 4
5 4 3 2 1 -> 5 4

1 5 7 1 2
7 5 2 1 1 -> 7 5

3 8 7 1 2
8 7 3 2 1 -> 8 7

8 4 7 1 6
8 7 6 4 1 -> 8 7

++++ FAKE_ANS = 57 = 1 (mod 4)

+====================== OUT ======================+




+======================*****======================+
\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.

*/