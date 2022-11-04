#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

const ll M = 1e17;

void ProGamerMove() {
	ll a, b, c; cin >> a >> b >> c;
	ll x = (M - a) / b * b + a;
	ll y = b;
	ll z = c;
	assert(x % y == a);
	assert(y % z == b);
	assert(z % x == c);
	cout << x << ' ' << y << ' ' << z << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}