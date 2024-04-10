#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, a[maxn][maxn];

bool vis[maxn][maxn];

vector<ll> v;

ll isval(ll x){
	for(ll i = 0; i < m; i++){
		for(ll j = 0; j < m; j++){
			vis[i][j] = 0;
		}
	}
	for(ll i = 0; i < n; i++){
		v.clear();
		for(ll j = 0; j < m; j++){
			if(a[i][j] >= x){
				v.pb(j);
			}
		}
		for(ll j = 0; j < v.size(); j++){
			for(ll k = j + 1; k < v.size(); k++){
				if(vis[v[j]][v[k]]){
					return 1;
				}
				vis[v[j]][v[k]] = 1;
			}
		}
	}
	return 0;
}

ll binary_search(){
	ll l = 0, r = 1e9 + 1, mi;
	while(r - l > 1){
		mi = (l + r) / 2;
		if(isval(mi)){
			l = mi;
		}
		else{
			r = mi;
		}
	}
	return l;
}

int main(){
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	
	cout << binary_search();
	
	return 0;
}