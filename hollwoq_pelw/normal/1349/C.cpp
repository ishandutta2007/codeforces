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
const int N = 1010;
char grid[N][N];
int n, m, t;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
ll dist[N][N];
 
bool chk(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y <= m;
}
 
void Solve(){
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++)
		cin >> grid[i];
	
	queue<pii> q;
	for (int x = 0; x < n; x++){
		for (int y = 0; y < m; y++) {
			dist[x][y] = LLONG_MAX;
			for (int i = 0; i < 4; i++) {
				int xx = x + dx[i], yy = y + dy[i];
				if (!chk(xx, yy)) 
				    continue;
				if (grid[xx][yy] == grid[x][y]) 
				    dist[x][y] = 0;
			}
			if (dist[x][y] == 0) 
			    q.push(make_pair(x, y));
		}
	}
	
	while (q.size()) {
		int x = q.front().F, y = q.front().S;
		q.pop();
		for (int j = 0; j < 4; j++) {
			int xx = x + dx[j], yy = y + dy[j];
			if (!chk(xx, yy)) continue;
			if (dist[xx][yy] <= dist[x][y] + 1) 
			    continue;
			dist[xx][yy] = dist[x][y] + 1;
			q.push(make_pair(xx, yy));
		}
	}
	
	while(t--) {
		int x, y; ll p;
		cin >> x >> y >> p;
		x--; y--;
		char ans = grid[x][y];
		if (p >= dist[x][y] && (p - dist[x][y]) % 2 == 1) ans ^= 1;
		cout << ans << endl;
	}
}

signed main(){
    FAST_IO;
    int TC = 1;
	//cin >> TC;
    while(TC--) Solve();
    cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
    return 0;
}
/*
 
*/