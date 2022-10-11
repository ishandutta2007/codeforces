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

ll n, x, s;

ll cal(ll b){
	ll y = 0;
	while(b){
		y += b % 10;
		b /= 10;
	}
	return y;
}

int main(){
	fast_io;
	
	x = 1;
	cin >> n;
	s = n;
	while(s){
		s /= 10;
		x *= 10;
	}
	x /= 10;
	x--;
	cout << max(cal(n), cal(x) + cal(n - x));
	
	return 0;
}