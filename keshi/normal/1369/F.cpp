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

ll t, m, n;
bool f, q;
vector<pair<pll, ll> > a;
vector<pll> b;

void solve(ll x){
	if(x < 1) return;
	if(x & 1){
		a.pb(Mp(Mp(1, x), 2));
		return;
	}
	a.pb(Mp(Mp(x / 2 + 1, x), 2));
	a.pb(Mp(Mp(x / 4 + 1, x / 2), 0));
	solve(x / 4);
	return;
}

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> m >> n;
		a.clear();
		solve(n);
		f = q = 0;
		for(ll i = 0; i < a.size(); i++){
			if(a[i].F.F <= m && m <= a[i].F.S){
				if(a[i].S == 0) f = 1;
				if(a[i].S == 1 && (a[i].F.S - m) % 2 == 0) f = 1;
				if(a[i].S == 2 && (a[i].F.S - m) % 2 == 1) f = 1;
			}
		}
		a.clear();
		a.pb(Mp(Mp(n / 2 + 1, n), 0));
		solve(n / 2);
		q = 0;
		for(ll i = 0; i < a.size(); i++){
			if(a[i].F.F <= m && m <= a[i].F.S){
				if(a[i].S == 0) q = 1;
				if(a[i].S == 1 && (a[i].F.S - m) % 2 == 0) q = 1;
				if(a[i].S == 2 && (a[i].F.S - m) % 2 == 1) q = 1;
			}
		}
		b.pb(Mp(f, q));
	}
	reverse(b.begin(), b.end());
	f = b[0].F;
	q = b[0].S;
	for(ll i = 1; i < b.size(); i++){
		if(b[i].S && f || b[i].F && (!f)) f = 1;
		else f = 0;
		if(b[i].S && q || b[i].F && (!q)) q = 1;
		else q = 0;
	}
	cout << f << " " << q;
	
	return 0;
}