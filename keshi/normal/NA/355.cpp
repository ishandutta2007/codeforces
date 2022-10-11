//In the name of GOD
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

ld n, l, v1, v2, k, s;

bool isval(ld t){
	ld x = (v2 * (l - v1 * t)) / (v2 - v1);
	ld y = (2 * x * v1) / (v1 + v2);
	return l >= x + s * y;
}

int main(){
	cout << fixed << setprecision(10);
	fast_io;
	
	cin >> n >> l >> v1 >> v2 >> k;
	
	s = ceil(n / k) - 1;
	
	ld l = 0, r = 1e10, mid;
	
	for(ll i = 0; i < 1000; i++){
		mid = (l + r) / 2;
		if(isval(mid)){
			r = mid;
		}
		else{
			l = mid;
		}
	}
	
	cout << r;
	
	return 0;
}