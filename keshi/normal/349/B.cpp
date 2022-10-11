#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

const ll maxn = 60;
const ll mod = 1e9;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define X first
#define Y second

ll v, m, t, c, y, a[maxn];

bool isval(ll x){
	if(c * x > v) return 0;
	return v - c * x >= (t - x) * m;
}

ll binary_search(){
	ll l = 0, r = t + 1, mi;
	while(r - l > 1){
		mi = (l + r) / 2;
		if(isval(mi)){
			l = mi;
		}
		else{
			r = mi;
		}
	}
	return l;
}

int main(){
	fast_io;
	cin >> v;
	
	m = inf;
	
	for(ll i = 1; i < 10; i++){
		cin >> a[i];
		m = min(m, a[i]);
	}
	
	t = v / m;
	
	if(t == 0){
		cout << -1;
		return 0;
	}
	
	for(ll i = 9; i > 0; i--){
		c = a[i];
		y = binary_search();
		for(ll j = 0; j < y; j++){
			cout << i;
		}
		t -= y;
		v -= c * y;
	}
	
	return 0;
}