#include <iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	ll t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

int main() {

	ll n, m, k;
	cin >> n >> m >> k;

	if (2*n*m % k) {
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";

	ll g = gcd(2*n, k);
	ll x = 2*n / g;
	ll y = 2*n*m / x / k;

	if (x > n) {
		x /= 2;
		y *= 2;
	}

	cout << "0 0\n0 " << y << '\n' << x << ' ' << y << '\n';
}