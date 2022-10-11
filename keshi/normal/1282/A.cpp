//In the name of GOD
//Out of competition B-)
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

ll t, a, b, c, x, l, r;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> a >> b >> c >> x;
		if(a > b) swap(a, b);
		l = c - x;
		r = c + x;
		if(a > r || b < l) cout << b - a << '\n';
		else cout << max(0ll, b - r) + max(0ll, l - a) << '\n';
	}
	
	return 0;
}