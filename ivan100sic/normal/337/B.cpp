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

	ll a, b, c, d;

	cin >> a >> b >> c >> d;

	ll x = a*d;
	ll y = b*c;
	ll g = gcd(x, y);
	x /= g;
	y /= g;
	if (x > y)
		swap(x, y);
	x = y-x;
	cout << x << '/' << y << '\n';
}