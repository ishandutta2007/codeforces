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
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], fen[maxn], f[maxn], t, ans;

void upd(ll x, ll b){
	for(; x < maxn; x += x & -x){
		fen[x] += b;
	}
	return;
}

ll get(ll x){
	ll b = 0;
	for(; x > 0; x -= x & -x){
		b += fen[x];
	}
	return b;
}

void u(ll x){
	for(; x < maxn; x += x & -x){
		f[x]++;
	}
	return;
}

ll g(ll x){
	ll b = 0;
	for(; x > 0; x -= x & -x){
		b += f[x];
	}
	return b;
}

int main(){
	fast_io;
	
	cout << setprecision(10) << fixed;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		a[i] = n - a[i] + 1;
		ans -= get(a[i]) * (n - i) * 2;
		ans += (n - i) * i * (i + 1) / 2;
		upd(a[i], i + 1);
		t += g(a[i]);
		u(a[i]);
	}
	
	cout << ans * 1.0 / (n * (n + 1)) + t;
	
	return 0;
}