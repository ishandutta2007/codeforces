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
#define PB push_back  
#define MP make_pair  
#define sz(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORsz(i,a,v) FOR(i,a,sz(v))  
#define REPsz(i,v) REP(i,sz(v))  

const int MAXN=1000000;
struct Set { vector<int> d; int idx; };

int n;
vector<int> adj[MAXN];
int ans[MAXN];

Set res[MAXN];
Set single() { 
    Set ret; 
    ret.d=vector<int>(1,1); 
    ret.idx=0; 
    return ret; 
}
void append(int a) {
	res[a].d.PB(0);
}
int merge(int a,int b) {
	if(sz(res[a].d) < sz(res[b].d)) 
	    swap(a,b);
	for(int i = 0; i < sz(res[b].d); i++) {
		int j=sz(res[a].d) - sz(res[b].d) + i;
		res[a].d[j] += res[b].d[i]; 
		if(res[a].d[j] > res[a].d[res[a].idx] || res[a].d[j] == res[a].d[res[a].idx] && j > res[a].idx) 
		    res[a].idx=j;
	}
	return a;
}

int dfs(int at,int par) {
	int ret = at;
	res[ret] = single();
	for (auto to:adj[at]) {
	    if(to == par) 
	        continue;
		int cur = dfs(to,at);
		append(cur);
		ret = merge(ret,cur);
	}
	ans[at] = sz(res[ret].d) - res[ret].idx - 1;
	return ret;
}

void Solve() {
	cin >> n;
	for(int i = 0; i < n-1; i++) { 
	    int a,b; 
	    cin >> a >> b;
	    --a,--b; 
	    adj[a].pb(b); 
	    adj[b].pb(a); 
	}
	dfs(0,-1);
	for (int i = 0; i < n; i++) 
	    cout << ans[i] << endl;
}

signed main(){
    FAST_IO;
    int TC = 1; 
	//cin >> TC;
    while(TC--) Solve();
    return 0;
}