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

ll n, a, s, l, ans;

map<ll, ll> c;
map<ll, bool> v;

int main(){
	fast_io;
	
	cin >> n;
	
	v[0] = 1;
	c[0] = -1;
	l = -1;
	
	for(ll i = 0; i < n; i++){
		cin >> a;
		s += a;
		if(v[s]) l = max(l, c[s] + 1);
		v[s] = 1;
		c[s] = i;
		ans += i - l;
	}
	
	cout << ans;
	
	return 0;
}