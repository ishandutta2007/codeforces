/*
 /+===================================================+\
//+---------------------------------------------------+\\
|.|\\...>>>>>>> Hollwo_Pelw's 2nd template<<<<<<<...//|.|
\\+---------------------------------------------------+//
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

void FAST_IO(string filein, string fileout);
void Hollwo_Pelw();

signed main(){
    FAST_IO("input.inp", "output.out");
    int testcases = 1;
    // cin >> testcases;
    for (int test = 1; test <= testcases; test++){
        // cout << "Case #" << test << ": ";
        Hollwo_Pelw();
    }
    return 0;
}

void FAST_IO(string filein = "", string fileout = ""){
    if (fopen(filein.c_str(), "r")){
        freopen(filein.c_str(), "r", stdin);
        freopen(fileout.c_str(), "w", stdout);
    }
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

// constant
const int allmod[3] = {(int) 1e9 + 7, 998244353, (int) 1e9 + 9};
const int mod = allmod[1];
const int MAXN = 2e5 + 6;
const int inf = 2e9;
const ll linf = 1e18;
#define int long long

vector<int> adj[MAXN], h[MAXN];
int dep[MAXN], par[MAXN][18], n, q;
int S[MAXN], E[MAXN], timer;

void dfs(int u){
    for (int i = 1; i < 18; i++){
        par[u][i] = par[par[u][i - 1]][i - 1];
    }
    S[u] = timer ++;
    h[dep[u]].pb(S[u]);
    for (auto v : adj[u]) {
        dep[v] = dep[u] + 1;
        dfs(v);
    }
    E[u] = timer;
}

void Hollwo_Pelw() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> par[i][0], adj[par[i][0]].pb(i);
    for (int i = 1; i <= n; i++)
        if (!par[i][0]) dfs(i);
    cin >> q;
    for (int u, k; q --; ){
        cin >> u >> k;
        for (int i = 0; i < 18; i++)
            if (k >> i & 1) u = par[u][i];
        if (!u) {cout << 0 << " "; continue;}
        int l = S[u], r = E[u];
        cout << upper_bound(all(h[dep[u] + k]), E[u]) - upper_bound(all(h[dep[u] + k]), S[u]) - 1 << " ";
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