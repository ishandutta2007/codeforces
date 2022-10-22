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
const int MAXN = 1e5 + 6 , MAXM = 5e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define int long long

int sz[MAXN], w[MAXN], c[MAXN]; 
vector<pii> adj[MAXN];

void dfs(int u, int p, int& val1, int& val2, priority_queue<pair<int, pii>>& pq1, 
                        priority_queue<pair<int, pii>>& pq2){
    sz[u] = 0;
    for (auto v : adj[u]){
        if (v.F != p){
            dfs(v.F, u, val1, val2, pq1, pq2);
            sz[u] += sz[v.F];
            if (c[v.S] == 1){
                pq1.push({sz[v.F]*((w[v.S]+1)/2),{sz[v.F], w[v.S]}});
                val1 += sz[v.F]*w[v.S];
            }else{
                pq2.push({sz[v.F]*((w[v.S]+1)/2),{sz[v.F], w[v.S]}});
                val2 += sz[v.F]*w[v.S];
            }
        }
    }
    if (!sz[u]) sz[u] = 1;
}

void Solve () {
    priority_queue<pair<int, pii>> pq1, pq2;
    int n, S; cin >> n >> S;
    for (int i = 1; i <= n; i++)
        adj[i].clear();

    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v >> w[i] >> c[i];
        adj[u].eb(v, i); adj[v].eb(u, i);
    }
    int ans = inf, val1 = 0, val2 = 0; 
    dfs(1, 1, val1, val2, pq1, pq2);
    vector<int> v1, v2;
    v1.pb(val1); v2.pb(val2);
    while(val1 > 0){
        auto x = pq1.top(); pq1.pop();
        val1 -= x.F; x.S.S /= 2; v1.pb(val1);
        pq1.push({(x.S.S+1)/2*x.S.F, {x.S}});
    }
    while(val2 > 0){
        auto x = pq2.top(); pq2.pop();
        val2 -= x.F; x.S.S /= 2; v2.pb(val2);
        pq2.push({(x.S.S+1)/2*x.S.F, {x.S}});
    }
    int pos = v2.size() - 1;
    for (int i = 0; i < v1.size(); ++i) {
        while (pos > 0 && v1[i] + v2[pos - 1] <= S) --pos;
        if (v1[i] + v2[pos] <= S) {
            ans = min(ans, i + pos * 2);
        }
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