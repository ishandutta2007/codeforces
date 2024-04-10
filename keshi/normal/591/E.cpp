//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e3 + 100;
const ll maxm = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, a[maxn][maxn], t, dis[3][maxm], ans;

string s[maxn];

vector<ll> g[maxm];

bool cor(ll x, ll y){
	if(x < 0 || x >= n || y < 0 || y >= m) return 0;
	return (s[x][y] != '#');
}

void bfs(ll x){
	ll v, u;
	for(ll i = 0; i < t; i++){
		dis[x][i] = inf;
	}
	queue<ll> q;
	dis[x][x] = 0;
	q.push(x);
	while(!q.empty()){
		v = q.front();
		q.pop();
		for(ll i = 0; i < g[v].size(); i++){
			u = g[v][i];
			if(dis[x][u] > dis[x][v] + 1){
				dis[x][u] = dis[x][v] + 1;
				q.push(u);
			}
		}
	}
	return;
}

int main(){
	fast_io;
	
	cin >> n >> m;
	
	t = 3;
	
	for(ll i = 0; i < n; i++){
		cin >> s[i];
		for(ll j = 0; j < m; j++){
			if(s[i][j] == '.'){
				a[i][j] = t++;
			}
			else if(s[i][j] != '#'){
				a[i][j] = s[i][j] - '1';
			}
		}
	}
	
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < m; j++){
			if(s[i][j] == '#') continue;
			if(cor(i + 1, j)){
				g[a[i][j]].pb(a[i + 1][j]);
			}
			if(cor(i - 1, j)){
				g[a[i][j]].pb(a[i - 1][j]);
			}
			if(cor(i, j + 1)){
				g[a[i][j]].pb(a[i][j + 1]);
			}
			if(cor(i, j - 1)){
				g[a[i][j]].pb(a[i][j - 1]);
			}
		}
	}
	
	bfs(0);
	bfs(1);
	bfs(2);
	
	ans = min(dis[0][1] + dis[0][2] - 2, min(dis[1][0] + dis[1][2] - 2, dis[2][0] + dis[2][1] - 2));
	
	for(ll i = 3; i < t; i++){
		ans = min(ans, dis[0][i] + dis[1][i] + dis[2][i] - 2);
	}
	
	if(ans + 10 >= inf){
		ans = -1;
	}
	
	cout << ans;
	
	return 0;
}