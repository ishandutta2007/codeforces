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

void FAST_IO(string filein = "", string fileout = ""){
    if (fopen(filein.c_str(), "r")){
        freopen(filein.c_str(), "r", stdin);
        freopen(fileout.c_str(), "w", stdout);
    }
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

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

// constant
const int allmod[3] = {(int) 1e9 + 7, 998244353, (int) 1e9 + 9};
const int mod = allmod[1];
const int MAXN = 1e5 + 1;
const int inf = 2e9;
const ll linf = 1e18;
#define int long long

int n, m, in[MAXN], vis[MAXN], dp[MAXN];
vector<int> adj[MAXN];
vector<pii> ed;

bool chk(int e){
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        in[i] = vis[i] = 0;
        dp[i] = 1;
    }
    for (int i = 0; i < e; i++){
        adj[ed[i].F].pb(ed[i].S);
        in[ed[i].S] ++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++){
        if (!in[i]) q.push(i);
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        for (auto v : adj[u]) {
            dp[v] = max(dp[u] + 1, dp[v]);
            in[v] --;
            if (!in[v]) q.push(v);
        }
    }
    return *max_element(dp + 1, dp + n + 1) == n;
}

void Hollwo_Pelw(){
    cin >> n >> m;
    for (int i = 0, u, v; i < m; i++){
        cin >> u >> v;
        ed.eb(u, v);
    }
    int l = 1, r = m, ans = -1;
    while (l <= r) {
        int md = l + r >> 1;
        if (chk(md)) {
            ans = md;
            r = md - 1;
        }else{
            l = md + 1;
        }
    }
    cout << ans;
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