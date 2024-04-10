//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 3e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, a[maxn], dis[maxn][maxn], x, y, cnt;

bool s[maxn], d[maxn], vis[maxn][maxn];

queue<pll> q;

int main(){
	fast_io;
	
	cin >> n >> k;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	
	d[n] = 1;
	
	for(ll i = n - 1; i > -1; i--){
		s[i] = s[i + 1] || (a[i] > 0);
		d[i] = d[i + 1] && (a[i] < 100);
	}
	
	q.push({0, 1});
	vis[0][1] = 1;
	
	while(!q.empty()){
		x = q.front().F;
		y = q.front().S;
		cnt++;
		q.pop();
		if(y >= n || dis[x][y] == k) continue;
		if(!vis[x][y + 1] && a[x] > 0 && d[y]){
			q.push({x, y + 1});
			vis[x][y + 1] = 1;
			dis[x][y + 1] = dis[x][y] + 1;
		}
		if(!vis[y][y + 1] && a[x] < 100 && s[y]){
			q.push({y, y + 1});
			vis[y][y + 1] = 1;
			dis[y][y + 1] = dis[x][y] + 1;
		}
		if(!vis[y + 1][y + 2] && a[x] > 0 && s[y]){
			q.push({y + 1, y + 2});
			vis[y + 1][y + 2] = 1;
			dis[y + 1][y + 2] = dis[x][y] + 1;
		}
	}
	
	cout << cnt;
	
	return 0;
}