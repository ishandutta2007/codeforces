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

ll lcm(ll x, ll y) {
	return x*y/gcd(x, y);
}

ll n, m, l = 1;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (ll i=0; i<n; i++) {
		ll x;
		cin >> x;
		l = gcd(lcm(l, x), m);
	}

	cout << (m == l ? "Yes\n" : "No\n");
}