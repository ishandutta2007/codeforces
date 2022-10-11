//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, b[maxn], ans[maxn];

pll a[maxn], c[maxn];

vector<ll> v, g[maxn], h[maxn], d[maxn];

map<ll, ll> mp;

set<pll> s;

int main(){
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i].F >> a[i].S;
	}
	
	for(ll i = 0; i < m; i++){
		cin >> b[i];
		v.pb(b[i]);
	}
	
	for(ll i = 1; i < n; i++){
		c[i].F = a[i].F - a[i - 1].S;
		v.pb(c[i].F);
		c[i].S = a[i].S - a[i - 1].F;
		v.pb(c[i].S);
	}
	
	sort(v.begin(), v.end());
	
	for(ll i = 0; i < v.size(); i++){
		mp[v[i]] = i;
	}
	
	for(ll i = 0; i < m; i++){
		b[i] = mp[b[i]];
		d[b[i]].pb(i + 1);
	}
	
	for(ll i = 1; i < n; i++){
		c[i].F = mp[c[i].F];
		g[c[i].F].pb(i);
		c[i].S = mp[c[i].S];
		h[c[i].S].pb(i);
	}
	
	for(ll i = 0; i < v.size(); i++){
		for(ll j = 0; j < g[i].size(); j++){
			s.insert({c[g[i][j]].S, g[i][j]});
		}
		
		for(ll j = 0; j < d[i].size(); j++){
			if(s.empty()) break;
			ans[s.begin() -> S] = d[i][j];
			s.erase(s.begin());
		}
		
		for(ll j = 0; j < h[i].size(); j++){
			s.erase({c[h[i][j]].S, h[i][j]});
		}
	}
	
	if(*min_element(ans + 1, ans + n) == 0){
		cout << "No";
		return 0;
	}
	
	cout << "Yes\n";
	
	for(ll i = 1; i < n; i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}