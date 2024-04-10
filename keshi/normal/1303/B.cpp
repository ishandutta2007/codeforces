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

ll t, n, g, b, a, x;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> n >> g >> b;
		x = n;
		n = (n + 1) / 2;
		if(n % g == 0) a = (g + b) * (n / g) - b;
		else a = (g + b) * (n / g) + n % g;
		cout << max(a, x) << '\n';
	}
	
	return 0;
}