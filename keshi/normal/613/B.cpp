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

ll n, c, cf, cm, m, b[maxn], ps[maxn], sp[maxn], ans, ma, mb;

pll a[maxn];

ll cal(ll t, ll i){
	if(t > c) return inf;
	ll j = upper_bound(a + 1, a + i + 1, make_pair(t, 0ll)) - a - 1;
	return t * j - ps[j];
}

int main(){
	fast_io;
	
	cin >> n >> c >> cf >> cm >> m;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i].F;
		a[i].S = i;
	}
	
	a[n + 1].F = inf;
	
	sort(a + 1, a + n + 1);
	
	for(ll i = 1; i <= n; i++){
		ps[i] = ps[i - 1] + a[i].F;
	}
	
	for(ll i = 1; i <= n; i++){
		sp[i] = sp[i - 1] + a[n - i + 1].F;
	}
	
	for(ll i = 0; i <= n; i++){
		ll x = m - i * c + sp[i];
		if(x < 0) continue;
		ll l = 0, r = c + 1, mid;
		while(r - l > 1){
			mid = (l + r) / 2;
			if(cal(mid, n - i) <= x){
				l = mid;
			}
			else{
				r = mid;
			}
		}
		if(i * cf + l * cm > ans){
			ans = i * cf + l * cm;
			ma = i;
			mb = l;
		}
	}
	
	for(ll i = 0; i < ma; i++){
		a[n - i].F = c;
	}
	
	for(ll i = 1; i <= n; i++){
		a[i].F = max(a[i].F, mb);
		b[a[i].S] = a[i].F;
	}
	
	cout << ans << endl;
	
	for(ll i = 1; i <= n; i++){
		cout << b[i] << " ";
	}
	
	return 0;
}