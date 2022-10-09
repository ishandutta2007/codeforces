#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll n, m, a, b;

	cin >> n >> m >> a >> b;
	a--, b--;

	ll qfirst = a/m;
	ll qlast = b/m;
	ll rfirst = a%m;
	ll rlast = b%m;
	ll z;

	if (qfirst == qlast) {
		z = 1;
	} else {
		z = 1;
		if (rfirst > 0)
			z++;
		if (rlast < m-1 && b != n-1)
			z++;

		if (z == 3 && qfirst+1 == qlast)
			z = 2;

		if (z == 3 && rfirst == rlast+1)
			z = 2;
	}

	cout << z << '\n';
}