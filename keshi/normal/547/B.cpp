//In the name of GOD
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const ll maxn = 3e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
 
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second
 
ll n, ans[maxn];

pll a[maxn];

set<ll> s;
set<pll> t;
 
int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i].F;
		a[i].S = i;
	}
	
	s.insert(0);
	s.insert(n + 1);
	t.insert({-n - 1, 0});
	
	sort(a + 1, a + n + 1);
	
	for(ll i = 1; i <= n; i++){
		set<ll>::iterator itr = s.upper_bound(a[i].S);
		set<ll>::iterator it = itr;
		it--;
		s.insert(a[i].S);
		ll x = -t.begin() -> F;
		t.erase({*it - *itr, *it});
		t.insert({a[i].S - *itr, a[i].S});
		t.insert({*it - a[i].S, *it});
		ll y = -t.begin() -> F;
		for(ll j = y; j < x; j++){
			ans[j] = a[i].F;
		}
	}
	
	for(ll i = 1; i <= n; i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}