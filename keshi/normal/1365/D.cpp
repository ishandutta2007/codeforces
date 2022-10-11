//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, m, c;
bool vis[maxn][maxn];

string s[maxn];

void solve(ll x, ll y){
	if(vis[x][y] || s[x][y] == '#') return;
	vis[x][y] = 1;
	if(x == 0 || x == n + 1 || y == 0 || y == m + 1) return;
	if(s[x][y] == 'B' || s[x + 1][y] == 'B' || s[x - 1][y] == 'B' || s[x][y + 1] == 'B' || s[x][y - 1] == 'B') return;
	if(s[x][y] == 'G') c--;
	solve(x, y + 1);
	solve(x, y - 1);
	solve(x + 1, y);
	solve(x - 1, y);
	return;
}

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		s[0] = "";
		s[n + 1] = "";
		for(ll j = 0; j < m + 2; j++){
			s[0] += ' ';
			s[n + 1] += ' ';
		}
		c = 0;
		for(ll i = 1; i <= n; i++){
			cin >> s[i];
			s[i] = ' ' + s[i] + ' ';
			for(ll j = 1; j <= m; j++){
				vis[i][j] = 0;
				if(s[i][j] == 'G') c++;
			}
		}
		solve(n, m);
		cout << (c ? "No\n" : "Yes\n");
	}
	
	return 0;
}