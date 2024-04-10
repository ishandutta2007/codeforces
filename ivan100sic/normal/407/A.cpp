#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll koren(ll x) {
	ll l = 1, r = x, o = 0;
	while (l <= r) {
		ll m = (l+r) >> 1;
		if (m*m > x) {
			r = m-1;
		} else {
			o = m;
			l = m+1;
		}
	}
	return o;
}

bool kvq(ll x) {
	ll y = koren(x);
	return y*y == x;
}

basic_string<pair<ll, ll>> pita(ll a) {
	basic_string<pair<ll, ll>> v;
	for (ll i=1; i<a; i++) {
		ll j = a*a - i*i;
		if (kvq(j)) {
			v += {i, koren(j)};
			v += {i, -koren(j)};
			v += {-i, -koren(j)};
			v += {-i, koren(j)};
		}
	}
	return v;
}

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

bool orto(pair<ll, ll> a, pair<ll, ll> b) {
	return a.first * b.first + a.second * b.second == 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll a, b;
	cin >> a >> b;

	auto u = pita(a);
	auto v = pita(b);

	for (auto p : u) {
		for (auto q : v) {
			if (p.first != q.first && p.second != q.second &&
				orto(p, q)) {

				cout << "YES\n";
				cout << "0 0\n";
				cout << p.first << ' ' << p.second << '\n';
				cout << q.first << ' ' << q.second << '\n';
				return 0;
			}
		}
	}
	cout << "NO\n";
}