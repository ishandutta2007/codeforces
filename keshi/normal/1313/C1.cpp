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

ll n, a[maxn], m, s, x, ans, b[maxn];

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(ll i = 0; i < n; i++){
		m = a[i];
		s = m;
		for(ll j = i; j--;){
			s += min(a[j], m);
			m = min(a[j], m);
		}
		m = a[i];
		for(ll j = i + 1; j < n; j++){
			s += min(a[j], m);
			m = min(a[j], m);
		}
		if(ans < s){
			ans = s;
			x = i;
		}
	}
	
	b[x] = a[x];
	m = a[x];
	
	for(ll j = x; j--;){
		b[j] = min(a[j], m);
		m = min(a[j], m);
	}
	m = a[x];
	for(ll j = x + 1; j < n; j++){
		b[j] = min(a[j], m);
		m = min(a[j], m);
	}
	
	for(ll i = 0; i < n; i++){
		cout << b[i] << " ";
	}
	
	return 0;
}