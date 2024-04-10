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
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, k, x;

ll cal(ll a){
	ll b = 10, c = -1;
	while(a){
		b = min(b, a % 10);
		c = max(c, a % 10);
		a /= 10;
	}
	return b * c;
}

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n >> k;
		while(--k){
			x = cal(n);
			if(x == 0) break;
			n += x;
		}
		cout << n << '\n';
	}
	
	return 0;
}