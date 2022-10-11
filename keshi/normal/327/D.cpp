//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 500 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m;

bool vis[maxn][maxn];

pll p;

string s[maxn];

vector< pair<char, pll> > ans;

bool val(ll x, ll y){
	if(x < 0 || x >= n || y < 0 || y >= m) return 0;
	return !vis[x][y];
}

void dfs(ll x, ll y){
	vis[x][y] = 1;
	
	ans.pb({'B', {x, y}});
	
	if(val(x + 1, y)){
		dfs(x + 1, y);
	}
	if(val(x - 1, y)){
		dfs(x - 1, y);
	}
	if(val(x, y + 1)){
		dfs(x, y + 1);
	}
	if(val(x, y - 1)){
		dfs(x, y - 1);
	}
	
	if(x != p.F || y != p.S){
		ans.pb({'D', {x, y}});
		ans.pb({'R', {x, y}});
	}
}

int main(){
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < n; i++){
		cin >> s[i];
		for(ll j = 0; j < m; j++){
			vis[i][j] = (s[i][j] == '#');
		}
	}
	
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < m; j++){
			if(!vis[i][j]){
				p = {i, j};
				dfs(i, j);
			}
		}
	}
	
	cout << ans.size() << endl;
	
	for(ll i = 0; i < ans.size(); i++){
		cout << ans[i].F << ' ' << ans[i].S.F + 1 << ' ' << ans[i].S.S + 1 << '\n';
	}
	
	return 0;
}