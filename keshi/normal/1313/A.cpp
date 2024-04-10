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

ll t, a[3], b[3], c, d;

void fix(ll n){
	for(ll i = 0; i < 3; i++){
		if(n % 2) b[i]++;
		n /= 2;
	}
	return;
}

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> a[0] >> a[1] >> a[2];
		c = 0;
		for(ll i = 0; i < (1 << 7); i++){
			b[0] = b[1] = b[2] = 0;
			d = 0;
			for(ll j = 0; j < 7; j++){
				if((i >> j) & 1){
					fix(j + 1);
					d++;
				}
			}
			if(a[0] >= b[0] && a[1] >= b[1] && a[2] >= b[2]) c = max(c, d);
		}
		cout << c << '\n';
	}
	
	return 0;
}