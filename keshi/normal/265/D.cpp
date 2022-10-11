//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, dp[maxn], p[maxn], ans, m, a;

vector<ll> v[maxn];

int main(){
	fast_io;
	
	for(ll i = 2; i < maxn; i++){
		if(p[i] == 0){
			p[i] = i;
			for(ll j = i * i; j < maxn; j += i){
				p[j] = i;
			}
		}
	}
	
	for(ll i = 2; i < maxn; i++){
		ll x = i;
		while(x != 1){
			v[i].pb(p[x]);
			while(x % v[i].back() == 0){
				x /= v[i].back();
			}
		}
	}
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a;
		m = 0;
		for(ll j = 0; j < v[a].size(); j++){
			m = max(m, dp[v[a][j]]);
		}
		for(ll j = 0; j < v[a].size(); j++){
			dp[v[a][j]] = m + 1;
		}
		ans = max(ans, m + 1);
	}
	
	cout << ans;
	
	return 0;
}