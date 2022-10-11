//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n;

ld p, a[maxn], b[maxn];

bool val(ld x){
	ld s = 0;
	ld z = 0;
	for(ll i = 0; i < n; i++){
		s += max(z, x * a[i] - b[i]);
	}
	return (s <= x * p);
}

int main(){
	ll c = 0;
	ld s = 0;
	fast_io;
	cout << setprecision(10) << fixed;
	
	cin >> n >> p;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i] >> b[i];
		if(b[i] == 0) c++;
		s += a[i];
	}
	
	if(c > 1){
		cout << 0;
		return 0;
	}
	
	if(s <= p){
		cout << -1;
		return 0;
	}
	
	ld l = 0, r = 1e18, mid;
	
	for(ll i = 0; i < 100; i++){
		mid = (l + r) / 2;
		if(val(mid)) l = mid;
		else r = mid;
	}
	
	cout << l;
	
	return 0;
}