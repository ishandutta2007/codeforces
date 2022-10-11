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

ll n, a[maxn], b[maxn], h[maxn], ans[maxn];

pair<pll, ll> p[maxn];

set<pll> s, d;

vector<ll> v;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i] >> b[i] >> h[i];
		p[i] = {{b[i], a[i]}, i};
	}
	
	sort(p, p + n, greater<pair<pll, ll> >());
	
	
	d.insert({0, -1});
	
	for(ll i = 0; i < n; i++){
		v.clear();
		for(set<pll>::iterator it = s.begin(); it != s.end(); it++){
			if(-(it -> F) < p[i].F.F) break;
			v.pb(it -> S);
		}
		for(ll j = 0; j < v.size(); j++){
			s.erase({-a[p[v[j]].S], v[j]});
			d.erase({-ans[v[j]], v[j]});
		}
		ans[i] = -(d.begin() -> F) + h[p[i].S];
		s.insert({-a[p[i].S], i});
		d.insert({-ans[i], i});
	}
	
	cout << *max_element(ans, ans + n);
	
	return 0;
}