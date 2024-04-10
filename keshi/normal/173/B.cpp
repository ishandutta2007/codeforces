//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, dis[2][maxn], d, r;

bool vis[2][maxn];

string s[maxn];

queue<pll> q;

int main(){
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < n; i++){
		cin >> s[i];
	}
	
	q.push({0, 0});
	
	while(!q.empty()){
		d = q.front().F;
		r = q.front().S;
		q.pop();
		if(d == 0){
			for(ll j = 0; j < m; j++){
				if(s[r][j] == '#'){
					if(!vis[1][j]){
						vis[1][j] = 1;
						dis[1][j] = dis[0][r] + 1;
						q.push({1, j});
					}
				}
			}
		}
		else{
			for(ll i = 0; i < n; i++){
				if(s[i][r] == '#'){
					if(!vis[0][i]){
						vis[0][i] = 1;
						dis[0][i] = dis[1][r] + 1;
						q.push({0, i});
					}
				}
			}
		}
	}
	
	if(!vis[0][n - 1]){
		dis[0][n - 1] = -1;
	}
	
	cout << dis[0][n - 1];
	
	return 0;
}