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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll n, a, b, p, q;

	cin >> n >> a >> b >> p >> q;

	ll x = n / a;
	ll y = n / b;
	ll z = n / (a*b / gcd(a, b));

	x -= z;
	y -= z;

	cout << p*x + q*y + z*max(p, q);
}