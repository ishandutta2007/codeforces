//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e3 + 100;
const ll maxm = 1e4 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, m, t, b[maxm], a[maxn];

pll dp[maxn][maxm];

bool f[maxn][maxm];

vector<ll> g, h[maxm], d, p, c;

map<ll, ll> mp;

int main(){
	ll x;
	fast_io;
	
	cin >> n >> k;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	if(k == 1){
		cout << "1\n";
		x = 1;
		for(ll i = 1; i <= n; i++){
			if(a[x] > a[i]) x = i;
		}
		cout << x;
		return 0;
	}
	
	x = k;
	
	for(ll i = 2; i * i <= x; i++){
		if(x % i) continue;
		p.pb(i);
		c.pb(0);
		while(x % i == 0){
			c.back()++;
			x /= i;
		}
	}
	
	if(x != 1){
		p.pb(x);
		c.pb(1);
	}
	
	for(ll i = 1; i * i <= k; i++){
		if(k % i == 0){
			g.pb(i);
			if(i * i != k) g.pb(k / i);
		}
	}
	
	m = g.size();
	t = p.size();
	for(ll i = 0; i < m; i++){
		x = g[i];
		ll y = 0;
		mp[x] = i;
		for(ll j = 0; j < t; j++){
			h[i].pb(0);
			while(x % p[j] == 0){
				h[i].back()++;
				x /= p[j];
			}
			y = y * (c[j] + 1) + h[i].back();
		}
		b[y] = i;
	}
	
	fill(dp[0], dp[0] + maxm, make_pair(inf, inf));
	dp[0][0] = make_pair(0, 0);
	
	for(ll i = 1; i <= n; i++){
		x = a[i];
		d.clear();
		for(ll j = 0; j < t; j++){
			d.pb(0);
			while(x % p[j] == 0){
				d.back()++;
				x /= p[j];
			}
		}
		for(ll j = 0; j < m; j++){
			x = 0;
			for(ll l = 0; l < t; l++){
				x = x * (c[l] + 1) + max(0ll, h[j][l] - d[l]);
			}
			x = b[x];
			dp[i][j] = min(dp[i - 1][j], make_pair(dp[i - 1][x].F + 1, dp[i - 1][x].S + a[i]));
			if(dp[i][j] < dp[i - 1][j]) f[i][j] = 1;
		}
	}
	
	if(dp[n][mp[k]].F == inf){
		cout << -1;
		return 0;
	}
	
	cout << dp[n][mp[k]].F << '\n';
	
	while(n){
		if(f[n][mp[k]]){
			cout << n << " ";
			k /= __gcd(k, a[n]);
		}
		n--;
	}
	
	return 0;
}