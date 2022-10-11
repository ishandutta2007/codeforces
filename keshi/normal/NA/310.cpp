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

ll n, a[maxn], A, B, ps[maxn];

vector<ll> vec;

ll solve(ll x){
	ll ans = -inf, l = n + 1, r = -1, y = 0, o = 0;
	for(ll i = 1; i <= n; i++){
		ps[i] = ps[i - 1];
		if(a[i] % x && (a[i] - 1) % x && (a[i] + 1) % x) r = max(r, i), l = min(l, i);
		else if(a[i] % x) ps[i]++, o += A;
	}
	for(ll i = 1; i <= n; i++){
		if(i < l) y = max(y, i * B - ps[i] * A);
		if(i >= r) ans = max(ans, (ps[i] * A - i * B) + y);
	}
	return o - ans;
}

int main(){
	ll x;
	fast_io;
	
	cin >> n >> B >> A;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(ll i = a[1] - 1; i <= a[1] + 1; i++){
		x = i;
		for(ll j = 2; j * j <= x; j++){
			if(x % j == 0){
				vec.pb(j);
				while(x % j == 0) x /= j;
			}
		}
		if(x != 1) vec.pb(x);
	}
	for(ll i = a[n] - 1; i <= a[n] + 1; i++){
		x = i;
		for(ll j = 2; j * j <= x; j++){
			if(x % j == 0){
				vec.pb(j);
				while(x % j == 0) x /= j;
			}
		}
		if(x != 1) vec.pb(x);
	}
	sort(vec.begin(), vec.end());
	
	ll ans = inf;
	
	for(ll i = 0; i < vec.size(); i++){
		if(i == 0 || vec[i] != vec[i - 1]) ans = min(ans, solve(vec[i]));
	}
	
	cout << ans;
	
	return 0;
}