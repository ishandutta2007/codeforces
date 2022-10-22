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
// #define int long long

int timer, ord[MAXN << 1];
int S[MAXN], E[MAXN], dep[MAXN];
vector<int> adj[MAXN];

void dfs(int u){
    ord[++timer] = u;
    S[u] = timer;
    for (auto v : adj[u]){
        dep[v] = dep[u] + 1;
        dfs(v);
        ord[++timer] = u;
    }
    E[u] = timer;
}

int n, q;

int lg[MAXN << 1], st[MAXN << 1][22];
pii stmin[MAXN << 1][22], stmax[MAXN << 1][22];

void build(){
    for (int i = 2; i <= timer; i++)
        lg[i] = lg[i / 2] + 1;
    for (int i = 1; i <= timer; i++)
        st[i][0] = dep[ord[i]];
    
    for (int i = 1; i <= n; i++){
        stmin[i][0] = {S[i], i};
        stmax[i][0] = {E[i], i};
    }
    
    for (int j = 1; j < 22; j++){
        for (int i = 1; i + (1 << j) <= timer + 1; i++){
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int j = 1; j < 22; j++){
        for (int i = 1; i + (1 << j) <= n + 1; i++){
            stmin[i][j] = min(stmin[i][j - 1], stmin[i + (1 << (j - 1))][j - 1]);
            stmax[i][j] = max(stmax[i][j - 1], stmax[i + (1 << (j - 1))][j - 1]);
        }
    }
}

pii querymin(int l, int r){
    if (l > r) return {inf, -1};
    int j = lg[r - l + 1];
    return min(stmin[l][j], stmin[r - (1 << j) + 1][j]);
}

pii querymax(int l, int r){
    if (l > r) return {-inf, -1};
    int j = lg[r - l + 1];
    return max(stmax[l][j], stmax[r - (1 << j) + 1][j]);
}

int query(int l, int r){
    int j = lg[r - l + 1];
    return min(st[l][j], st[r - (1 << j) + 1][j]);
}

int get(int l, int r, int m){
    int ss = min(querymin(l, m - 1), querymin(m + 1, r)).F;
    int ee = max(querymax(l, m - 1), querymax(m + 1, r)).F;
    return query(ss, ee);
}

void Solve() {
    cin >> n >> q;
    for (int i = 2, p; i <= n; i++)
        cin >> p, adj[p].pb(i);
    dfs(1);
    build();
    // for (int i = 1; i <= timer; i++)
    //     cout << ord[i] << ' ';
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    //     cout << S[i] << ' ' << E[i] << endl;
    // assert(timer == n * 2 - 1);
    while(q--){
        int l, r;
        cin >> l >> r;
        // cout << "Fuck " << l << ' ' << r << endl;
        // cout << "log = " << lg[r - l + 1] << endl;
        // cout << "two range: " << endl;
        // cout << l << ' ' << l + (1 << lg[r - l + 1]) - 1 << endl;
        // cout << r - (1 << lg[r - l + 1]) + 1 << ' ' << r << endl;
        int mn = querymin(l, r).S;
        int mx = querymax(l, r).S;
        int resmn = get(l, r, mn);
        int resmx = get(l, r, mx);
        if (resmn > resmx)
            cout << mn << ' ' << resmn << endl;
        else
            cout << mx << ' ' << resmx << endl;
    }
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
    // cin >> TC;
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