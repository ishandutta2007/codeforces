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
#define F first
#define S second

ll n, x, y, l, a[maxn], t, k;

bool f[4];

int main(){
	fast_io;
	
	cin >> n >> l >> x >> y;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(ll i = 0; i < n; i++){
		if(*lower_bound(a, a + n, a[i] + x) == a[i] + x) f[0] = 1;
		if(*lower_bound(a, a + n, a[i] + y) == a[i] + y) f[1] = 1;
		if(*lower_bound(a, a + n, a[i] + x + y) == a[i] + x + y){f[2] = 1; t = a[i] + x;}
		if(*lower_bound(a, a + n, a[i] + y - x) == a[i] + y - x){
			if(a[i] + y <= l){
				f[3] = 1;
				k = a[i] + y;
			}
			if(a[i] - x >= 0){
				f[3] = 1;
				k = a[i] - x;
			}
		}
	}
	
	if(f[0] && f[1]){
		cout << 0;
		return 0;
	}
	if(f[0]){
		cout << 1 << endl << y;
		return 0;
	}
	if(f[1]){
		cout << 1 << endl << x;
		return 0;
	}
	if(f[2]){
		cout << 1 << endl << t;
		return 0;
	}
	if(f[3]){
		cout << 1 << endl << k;
		return 0;
	}
	cout << 2 << endl << x << " " << y;
	
	return 0;
}