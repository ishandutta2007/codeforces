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
// loop
//#define For(i, l, r)        for (int i = l; i < r; i++)
//#define ForE(i, l, r)       for (int i = l; i <= r; i++)
//#define Ford(i, r, l)       for (int i = r; i > l; i--)
//#define FordE(i, r, l)      for (int i = r; i >= l; i--)
//#define Fora(i, a)          for (auto i : a)
// I/O
#define open(file, in, out) if (fopen(file in, "r")) {        \
                                freopen(file in, "r", stdin);  \
                                freopen(file out, "w", stdout); \
                            }
#define FAST_IO             std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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
const int mod1 = 998244353, mod = 1e9+7;
const int MAXN = 1e5 + 5, MAXM = 2e5 + 5, MX = 1e6 + 5;
// code
#define int long long

int n, m;
int s[100005], col[100005];
vector <int> swt[100005];
vector <pii> adj[100005];
 
void Solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> s[i];
	
	for(int i = 1, k, x; i <= m; i++){
		col[i] = -1;
		cin >> k; while(k--){
			cin >> x;
			swt[x].pb(i);
		}
	}
	for(int i = 1; i <= n; i++){
		adj[swt[i][0]].eb(swt[i][1], 1 ^ s[i]);
		adj[swt[i][1]].eb(swt[i][0], 1 ^ s[i]);
	}
	for(int i = 1; i <= m; i++){
		if(col[i] == -1){
			queue <int> bfs;
			bfs.push(i);
			col[i] = 0;
			while(bfs.size()){
				int u = bfs.front(); bfs.pop();
				for(auto x : adj[u]){
					int tmp = col[u] ^ x.S;
					if(col[x.F] == -1){
						col[x.F] = tmp;
						bfs.push(x.F);
					}
					else if(tmp != col[x.F]){
						cout << "NO";
						return ;
					}
				}
			}
		}
	}
	cout << "YES";
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO;
    int TC = 1;
    //cin >> TC;
    while(TC--) Solve();
    return 0;
}
/*

./-=====>>><<<-------- DEBUG -------->>><<<=====-\.
/.................................................\

+====================== INP ======================+


+====================== OUT ======================+


\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.

*/