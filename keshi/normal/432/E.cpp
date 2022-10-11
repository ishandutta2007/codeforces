// In The Name of GOD
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define Ssecond

ll n, m, v[MAXN][MAXN];

ll val(ll x, ll y){
	if(x < 0 || x >= n || y < 0 || y >= m){
		return 0;
	}
	return v[x][y];
}

bool B(ll x, ll y, ll k){
	if(val(x - 1, y) == k || val(x + 1, y) == k || val(x, y - 1) == k || val(x, y + 1) == k){
		return 0;
	}
	return 1;
}


ll best(ll x, ll y){
	ll d = 0;
	while(y + d < m && val(x, y + d) == 0 && val(x - 1, y + d) != 1){
		d++;
	}
	return min(n - x, d);
}

void adj(ll x, ll y){
	if(val(x, y)){
		return;
	}
	ll d;
	if(B(x, y, 1)){
		d = best(x, y);
		for(ll i = 0; i < d; i++){
			for(ll j = 0; j < d; j++){
				v[x + i][y + j] = 1;
			}
		}
		return;
	}
	if(B(x, y, 2)){
		v[x][y] = 2;
		return;
	}
	if(val(x - 1, y) == 2 || val(x, y + 1) == 2){
		if(B(x, y, 3)){
			v[x][y] = 3;
			return;
		}
		v[x][y] = 4;
		return;
	}
	d = x;
	while(val(d, y - 1) == 2){
		d++;
	}
	if(d == n){
		if(B(x, y, 3)){
			v[x][y] = 3;
			return;
		}
		v[x][y] = 4;
		return;
	}
	for(ll j = x; j <= d; j++){
		v[j][y] = 2;
	}
	for(ll i = y; val(d - 1, i) == 2; i--){
		v[d][i] = 2;
	}
	return;
}

int main(){
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < m; j++){
			adj(i, j);
		}
	}
	
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < m; j++){
			cout << char('A' + (v[i][j] - 1));
		}
		cout << endl;
	}
	
	return 0;
}