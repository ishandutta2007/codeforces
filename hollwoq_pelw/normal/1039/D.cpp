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
//#define PrintV(a)           Fora(ii, a) cout << ii << ' '; cout << endl;
//#define PrintVl(a)          Fora(ii, a) cout << ii << endl;
//#define PrintA(a, l, r)     for (int ii = l; ii <= r; ii++) cout << a[ii] << ' '; cout << endl;
//#define PrintAl(a, l, r)    for (int ii = l; ii <= r; ii++) cout << a[ii] << endl;
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
const int mod1 = 998244353, mod2 = 1e9+7;
const int MAX_N = 100005, MAX_M = 200010;
//
vector<int> grp[MAX_N];
pii dp[MAX_N];
int par[MAX_N], dp_ord[MAX_N], ans[MAX_N], max1[MAX_N], max2[MAX_N], n, c;

void dfs(int v, int p){
	par[v] = p;
	for (auto u: grp[v]){
		if (u != p){ // if not parent node
			dfs(u, v);
		}
	}
	// dp order of tree 
	dp_ord[c++] = v;
}
// dp[i] = (max len of unfinished path, total finished path) of subtree rooted at (ith) node;

int calc(int k){
    for (int i = 0; i < n; i++) 
		dp[i].F = dp[i].S = max1[i] = max2[i] = 0;
    for (int i = 0; i < n; i++){
        int t = dp_ord[i];
        if (max1[t] + max2[t] + 1 >= k){
            dp[t].F = max1[t] + max2[t] + 1;
        }
        else{
            dp[t].F = max1[t] + 1;
        }
        if (dp[t].F >= k){
            dp[t].F = 0;
            dp[t].S++;
        }
        if (par[t] != -1){
            dp[par[t]].S += dp[t].S;
            int len = dp[t].F;
            if (len > max1[par[t]]) swap(len, max1[par[t]]);
            if (len > max2[par[t]]) swap(len, max2[par[t]]);
        }
    }
    return dp[0].S;
}

void bin_solv(int l, int r, int l_val, int r_val){
	if (l > r){
		return;
	}
	if (l_val == r_val){
		for (int i = l; i <= r; i++){
			ans[i] = l_val;
		}
		return;
	}
	int m = (l+r)/2;
	int m_val = calc(m);
	ans[m] = m_val;
	bin_solv(l, m-1, m_val, r_val);
	bin_solv(m+1, r, l_val, m_val);
}

void Solve(){
	cin >> n;
	for (int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		grp[u-1].push_back(v-1);
		grp[v-1].push_back(u-1);
	}
	dfs(0, -1);
	bin_solv(1, n, 0, n);
	for (int i = 1; i <= n; i++){
		cout << ans[i] << endl;
	}
}

signed main(){
    FAST_IO;
    int TC = 1; 
	// cin >> TC;
    while(TC--) Solve();
    return 0;
}