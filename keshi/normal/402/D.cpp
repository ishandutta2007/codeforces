//In the name of GOD
//Hello Yellow
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 5e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, ans, a[maxn], dp[maxn], g[maxn];

map<ll, bool> mp;

ll cal(ll x){
	ll c = 0, d;
	for(ll i = 2; i * i <= x; i++){
		if(x % i == 0){
			d = 1;
			if(mp[i]) d = -1;
			while(x % i == 0){
				c += d;
				x /= i;
			}
		}
	}
	if(x != 1){
		if(mp[x]) c--;
		else c++;
	}
	return -c;
}

int main(){
	ll x;
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		g[i] = __gcd(g[i - 1], a[i]);
	}
	
	for(ll i = 0; i < m; i++){
		cin >> x;
		mp[x] = 1;
	}
	
	for(ll i = 1; i <= n; i++){
		x = cal(g[i]);
		dp[i] = i * x;
		for(ll j = 1; j < i; j++){
			dp[i] = max(dp[i], dp[j] + (i - j) * x);
		}
		ans = max(ans, dp[i]);
	}
	
	for(ll i = 1; i <= n; i++){
		ans -= cal(a[i]);
	}
	
	cout << ans;
	
	return 0;
}