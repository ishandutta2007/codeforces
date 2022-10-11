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

ll n, m, k;

vector<pair<ll, char> > a, b;

int main(){
	fast_io;
	
	cin >> n >> m >> k;
	
	for(ll i = 1; i < n; i++){
		a.pb({m - 1, 'R'});
		a.pb({m - 1, 'L'});
		a.pb({1ll, 'D'});
	}
	for(ll i = 1; i < m; i++){
		a.pb({1ll, 'R'});
		a.pb({n - 1, 'U'});
		a.pb({n - 1, 'D'});
	}
	a.pb({m - 1, 'L'});
	a.pb({n - 1, 'U'});
	
	for(ll i = 0; i < a.size(); i++){
		a[i].F = min(a[i].F, k);
		k -= a[i].F;
		if(a[i].F == 0) continue;
		b.pb({a[i].F, a[i].S});
	}
	
	if(k){
		cout << "NO";
		return 0;
	}
	
	cout << "YES\n" << b.size() << '\n';
	
	for(ll i = 0; i < b.size(); i++){
		cout << b[i].F << " " << b[i].S << '\n';
	}
	
	return 0;
}