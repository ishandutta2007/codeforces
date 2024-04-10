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

ll q, n, a[maxn];

ll cal(ll t){
	ll x = 0;
	for(ll i = t; i > -1; i--){
		x = x * 3 + a[i];
	}
	return x;
}

void solve(ll x){
	ll d = x, t = 0, j = -1;
	while(d){
		a[t] = d % 3;
		d /= 3;
		t++;
	}
	a[t] = 0;
	bool f = 0;
	for(ll i = 0; i <= t; i++){
		if(a[i] == 0 && f){
			j = i;
			f = 0;
		}
		if(a[i] == 2) f = 1;
	}
	if(j == -1){
		cout << x << endl;
		return;
	}
	fill(a, a + j, 0);
	a[j] = 1;
	cout << cal(t) << endl;
}

int main(){
	fast_io;
	
	cin >> q;
	
	while(q--){
		cin >> n;
		solve(n);
	}
	
	return 0;
}