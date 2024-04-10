#include <bits/stdc++.h>
using namespace std;
// type
#define int long long
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
#define all(a)              a.begin(), a.End()
#define rall(a)             a.rbegin(), a.rEnd()
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
const int MAX_N = 1000005, MAX_M = 200010;
// code
int n, cost[MAX_M], cnt[MAX_M][2], dp[MAX_M];
vector<int> adj[MAX_M];

void dfs(int u, int pr){
    cost[u] = min(cost[u], cost[pr]);
    for (auto v:adj[u]){
        if (v == pr)
            continue;
        dfs(v, u);
        dp[u] += dp[v];
        cnt[u][0] += cnt[v][0];
        cnt[u][1] += cnt[v][1];
    }
    int m = min(cnt[u][0], cnt[u][1]);
    dp[u] += 2 * m * cost[u];
    cnt[u][0] -= m;
    cnt[u][1] -= m;
    //cout << u << ' ' << cost[u] << ' ' << dp[u] << ' ' << cnt[u][0] << ' ' << cnt[u][1] << endl;
}

void Solve(){
    cost[0] = INT_MAX;
    cin >> n;
    for (int i = 1, b, c; i <= n; i++){
        cin >> cost[i] >> b >> c;
        cnt[i][b] += (b != c);
    }
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 0);
    if (cnt[1][0] || cnt[1][1])
        cout << -1;
    else
        cout << dp[1];
}

signed main(){
    FAST_IO;
    int TC = 1;
	//cin >> TC;
    while(TC--) Solve();
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}