//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const ld pi = 3.141592653589793238462643383279;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll q;
ld n, x, y, a, b, c, t;

int main(){
	fast_io;
	cout << setprecision(20) << fixed;
	
	cin >> q;
	
	while(q--){
		cin >> n;
		n *= 2;
		x = cos(pi / n) / sin(pi / n) / 2;
		y = sqrt(x * x + 0.25);
		t = floor(n / 4);
		a = 90 / n * (n - 2 * t);
		b = (y - 0.5) / cos(a * pi / 180);
		a = 90 - a;
		c = (y + 0.5) / cos(a * pi / 180);
		cout << (b + c) / sqrt(2) << '\n';
	}
	
	return 0;
}