#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll a[500005], b[500005], g[64];

void dodaj(ll x) {
	for (int i=0; i<62; i++) {
		if (x & (1ll << i)) {
			if (g[i] == 0) {
				g[i] = x;
				break;
			} else {
				x ^= g[i];
			}
		}
	}
}

int gsize() {
	int z = 0;
	for (int i=0; i<62; i++)
		if (g[i])
			z++;
	return z;
}

bool moze(ll x) {
	for (int i=0; i<62; i++) {
		if (x & (1ll << i)) {
			if (g[i]) {
				x ^= g[i];
			}
		}
	}
	return x == 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	ll ax = 0;
	for (int i=0; i<n; i++) {
		cin >> a[i] >> b[i];
		ax ^= a[i];
		dodaj(b[i] ^ a[i]);
	}

	if (moze(ax)) {
		ll t = 1ll << gsize();
		cout << t-1 << "/" << t << '\n';
	} else {
		cout << "1/1\n";
	}
}