//In the name of GOD
//Hello Yellow
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 510;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, c, lx[maxn], rx[maxn], ly[maxn], ry[maxn];

bool g[maxn][maxn], vis[maxn][maxn];

string s;

void dfs(ll x, ll y){
	vis[x][y] = 1;
	if(!g[x][y]) s += '1';
	else c--;
	lx[x] = min(lx[x], y);
	ly[y] = min(ly[y], x);
	rx[x] = max(rx[x], y);
	ry[y] = max(ry[y], x);
	for(ll i = ly[y]; i <= ry[y]; i++){
		if(!vis[i][y]){
			if(i < x){
				for(ll j = 0; j < x - i; j++){
					s += 'U';
				}
			}
			else{
				for(ll j = 0; j < i - x; j++){
					s += 'D';
				}
			}
			dfs(i, y);
			if(i < x){
				for(ll j = 0; j < x - i; j++){
					s += 'D';
				}
			}
			else{
				for(ll j = 0; j < i - x; j++){
					s += 'U';
				}
			}
		}
	}
	for(ll j = lx[x]; j <= rx[x]; j++){
		if(!vis[x][j]){
			if(j < y){
				for(ll i = 0; i < y - j; i++){
					s += 'L';
				}
			}
			else{
				for(ll i = 0; i < j - y; i++){
					s += 'R';
				}
			}
			dfs(x, j);
			if(j < y){
				for(ll i = 0; i < y - j; i++){
					s += 'R';
				}
			}
			else{
				for(ll i = 0; i < j - y; i++){
					s += 'L';
				}
			}
		}
	}
	return;
}


void dfs2(ll x, ll y){
	vis[x][y] = 1;
	for(ll i = ly[y]; i <= ry[y]; i++){
		if(!vis[i][y]){
			if(i < x){
				for(ll j = 0; j < x - i; j++){
					s += 'U';
				}
			}
			else{
				for(ll j = 0; j < i - x; j++){
					s += 'D';
				}
			}
			dfs2(i, y);
			if(i < x){
				for(ll j = 0; j < x - i; j++){
					s += 'D';
				}
			}
			else{
				for(ll j = 0; j < i - x; j++){
					s += 'U';
				}
			}
		}
	}
	for(ll j = lx[x]; j <= rx[x]; j++){
		if(!vis[x][j]){
			if(j < y){
				for(ll i = 0; i < y - j; i++){
					s += 'L';
				}
			}
			else{
				for(ll i = 0; i < j - y; i++){
					s += 'R';
				}
			}
			dfs2(x, j);
			if(j < y){
				for(ll i = 0; i < y - j; i++){
					s += 'R';
				}
			}
			else{
				for(ll i = 0; i < j - y; i++){
					s += 'L';
				}
			}
		}
	}
	s += '2';
	return;
}

int main(){
	ll x, y;
	fast_io;
	
	cin >> n >> x >> y;
	
	fill(lx + 1, lx + n + 1, n + 1);
	fill(ly + 1, ly + n + 1, n + 1);
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= n; j++){
			cin >> g[i][j];
			if(g[i][j]){
				c++;
				lx[i] = min(lx[i], j);
				ly[j] = min(ly[j], i);
				rx[i] = max(rx[i], j);
				ry[j] = max(ry[j], i);
			}
		}
	}
	
	dfs(x, y);
	if(c){
		cout << "NO";
		return 0;
	}
	
	for(ll i = 1; i <= n; i++){
		fill(vis[i], vis[i] + maxn, 0);
	}
	
	dfs2(x, y);
	
	cout << "YES\n" << s;
	
	return 0;
}