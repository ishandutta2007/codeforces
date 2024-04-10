//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef __int128 ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

long long s;

ll n, k, x, a[maxn];

vector<ll> c[maxn];

bool val(ll t){
	x = 0;
	x += a[0];
	x += (t + 1) * a[1];
	if(n > 2 && t < 1e10) x += (t + 1) * (t + 2) / 2 * a[2];
	else if(n > 2 && a[2]) return 1;
	for(ll i = 3; i < n; i++){
		if(x >= k) return 1;
		if(t >= c[i].size() && a[i] > 0) return 1;
		else if(t < c[i].size()) x += c[i][t] * a[i];
	}
	return (x >= k);
}
int main(){
	fast_io;
	
	for(ll i = 3; i < maxn; i++){
		x = 1;
		ll j = 1;
		while(x < 1e18){
			c[i].pb(x);
			x = x * (i + j) / j;
			j++;
		}
	}
	
	cin >> s;
	n = s;
	cin >> s;
	k = s;
	
	for(ll i = 1; i <= n; i++){
		cin >> s;
		a[n - i] = s;
	}
	
	if(*max_element(a, a + n) >= k){
		cout << 0;
		return 0;
	}
	
	ll l = 0, r = 1e18, mid;
	
	while(r - l > 1){
		mid = (l + r) / 2;
		if(val(mid - 1)) r = mid;
		else l = mid;
	}
	
	s = r;
	
	cout << s;
	
	return 0;
}