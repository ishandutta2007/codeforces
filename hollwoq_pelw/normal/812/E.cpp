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
int n, t, ans = 0;
vector<int> adj[MAX_N];
int color[MAX_N], cnt[5], a[MAX_N];
ll res = 0;
map<int, ll> C;

void dfs(int u, int c){
    color[u] = c;
    cnt[c] ++;
    for (auto v:adj[u]){
        if (!color[v]){
            dfs(v, 3-c);
        }
    }
}

void Solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 2, x; j <= n; j++){
        cin >> x;
        adj[x].eb(j);
        adj[j].eb(x);
    }
    dfs(1, 1);
    for(int i = 1; i <= n; i++){
		if(adj[i].size() == 1 and i != 1){
			t = color[i];
			break;
		}
	}
	for(int i = 1; i <= n; i++){
		if(color[i] == t){
			ans ^= a[i];
			C[a[i]]++;
		}
	}
	for(int i = 1; i <= n; i++){
		if(color[i] == 3-t){
			res += C[a[i] ^ ans];
		}
	}
	if(ans == 0){
		res += 1ll * cnt[3-t] * (cnt[3-t] - 1) / 2;
		res += 1ll * cnt[t] * (cnt[t] - 1) / 2;
	}
	cout << res;
}

signed main(){
    FAST_IO;
    int TC = 1; 
//	cin >> TC;
    while(TC--) Solve();
    return 0;
}