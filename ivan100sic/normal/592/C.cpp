#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T>
T gcd(T a, T b) {
	T t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

void pf(ll x, ll y) {
	x--;
	ll g = gcd(x, y);
	x /= g;
	y /= g;
	cout << x << '/' << y << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll t, a, b, g;
	cin >> t >> a >> b;

	g = gcd(a, b);
	double lcmr = 1.0 * a * b / g;
	if (lcmr > 6e18) {
		pf(min({a, b, t+1}), t);
	} else {
		ll z = a * (b / g);
		ll y = min(a, b) * ((t+1) / z);
		pf(y + min({a, b, (t+1) % z}), t);
	}
}