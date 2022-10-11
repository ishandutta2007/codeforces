//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first.first
#define S first.second
#define ind second

ll n, k, h;

ld ans;

pair<pll, ll> a[maxn];

bool isval(ld t){
	ll x = 0;
	for(ll i = 0; i < n; i++){
		if(x < floor((t * a[i].S) / h)) x++;
	}
	return (x >= k);
}

int main(){
	fast_io;
	
	cin >> n >> k >> h;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i].F;
		a[i].ind = i + 1;
	}
	
	for(ll i = 0; i < n; i++){
		cin >> a[i].S;
	}
	
	sort(a, a + n);
	
	ld l = 0, r = 1e10, mid;
	
	for(ll i = 0; i < 100; i++){
		mid = (l + r) / 2;
		if(isval(mid)){
			r = mid;
		}
		else{
			l = mid;
		}
	}
	
	ll x = 0;
	
	for(ll i = 0; i < n; i++){
		if(x < floor((r * a[i].S) / h)){
			cout << a[i].ind << " ";
			x++;
			if(x == k) return 0;
		}
	}
	
	return 0;
}