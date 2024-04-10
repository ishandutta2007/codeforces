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
//
int n;
int c[MAX_N], w[MAX_N], vis[MAX_N], mx[MAX_N];
ll cnt[MAX_N], ans[MAX_N];
map<int, int> sub[MAX_N];
vector<int> grp[MAX_N];

void merge(int a, int b){
    if (sub[w[a]].size() < sub[w[b]].size()){
		swap(w[a],w[b]);
	}
	int id = w[a];
	for (auto it = sub[w[b]].begin(); it != sub[w[b]].end(); it++){
		int val = (*it).first;
		int at = (*it).second;
		sub[id][val] += at;
		if (sub[id][val] > mx[id]){
			mx[id] = sub[id][val];
			cnt[id] = 0;
		}
		if (sub[id][val]==mx[id])
			cnt[id] += val;
	}
}

void dfs(int v){
    vis[v] = 1;
    for (auto to:grp[v]){
        if (vis[to])
            continue;
        dfs(to);
        merge(v, to);
    }
    ans[v] = cnt[w[v]];
}

void Solve() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> c[i];
        sub[i][c[i]] = 1;
        w[i] = i;
        mx[i] = 1;
        cnt[i] = c[i];
    }
	for (int i = 1, u, v; i < n; i++){
	    cin >> u >> v;
	    grp[u].pb(v);
	    grp[v].pb(u);
	}
	dfs(1);
	for (int i = 1; i <= n; i++){
	    cout << ans[i] << ' ';
	}
}

signed main(){
    FAST_IO;
    int TC = 1; 
	//cin >> TC;
    while(TC--) Solve();
    return 0;
}