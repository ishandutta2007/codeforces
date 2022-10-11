//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, t, x;

vector<ll> ans;

map<pll, ll> mp;

set<ll> s;

void dfs(ll v){
    x++;
	ll u;
	s.erase(v);
	set<ll>::iterator it = s.begin();
	while(it != s.end()){
		u = *it;
		if(!mp[{v, u}]){
			dfs(u);
		}
		it = s.upper_bound(u);
	}
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		mp[{v, u}] = 1;
		mp[{u, v}] = 1;
	}
	
	for(ll i = 1; i <= n; i++){
		s.insert(i);
	}
	
	for(ll i = 1; i <= n; i++){
		if(s.find(i) != s.end()){
			t++;
			x = 0;
			dfs(i);
			ans.pb(x);
		}
	}
	
	cout << t << endl;
	
	sort(ans.begin(), ans.end());
	
	for(ll i = 0; i < t; i++){
	    cout << ans[i] << " ";
	}
	
	return 0;
}