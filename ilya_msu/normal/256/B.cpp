#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:64000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
 
using namespace std; 
 
typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-8;
const int INF = 1000 * 1000 + 10;

ll n, x, y, c;

ll f(ll m) {
	ll res = (ll)(2) * m * m + (ll)(2) * m + 1;
	ll x1 = max(ll(0), m - (x - 1));
	ll y1 = max(ll(0), m - (y - 1)); 
	ll x2 = max(ll(0), m - (n - x)); 
	ll y2 = max(ll(0), m - (n - y)); 
	res -= x1 * x1;
	res -= x2 * x2;
	res -= y1 * y1;
	res -= y2 * y2;
	ll d1 = (n + 1) * 2 - x - y;
	ll d2 = n + 1 - x + y;
	ll d3 = n + 1 - y + x;
	ll d4 = x + y;
	ll a1 = max(m + 1 - d1, (ll)(0));
	ll a2 = max(m + 1 - d2, (ll)(0));
	ll a3 = max(m + 1 - d3, (ll)(0));
	ll a4 = max(m + 1 - d4, (ll)(0));
	res += a1 * (a1 + 1) / 2;
	res += a2 * (a2 + 1) / 2;
	res += a3 * (a3 + 1) / 2;
	res += a4 * (a4 + 1) / 2;
	return res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> x >> y >> c;
	if (c < 2) {
		cout << 0 << endl;
		return 0;
	}
	

	ll down = 0;
	ll up = 2 * n;
	while (up - down > 1) {
		ll m = down + (up - down) / 2;
		ll x = f(m);
		if (x >= c)
			up = m;
		else
			down = m;
	}
	cout << up << endl;	
	return 0;
}