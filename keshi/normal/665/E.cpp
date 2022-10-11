//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 3e7 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, h[maxn], c[maxn], a[maxn], b[maxn], t;
long long ans;

void upd(ll id, ll x){
	c[id]++;
	if(h[id] == -1) return;
	if((x >> h[id]) & 1){
		if(b[id] == 0){
			b[id] = t;
			h[t++] = h[id] - 1;
		}
		upd(b[id], x);
	}
	else{
		if(a[id] == 0){
			a[id] = t;
			h[t++] = h[id] - 1;
		}
		upd(a[id], x);
	}
	return;
}
void get(ll id, ll x, ll k){
	if(h[id] == -1) return;
	if((x >> h[id]) & 1){
		if(k <= (1ll << h[id])){
			if(a[id]) ans += c[a[id]];
			if(b[id]) get(b[id], x, k);
		}
		else{
			if(a[id]) get(a[id], x, k - (1ll << h[id]));
		}
	}
	else{
		if(k <= (1ll << h[id])){
			if(b[id]) ans += c[b[id]];
			if(a[id]) get(a[id], x, k);
		}
		else{
			if(b[id]) get(b[id], x, k - (1ll << h[id]));
		}
	}
	return;
}

int main(){
	ll x = 0, y, k;
	fast_io;
	
	h[t++] = 30;
	cin >> n >> k;
	upd(0, x);
	for(ll i = 0; i < n; i++){
		cin >> y;
		x = x ^ y;
		get(0, x, k);
		upd(0, x);
	}
	cout << ans;
	
	return 0;
}