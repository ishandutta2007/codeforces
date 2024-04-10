//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, h[maxn], ps[maxn], a, r, m, ans;

pll calp(ll x){
	ll j = upper_bound(h + 1, h + n + 1, x) - h - 1;
	return Mp(j * x - ps[j], ps[n] - ps[j] - (n - j) * x);
}
ll cal(ll x){
	pll p = calp(x);
	if(m > a + r) return p.F * a + p.S * r;
	if(p.F <= p.S) return p.F * m + (p.S - p.F) * r;
	return p.S * m + (p.F - p.S) * a;
}

int main(){
	fast_io;
	
	cin >> n >> a >> r >> m;
	for(ll i = 1; i <= n; i++){
		cin >> h[i];
	}
	sort(h + 1, h + 1 + n);
	for(ll i = 1; i <= n; i++){
		ps[i] = ps[i - 1] + h[i];
	}
	h[n + 1] = 1e10;
	
	ll l = 0, r = 1e10, mid, m1, m2;
	while(r - l > 1){
		mid = (l + r) / 2;
		if(calp(mid).F <= calp(mid).S) l = mid;
		else r = mid;
	}
	ans = inf;
	for(ll i = 0; i <= n; i++){
		if(h[i + 1] <= l){
			if(m <= a + r){
				if(i * m - n * r >= 0) ans = min(ans, cal(h[i]));
				else ans = min(ans, cal(h[i + 1]));
			}
			else{
				if(i * (a + r) - r * n >= 0) ans = min(ans, cal(h[i]));
				else ans = min(ans, cal(h[i + 1]));
			}
		}
		if(h[i] > l){
			if(m <= a + r){
				if((i - n) * m + n * a >= 0) ans = min(ans, cal(h[i]));
				else ans = min(ans, cal(h[i + 1]));
			}
			else{
				if(i * (a + r) - a * n >= 0) ans = min(ans, cal(h[i]));
				else ans = min(ans, cal(h[i + 1]));
			}
		}
		else{
			if(m <= a + r){
				if(i * m - n * r >= 0) ans = min(ans, cal(h[i]));
				else ans = min(ans, cal(l));
			}
			else{
				if(i * (a + r) - r * n >= 0) ans = min(ans, cal(h[i]));
				else ans = min(ans, cal(l));
			}
			if(m <= a + r){
				if((i - n) * m + n * a >= 0) ans = min(ans, cal(l + 1));
				else ans = min(ans, cal(h[i + 1]));
			}
			else{
				if(i * (a + r) - a * n >= 0) ans = min(ans, cal(l + 1));
				else ans = min(ans, cal(h[i + 1]));
			}
		}
	}
	cout << ans;
	
	return 0;
}