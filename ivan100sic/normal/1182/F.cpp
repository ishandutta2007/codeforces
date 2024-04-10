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

template<class T>
T eea(T a, T b, T& x, T& y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}

	T x1, y1;
	T g = eea(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return g;
}

ll inverse(ll n, ll mod) {
	ll x, y;
	eea(n, mod, x, y);
	x %= mod;
	if (x < 0)
		x += mod;
	return x;
}

// resi ax = b (mod m)
pair<ll, ll> slinrek(ll a, ll b, ll m) {
	b = (b % m + m) % m;

	ll g = gcd(a, m);
	if (b % g)
		return {-1, -1};
	a /= g;
	b /= g;
	m /= g;

	if (a == 0) {
		if (b != 0) {
			return {-1, -1};
		} else {
			return {0, 1};
		}
	}

	// x = b/a (mod m)
	return {inverse(a, m) * b % m, m};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		ll a, b, p, q;
		cin >> a >> b >> p >> q;
		p %= q;

		{
			ll g = gcd(p, q);
			p /= g;
			q /= g;
		}

		ll value = -1, opt = -1;

		auto enlist = [&](ll x) {
			ll y = p*x % q;
			ll v = min(y, q-y);
			if (v > value) {
				value = v;
				opt = x;
			} else if (v == value && x < opt) {
				opt = x;
			}
		};

		enlist(a);
		enlist(b);

		bool enlisted = false;

		auto ciljaj = [&](ll tgt) {
			auto [base, step] = slinrek(p, tgt, q);
			if (base == -1)
				return;

			if (base > a) {
				base -= (base-a) / step * step;
			}

			if (base < a) {
				base += (a-base) / step * step;
			}

			if (base < a)
				base += step;

			if (a <= base && base <= b) {
				enlist(base);
				enlisted = true;
			}
		};

		for (int dev=0; dev<=min(q/2+2, 10000ll); dev++) {
			ciljaj(q/2 - dev);
			ciljaj(q/2+1 + dev);
			if (enlisted)
				break;
		}

		for (int i=a; i<=min(b, a+300000); i++)
			enlist(i);

		for (int i=b; i>=max(a, b-300000); i--)
			enlist(i);

		cout << opt << '\n';
	}
}