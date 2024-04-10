#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 262200;
const ll maxm = 110;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll x, n, m, a[20], cnt[10], fac[20], dp[maxn][maxm], t, ans;

vector<ll> v;

vector<pll> vec;

int main(){
	fast_io;
	
	cin >> x >> m;
	
	while(x){
		a[n] = x % 10;
		cnt[a[n]]++;
		n++;
		x /= 10;
	}
	
	fac[0] = 1;
	for(ll i = 1; i < 19; i++){
		fac[i] = i * fac[i - 1];
	}
	
	for(ll i = 0; i < 1ll << n; i++){
		t = 0;
		for(ll j = 0; j < n; j++){
			if((i >> j) & 1){
				t++;
			}
		}
		vec.pb({t, i});
	}
	
	sort(vec.begin(), vec.end());
	
	dp[0][0] = 1;
	
	for(ll o = 0; o < vec.size(); o++){
		ll i = vec[o].S;
		v.clear();
		for(ll j = 0; j < n; j++){
			if(((i >> j) & 1) == 0){
				v.pb(j);
			}
		}
		for(ll j = 0; j < m; j++){
			if(dp[i][j] == 0) continue;
			for(ll k = 0; k < v.size(); k++){
				dp[i + (1ll << v[k])][(10 * j + a[v[k]]) % m] += dp[i][j];
			}
		}
	}
	
	ans = dp[(1ll << n) - 1][0];
	for(ll i = 0; i < n; i++){
		if(a[i] == 0) ans -= dp[(1ll << n) - 1 - (1ll << i)][0];
	}
	
	for(ll i = 0; i < 10; i++){
		ans /= fac[cnt[i]];
	}
	
	cout << ans;
	
	return 0;
}