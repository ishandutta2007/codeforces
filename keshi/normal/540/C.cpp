//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 510;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, c;

bool f, vis[maxn][maxn];

string s[maxn];

bool cor(ll x, ll y){
	if(x < 0 || x >= n || y < 0 || y >= m) return 0;
	return (s[x][y] == '.');
}

bool val(ll x, ll y){
	if(!cor(x, y)) return 0;
	return !vis[x][y];
}

void dfs(ll x, ll y){
	vis[x][y] = 1;
	if(val(x + 1, y)) dfs(x + 1, y);
	if(val(x - 1, y)) dfs(x - 1, y);
	if(val(x, y + 1)) dfs(x, y + 1);
	if(val(x, y - 1)) dfs(x, y - 1);
	return;
}

int main(){
	ll x, y, a, b;
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < n; i++){
		cin >> s[i];
	}
	
	cin >> x >> y >> a >> b;
	x--;
	y--;
	a--;
	b--;
	if(s[a][b] == 'X'){
		s[a][b] = '.';
		f = 1;
	}
	
	dfs(x, y);
	
	s[x][y] = '.';
	
	if(f){
		if(a == x && b == y){
			vis[a][b] = cor(a + 1, b) || cor(a - 1, b) || cor(a, b + 1) || cor(a, b - 1);
		}
		cout << (vis[a][b] ? "YES" : "NO");
	}
	else{
		if(!vis[a][b]){
			cout << "NO";
			return 0;
		}
		if(cor(a + 1, b)) c++;
		if(cor(a - 1, b)) c++;
		if(cor(a, b + 1)) c++;
		if(cor(a, b - 1)) c++;
		cout << ((c > 1) ? "YES" : "NO");
	}
	
	return 0;
}