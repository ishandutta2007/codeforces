#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 100;
const long long mod = 1e9 + 7;
const long long inf = 1e18;

typedef long long ll;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, u, v, ans, c[maxn];

set<ll> s[maxn];

int main(){
	fast_io;
	
	cin >> n >> m;
	
	ans = inf;
	
	for(ll i = 1; i <= n; i++){
		cin >> c[i];
		ans = min(ans, c[i]);
	}
	
	for(ll i = 0; i < m; i++){
		cin >> u >> v;
		if(c[u] != c[v]){
			s[c[u]].insert(c[v]);
			s[c[v]].insert(c[u]);
		}
	}
	for(ll i = maxn - 1; i > 0; i--){
		if(s[i].size() > 0 && s[i].size() >= s[ans].size()){
			ans = i;
		}
	}
	
	cout << ans;
	
	return 0;
}