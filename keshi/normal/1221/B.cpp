#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

const ll maxn = 200;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n;

bool vis[maxn][maxn];
char s[maxn][maxn];

bool val(ll x, ll y){
	if(x < 0 || x >= n || y < 0 || y >= n){
		return 0;
	}
	return !vis[x][y];
}

void dfs(ll x, ll y, bool c){
	ll dx, dy;
	vis[x][y] = 1;
	if(c){
		s[x][y] = 'B';
	}
	else{
		s[x][y] = 'W';
	}
	for(ll i = 1; i < 3; i++){
		for(ll j = -1; j < 2; j += 2){
			for(ll k = -1; k < 2; k += 2){
				dx = i * j;
				dy = (3 - i) * k;
				if(val(x + dx, y + dy)){
					dfs(x + dx, y + dy, !c);
				}
			}
		}
	}
	return;
}

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			if(!vis[i][j]){
				dfs(i, j, 0);
			}
			cout << s[i][j];
		}
		cout << endl;
	}
	
	return 0;
}