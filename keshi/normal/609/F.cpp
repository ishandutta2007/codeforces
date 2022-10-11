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

ll n, m, x, y;
pair<pll, ll> a[maxn];
pll b[maxn];
set<pll> s;
multiset<pll> t;

int main(){
	fast_io;
	
	cin >> n >> m;
	for(ll i = 0; i < n; i++){
		cin >> a[i].F.F >> a[i].F.S;
		a[i].S = i;
		b[i].S = a[i].F.S;
	}
	sort(a, a + n);
	x = -inf;
	s.insert(Mp(x, n));
	for(ll i = 0; i < n; i++){
		if(a[i].F.F + a[i].F.S > x){
			s.insert(Mp(max(x + 1, a[i].F.F), i));
			x = a[i].F.F + a[i].F.S;
		}
	}
	t.insert(Mp(inf, 0ll));
	s.insert(Mp(inf, n));
	a[n] = Mp(Mp(-inf, 0), n);
	for(ll i = 0; i < m; i++){
		cin >> x >> y;
		t.insert(Mp(x, y));
		ll j = (--s.upper_bound(Mp(x, inf))) -> S;
		while(t.lower_bound(Mp(a[j].F.F, -inf)) -> F <= a[j].F.F + a[j].F.S){
			set<pll>::iterator it = t.lower_bound(Mp(a[j].F.F, -inf));
			a[j].F.S += it -> S;
			b[a[j].S].F++;
			b[a[j].S].S = a[j].F.S;
			t.erase(it);
		}
		while((--s.upper_bound(Mp(a[j].F.F + a[j].F.S, inf))) -> S != j){
			set<pll>::iterator it = s.upper_bound(Mp(a[j].F.F + a[j].F.S, inf));
			it--;
			ll k = it -> S;
			s.erase(it);
			if(a[k].F.F + a[k].F.S >= a[j].F.F + a[j].F.S + 1) s.insert(Mp(a[j].F.F + a[j].F.S + 1, k));
		}
	}
	for(ll i = 0; i < n; i++){
		cout << b[i].F << " " << b[i].S << '\n';
	}
	
	return 0;
}