#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count()
	+ reinterpret_cast<unsigned long>(new int) + *(new unsigned long));

ll mod1, mod2;

bool primeq(ll x) { // x large enough
	for (ll i=2; i*i<=x; i++)
		if (x % i == 0)
			return false;
	return true;
}

ll nextprime(ll x) {
	while(!primeq(x))
		x++;
	return x;
}

int n;
ll a[200005], k;
ll val1, val2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	mod1 = nextprime(uniform_int_distribution<ll>(2.1e9, 3e9)(eng));
	mod2 = nextprime(uniform_int_distribution<ll>(2.1e9, 3e9)(eng));

	cin >> n >> k;
	for (int i=0; i<=n; i++) {
		cin >> a[i];
	}

	for (int i=n; i>=0; i--) {
		val1 = (val1 * 2 + a[i] + mod1) % mod1;
		val2 = (val2 * 2 + a[i] + mod2) % mod2;
	}

	cerr << mod1 << ' ' << mod2 << '\n';
	cerr << val1 << ' ' << val2 << '\n';

	int z = 0;
	ll pow1 = 1;
	ll pow2 = 1; // 2^-i
	for (int i=0; i<=n; i++) {
		// int delta = -val / pow(2, i)
		ll delta1 = (mod1 - val1) * pow1 % mod1;
		ll delta2 = (mod2 - val2) * pow2 % mod2;

		// cerr << i << ' ' << pow1 << ' ' << pow2 << '\n';
		// cerr << i << ' ' << delta1 << ' ' << delta2 << '\n';

		if (delta1 == delta2) {
			// ok, delta je verodostojan
			if ((a[i] + delta1 != 0 || i < n) && abs(a[i] + delta1) <= k)
				z++;
		}

		delta1 -= mod1;
		delta2 -= mod2;

		// cerr << i << ' ' << delta1 << ' ' << delta2 << "\n\n";

		if (delta1 == delta2) {
			// ok, delta je verodostojan
			if ((a[i] + delta1 != 0 || i < n) && abs(a[i] + delta1) <= k)
				z++;
		}

		pow1 = pow1 * ((mod1 + 1) / 2) % mod1;
		pow2 = pow2 * ((mod2 + 1) / 2) % mod2;
	}

	cout << z << '\n';
}