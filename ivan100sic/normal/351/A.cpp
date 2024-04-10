#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll a[4005], s;

bool moze(int z, int o, int j) {
	while (j > 0) {
		if (o > j) {
			o -= 2;
			j--;
		} else {
			if (!z || !o) return 0;
			z--;
			o--;
			j--;
		}
	}
	while (z || o) {
		if (!z) return 0;
		if (!o) return 1;
		z--;
		o--;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	n *= 2;
	for (int i=0; i<n; i++) {
		ld x;
		cin >> x;
		a[i] = ll(round(x * 1000)) % 1000;
	}

	s = accumulate(a, a+n, 0ll);

	int zero = count(a, a+n, 0ll);
	int one = n - zero;

	ll sol = 1e18;

	for (int j=0; j<4004; j++) {
		if (moze(zero, one, j)) {
			sol = min(sol, abs(j*1000ll-s));
		}
	}

	cout << setprecision(3) << fixed << sol/1000.0 << "\n";
}