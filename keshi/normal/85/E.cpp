//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 5e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n;

bool vis[maxn], c[maxn];

pll a[maxn];

ll dis(ll i, ll j){
	return abs(a[i].F - a[j].F) + abs(a[i].S - a[j].S);
}

bool dfs(ll v, ll x, bool e){
	vis[v] = 1;
	c[v] = e;
	for(ll i = 0; i < n; i++){
		if(dis(i, v) > x){
			if(!vis[i]){
				if(!dfs(i, x, !e)) return 0;
			}
			else{
				if(c[i] == c[v]){
					return 0;
				}
			}
		}
	}
	return 1;
}

bool isval(ll x){
	fill(vis, vis + maxn, 0);
	for(ll i = 0; i < n; i++){
		if(!vis[i]){
			if(!dfs(i, x, 0)) return 0;
		}
	}
	return 1;
}

ll cal(ll x){
	fill(vis, vis + maxn, 0);
	ll ans = 1;
	for(ll i = 0; i < n; i++){
		if(!vis[i]){
			dfs(i, x, 0);
			ans = ans * 2;
			if(ans > mod){
				ans -= mod;
			}
		}
	}
	return ans;
}
 
int main(){
	ll u, v;
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i].F >> a[i].S;
	}
	
	ll l = -1, r = 10000, mid;
	
	while(r - l > 1){
		mid = (l + r) / 2;
		if(isval(mid)){
			r = mid;
		}
		else{
			l = mid;
		}
	}
	
	cout << r << endl << cal(r);
	
	return 0;
}