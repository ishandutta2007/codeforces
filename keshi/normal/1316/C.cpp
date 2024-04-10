//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, p, x, y, a, b;

int main(){
	fast_io;
	
	cin >> n >> m >> p;
	
	x = -1;
	y = -1;
	
	for(ll i = 0; i < n; i++){
		cin >> a;
		if(x == -1 && a % p != 0) x = i;
	}
	
	for(ll i = 0; i < m; i++){
		cin >> b;
		if(y == -1 && b % p != 0) y = i;
	}
	
	cout << x + y;
	
	return 0;
}