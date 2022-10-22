#include <bits/stdc++.h>
using namespace std;
// type
//#define int long long
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
const int MAX_N = 1000005, MAX_M = 200010;
// code
int n, m;
int vis[55][55];
char grid[55][55];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


void Solve(){
    cin >> n >> m;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> grid[i][j];
        }
    }
    
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (grid[i][j] == 'B') {
				for (int k = 0; k < 4; k++) {
					int x = i + dx[k], y = j + dy[k];
					if (x <= 0 || y <= 0 || x > n || y > m) continue;
					if (grid[x][y] == 'G') {
						cout << "NO\n";
						return;
					}
					if (grid[x][y] == 'B') continue;
					grid[x][y] = '#';
				}
			}
		}
	}
	
	if (grid[n][m] == '.') {
		vis[n][m] = 1;
		queue<pii> q;
		q.push(make_pair(n, m));
		while (!q.empty()) {
			pii u = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				int x = u.first + dx[i], y = u.second + dy[i];
				if (x <= 0 || y <= 0 || x > n || y > m) continue;
				if (grid[x][y] == '#' || vis[x][y]) continue;
				vis[x][y] = 1; q.push(make_pair(x, y));
			}
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (grid[i][j] == 'G' && !vis[i][j]) {
				cout << "NO\n";
				return;
			}
		}
	}
	cout << "Yes\n";
}

signed main(){
    FAST_IO;
    int TC = 1;
	cin >> TC;
    while(TC--) Solve();
    return 0;
}