//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;


#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, k, dis[maxn][maxn], x, y, ans;

pll p;

queue<pll> q;

int main(){
	file_io;
	fast_io;
	
	cin >> n >> m >> k;
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= m; j++){
			dis[i][j] = inf;
		}
	}
	
	for(ll i = 0; i < k; i++){
		cin >> x >> y;
		dis[x][y] = 0;
		q.push({x, y});
	}
	
	while(!q.empty()){
		x = q.front().F;
		y = q.front().S;
		if(dis[x][y] >= ans){
			ans = dis[x][y];
			p = {x, y};
		}
		q.pop();
		if(dis[x + 1][y] > dis[x][y] + 1){
			dis[x + 1][y] = dis[x][y] + 1;
			q.push({x + 1, y});
		}
		if(dis[x - 1][y] > dis[x][y] + 1){
			dis[x - 1][y] = dis[x][y] + 1;
			q.push({x - 1, y});
		}
		if(dis[x][y + 1] > dis[x][y] + 1){
			dis[x][y + 1] = dis[x][y] + 1;
			q.push({x, y + 1});
		}
		if(dis[x][y - 1] > dis[x][y] + 1){
			dis[x][y - 1] = dis[x][y] + 1;
			q.push({x, y - 1});
		}
	}
	
	cout << p.F << " " << p.S;
	
	return 0;
}