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

ll w, h, n, x;

set<pll> s1, s2, d1, d2;

char c;

set<pll>::iterator j, k;

int main(){
	fast_io;
	
	cin >> w >> h >> n;
	
	s1.insert({0, -4});
	s2.insert({0, -3});
	s1.insert({w, -2});
	s2.insert({h, -1});
	d1.insert({-w, -4});
	d2.insert({-h, -3});
	
	for(ll i = 0; i < n; i++){
		cin >> c >> x;
		if(c == 'V'){
			j = s1.lower_bound({x, -5ll});
			k = j;
			k--;
			d1.erase({k -> F - j -> F, k -> S});
			d1.insert({x - j -> F, i});
			d1.insert({k -> F - x, k -> S});
			s1.insert({x, i});
		}
		else{
			j = s2.lower_bound({x, -5ll});
			k = j;
			k--;
			d2.erase({k -> F - j -> F, k -> S});
			d2.insert({x - j -> F, i});
			d2.insert({k -> F - x, k -> S});
			s2.insert({x, i});
		}
		cout << d1.begin() -> F * d2.begin() -> F << '\n';
	}
	
	return 0;
}