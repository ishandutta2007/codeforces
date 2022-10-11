//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, c, a[maxn], ans[maxn];
bool vis[maxn];
vector<ll> vec;
vector<pll> q[maxn];

int main(){
	fast_io;
	ll l, x;
	
	cin >> n >> m;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	for(ll i = 0; i < m; i++){
		cin >> l >> x;
		q[l - 1].pb(Mp(x, i));
	}
	vis[0] = 1;
	c = 1;
	vec.pb(0);
	for(ll i = 0; i < n; i++){
		if(vis[a[i]]) c = (c * 2) % mod;
		else{
			x = vec.size();
			for(ll j = 0; j < x; j++){
				vis[a[i] ^ vec[j]] = 1;
				vec.pb(a[i] ^ vec[j]);
			}
		}
		for(ll j = 0; j < q[i].size(); j++){
			ans[q[i][j].S] = (vis[q[i][j].F] ? c : 0);
		}
	}
	for(ll i = 0; i < m; i++){
		cout << ans[i] << '\n';
	}
	
	return 0;
}