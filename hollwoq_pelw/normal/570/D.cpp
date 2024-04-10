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
const int MAXN = 5e5 + 5;
const int inf = 2e9;
const ll linf = 1e18;
// #define int long long

string s;
int n, m, dep[MAXN], w[MAXN];
bool ans[MAXN];
vector<int> adj[MAXN], cnt[MAXN];
vector<pii> q[MAXN]; 
// cnt contains all character in a depth using xor operator.
// it contain all dep in subtree in this order dep[v] + sz - 1, dep + sz - 2, ..., dep[v] + 1, dep[v]

void merge(int u, int v){
    if (cnt[w[u]].size() < cnt[w[v]].size())
        swap(w[u], w[v]);
    for (int k = 0; k < cnt[w[v]].size(); k++){
        int i = cnt[w[v]].size() - 1 - k;
        int j = cnt[w[u]].size() - 1 - k;
        cnt[w[u]][j] ^= cnt[w[v]][i];
    }
}

void dfs(int u, int h){
    dep[u] = h, w[u] = u;
    cnt[w[u]].pb(1 << (s[u - 1] - 'a'));
    for (auto v : adj[u]){
        dfs(v, h + 1);
        cnt[w[v]].pb(0);
        merge(u, v);
    }
    for (auto [h, id] : q[u]){
        if (h < dep[u]){
            ans[id] = 1;
        }else {
            h -= dep[u];
            if (h >= cnt[w[u]].size())
                ans[id] = 1;
            else
                ans[id] = __builtin_popcount(cnt[w[u]][cnt[w[u]].size() - h - 1]) <= 1;
        }
    }
}

void Hollwo_Pelw() {
    cin >> n >> m;
    for (int i = 2, p; i <= n; i++)
        cin >> p, adj[p].pb(i);
    cin >> s;
    for (int i = 1, v, h; i <= m; i++)
        cin >> v >> h, q[v].eb(h, i);
    dfs(1, 1);
    for (int i = 1; i <= m; i++){
        cout << (ans[i] ? "Yes" : "No") << "\n";
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