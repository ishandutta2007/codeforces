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
const int MAXN = 5e3 + 5;
const int inf = 2e9;
const ll linf = 1e18;
#define int long long

int n, n1, n2, n3, m, comp, col[MAXN];
vector<int> adj[MAXN];
vector<int> in[MAXN][2];

void kill(){
    cout << "NO";
    exit(0);
}

void dfs(int u, int c){
    col[u] = c;
    in[comp][c].pb(u);
    for (auto v : adj[u]){
        if (col[v] == -1)
            dfs(v, c ^ 1);
        else if (col[v] == col[u])
            kill();    
        
    }
}

int dp[MAXN][MAXN];

void Hollwo_Pelw(){
    cin >> n >> m >> n1 >> n2 >> n3;
    for (int i = 1, u, v; i <= m; i++)
        cin >> u >> v, adj[u].pb(v), adj[v].pb(u);
    for (int i = 1; i <= n; i++) col[i] = -1;
    for (int i = 1; i <= n; i++) 
        if (col[i] == -1) ++comp, dfs(i, 0);
    // for (int i = 1; i <= comp; i++)
    //     cout << in[i][0] << " : " << in[i][1] << endl;
    dp[0][0] = 1;
    for (int i = 1; i <= comp; i++){
        for (int j = 0; j <= n2; j++){
            int j1 = j - in[i][0].size();
            int j2 = j - in[i][1].size();
            dp[i][j] = (j1 >= 0 && dp[i - 1][j1]) || (j2 >= 0 && dp[i - 1][j2]);
        }
    }
    if (!dp[comp][n2]) kill();
    int cur = n2;
    for (int i = n; i >= 1; i--){
        int nxt1 = cur - in[i][0].size();
        int nxt2 = cur - in[i][1].size();
        if (dp[i - 1][nxt1]) {
            for (auto v : in[i][0])
                col[v] = 2;
            for (auto v : in[i][1])
                col[v] = 3;
            cur = nxt1;
        }else{
            for (auto v : in[i][0])
                col[v] = 3;
            for (auto v : in[i][1])
                col[v] = 2;
            cur = nxt2;
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++){
        if (n1 && col[i] == 3) col[i] = 1, n1 --;
        cout << col[i];
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