//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n;

ld x[maxn], y[maxn];

int main(){
	ld h, a1, b1, a2, b2, x1, y1;
	fast_io;
	cout << setprecision(10) << fixed;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> x[i] >> y[i];
	}
	
	x[0] = x[n];
	y[0] = y[n];
	x[n + 1] = x[1];
	y[n + 1] = y[1];
	
	h = inf;
	
	for(ll i = 1; i <= n; i++){
		if(x[i - 1] == x[i + 1]) h = min(h, abs(x[i] - x[i - 1]));
		else if(y[i - 1] == y[i + 1]) h = min(h, abs(y[i] - y[i - 1]));
		else{
			a1 = (y[i + 1] - y[i - 1]) / (x[i + 1] - x[i - 1]);
			b1 = y[i + 1] - a1 * x[i + 1];
			a2 = -1 / a1;
			b2 = y[i] - a2 * x[i];
			x1 = (b2 - b1) / (a1 - a2);
			y1 = a1 * x1 + b1;
			h = min(h, sqrt((x1 - x[i]) * (x1 - x[i]) + (y1 - y[i]) * (y1 - y[i])));
		}
	}
	
	cout << h / 2;
	
	return 0;
}