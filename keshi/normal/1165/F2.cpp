//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 5e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, a[maxn], s, d[maxn];

pll o[maxn];

vector<ll> g[maxn];

bool isval(ll t){
	ll mo = 0, u = s;
	fill(d, d + n + 1, -1);
	for(ll i = 1; i <= t; i++){
		g[i].clear();
	}
	ll x = upper_bound(o, o + m, make_pair(t, inf)) - o;
	for(ll i = x - 1; i > -1; i--){
		if(d[o[i].S] == -1){
			d[o[i].S] = i;
			g[o[i].F].pb(o[i].S);
		}
	}
	for(ll i = 1; i <= t; i++){
		mo++;
		for(ll j = 0; j < g[i].size(); j++){
			u -= min(mo, a[g[i][j]]);
			mo -= min(mo, a[g[i][j]]);
		}
	}
	return (u * 2 <= mo);
}

int main(){
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		s += a[i];
	}
	
	for(ll i = 0; i < m; i++){
		cin >> o[i].F >> o[i].S;
	}
	
	sort(o, o + m);
	
	ll l = 0, r = 2 * s, mid;
	
	while(r - l > 1){
		mid = (l + r) / 2;
		if(isval(mid)){
			r = mid;
		}
		else{
			l = mid;
		}
	}
	
	cout << r;
	
	return 0;
}