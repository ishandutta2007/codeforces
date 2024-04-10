#include <bits/stdc++.h>
using namespace std;
// type
typedef long long ll;
typedef long double ld;
// loop
//#define For(i, l, r, x)     for (int i = l; i < r; i+=x)
//#define ForE(i, l, r, x)    for (int i = l; i <= r; i+=x)
//#define Ford(i, r, l)       for (int i = r; i > l; i--)
//#define FordE(i, r, l)      for (int i = r; i >= l; i--)
//#define Fora(i, a)          for (auto i : a)
// I/O 
#define FAST_IO             std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//#define PrintV(a)           Fora(ii, a) cout << ii << ' '; cout << rl;
//#define PrintVl(a)          Fora(ii, a) cout << ii << rl;
//#define PrintA(a, l, r)     for (int ii = l; ii <= r; ii++) cout << a[ii] << ' '; cout << rl;
//#define PrintAl(a, l, r)    for (int ii = l; ii <= r; ii++) cout << a[ii] << rl;
//#define Ptest(x)            return cout << x, 0;
#define setpre(n)           fixed << setprecision(n)
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
// geometry calc    
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
const int mod1 = 998244353, mod = 1e9+7;
const int MAX_N = 100005, MAX_M = 200010;
// code
//#define int long long

int n;
vector<int> g[1001];
int dep[1001];
 
pii query(bool all, vector<int> ask){
    if (all){
        for(int i = 1; i <= n; i++){
            ask.pb(i);
        }
    }
    cout << "? " << ask.size() << ' ';
    for(auto v:ask) cout << v << ' ';
    cout << endl; 
    pii ans; cin >> ans.F >> ans.S;
    return ans;
}

void dfs(int u, int p){
    if (u == p) dep[u] = -1;
    dep[u] = dep[p] + 1;
    for(auto v: g[u]){
        if (v == p) continue;
        dfs(v, u);
    }
}
 
void Solve(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        g[i].clear();
        
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
    }
    pii query_ans;
    query_ans = query(true, {});
    int d = query_ans.S;
    dfs(query_ans.F, query_ans.F);

    int l = (d + 1) / 2 - 1, r = d;
    map <int, int> mpp;
    while (l < r){
        int x = (l + r + 1) >> 1;
        if (x == d + 1) break;
        vector<int> ask;
        for(int i = 1; i <= n; i++){
            if (dep[i] == x){
                ask.pb(i);
            }
        }
        
        if (ask.size() == 0){
            r = x - 1;
            continue;
        }
        
        query_ans = query(false, ask);
        mpp[x] = query_ans.F;
        if (query_ans.S == d)
            l = x;
        else
            r = x - 1;
    }
    int vx = mpp[l];
    dfs(vx, vx);
    vector<int> ask;
    for(int i = 1; i <= n; i++)
        if (dep[i] == d)
            ask.pb(i);
    
    query_ans = query(false, ask);
    
    cout << "! " << vx << ' ' << query_ans.F << endl;
    string s; cin >> s;
    if (s != "Correct") exit(0);
}


signed main(){
    FAST_IO;
    int TC = 1;
    cin >> TC;
    while(TC--) Solve();
    return 0;
}