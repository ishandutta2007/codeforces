#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool f[1000005];
vector<int> prosti;

void sito() {
	for (int i=2; i<=1000; i++)
		if (!f[i])
			for (int j=i*i; j<=1000000; j+=i)
				f[j] = 1;
	for (int i=2; i<=1000000; i++)
		if (!f[i])
			prosti.push_back(i);
}

ll n, m, k;
ll a[10005], b[10005];
ll fc[22]; int l;

ll eea(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	ll x1, y1;
	ll g = eea(b, a%b, x1, y1);
	x = y1;
	y = x1 - y1*(a/b);
	return g;
}

ll inv(ll x, ll m) {
	ll r, t;
	eea(x, m, r, t);
	r %= m;
	if (r < 0)
		r += m;
	return r;
}

ll bigmod(ll x, ll y, ll m) {
	if (y == 0)
		return 0;
	ll z = bigmod(x, y >> 1, m);
	z <<= 1;
	z -= m*(z >= m);
	if (y & 1) {
		z += x;
		z -= m*(z >= m);
	}
	return z;
}

ll crt(ll m1, ll r1, ll m2, ll r2) {
	r1 = (r1%m1+m1)%m1;
	r2 = (r2%m2+m2)%m2;
	ll x, y;
	eea(m1, m2, x, y);
	ll m = m1*m2;
	ll z = 0;
	x = (x%m+m)%m;
	y = (y%m+m)%m;
	z += bigmod(bigmod(r1, m2, m), y, m);
	z += bigmod(bigmod(r2, m1, m), x, m);
	z -= m*(z >= m);
	z += m*(z < 0);
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	sito();
	cin >> n >> m >> k;
	for (int i=0; i<k; i++)
		cin >> a[i];

	ll w = 1;
	for (int i=0; i<k; i++) {
		ll g = gcd(a[i], w);
		if (1.0 * a[i] * w / g > 1e18) {
			cout << "NO\n";
			return 0;
		}
		w *= a[i] / g;
	}

	if (w > n) {
		cout << "NO\n";
		return 0;
	}

	for (ll t : prosti) {
		if (w % t == 0) {
			fc[l] = 1;
			while (w % t == 0) {
				w /= t;
				fc[l] *= t;
			}
			l++;
		}
	}

	if (w > 1) {
		fc[l++] = w;
	}

	ll rem = 0, mod = 1;
	for (int i=0; i<l; i++) {
		for (int j=0; j<k; j++) {
			if (a[j] % fc[i] == 0) {
				rem = crt(mod, rem, fc[i], -j);
				mod *= fc[i];
				break;
			}
		}
	}

	if (rem == 0)
		rem = mod;

	// (n == 942751266745ll ? cout : cerr) <<
	// 	"maybe it's " << mod << ' ' << rem << '\n';

	if (mod > n || rem + k - 1 > m) {
		cout << "NO\n";
		return 0;
	}

	for (int i=0; i<k; i++) {
		b[i] = gcd(mod, rem+i);
	}

	// if (n == 942751266745ll) {
	// 	for (int i=0; i<k; i++) {
	// 		if (a[i] != b[i]) {
	// 			cout << "diff " << i << ' ' << a[i] << ' ' << b[i] << '\n';
	// 		}
	// 	}
	// }

	cout << (equal(a, a+k, b) ? "YES\n" : "NO\n");
}