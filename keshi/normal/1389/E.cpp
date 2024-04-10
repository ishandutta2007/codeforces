//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll q, m, d, w, k, x, t;

int main(){
	fast_io;
	
	cin >> q;
	while(q--){
		cin >> m >> d >> w;
		k = min(m, d);
		x = w / __gcd(d - 1, w);
		t = k / x;
		cout << k * t - t * (t + 1) / 2 * x << '\n';
	}
	
	return 0;
}