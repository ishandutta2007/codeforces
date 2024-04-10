//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 4e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, q, t, l, r, b[maxn], a[maxn], fen[maxn];

void upd(ll x, ll y){
	for(; x < maxn; x += x & -x){
		fen[x] += y;
	}
	return;
}

ll get(ll x){
	ll y = 0;
	for(; x > 0; x -= x & -x){
		y += fen[x];
	}
	return y;
}

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> b[i];
		a[b[i]] = i;
	}
	
	a[n + 1] = n + 1;
	
	for(ll i = 0; i <= n; i++){
		if(a[i] > a[i + 1]) upd(i + 1, 1);
	}
	
	cin >> q;
	
	for(ll i = 0; i < q; i++){
		cin >> t >> l >> r;
		if(t == 2){
			swap(b[l], b[r]);
			l = b[l];
			r = b[r];
			if(l > r) swap(l, r);
			if(a[l - 1] > a[l]) upd(l, -1);
			if(a[l] > a[l + 1]) upd(l + 1, -1);
			if(r - l > 1 && a[r - 1] > a[r]) upd(r, -1);
			if(r - 1 > 0 && a[r] > a[r + 1]) upd(r + 1, -1);
			swap(a[l], a[r]);
			if(a[l - 1] > a[l]) upd(l, 1);
			if(a[l] > a[l + 1]) upd(l + 1, 1);
			if(r - l > 1 && a[r - 1] > a[r]) upd(r, 1);
			if(r - 1 > 0 && a[r] > a[r + 1]) upd(r + 1, 1);
		}
		else{
			cout << get(r) - get(l) + 1 << '\n';
		}
	}
	
	return 0;
}