#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int m;

struct mat {
	int a[2][2];

	mat() {
		a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0;
	}

	int* operator[] (int x) {
		return a[x];
	}
};

mat mul(mat a, mat b) {
	mat c;
	for (int i=0; i<2; i++)
		for (int j=0; j<2; j++)
			for (int k=0; k<2; k++)
				c[i][k] = (c[i][k] + a[i][j] * 1ll * b[j][k]) % m;
	return c;
}

mat id() {
	mat c;
	c[0][0] = c[1][1] = 1;
	return c;
}

mat fib() {
	mat c;
	c[0][0] = c[0][1] = c[1][0] = 1;
	return c;
}

mat pw(mat a, ll k) {
	if (k == 0)
		return id();
	if (k == 1)
		return a;
	mat b = pw(a, k >> 1);
	b = mul(b, b);
	if (k & 1) {
		b = mul(b, a);
	}
	return b;
}

int pw(int a, ll k) {
	if (k == 0)
		return 1 % m;
	if (k == 1)
		return a % m;
	int b = pw(a, k >> 1);
	b = b * 1ll * b % m;
	if (k & 1) {
		b = b * 1ll * a % m;
	}
	return b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll n, k;
	int l;
	cin >> n >> k >> l >> m;

	int f = pw(fib(), n+1)[0][0] % m;
	int p2 = pw(2, n) % m;
	int g = p2 - f;
	if (g < 0)
		g += m;

	cerr << f << ' ' << g << '\n';

	int z = 1;
	for (int i=0; i<l; i++) {
		ll bit = k & 1;
		k >>= 1;

		if (bit == 0) {
			z = z * 1ll * f % m;
		} else {
			z = z * 1ll * g % m;
		}
	}

	if (k)
		z = 0;

	cout << z % m << '\n';
}