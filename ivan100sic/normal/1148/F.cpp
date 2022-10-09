#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll val[300005], mask[300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	ll zbir = 0;
	for (int i=0; i<n; i++) {
		cin >> val[i] >> mask[i];
		zbir += val[i];
	}

	if (zbir < 0) {
		for (int i=0; i<n; i++)
			val[i] *= -1;
		zbir = -zbir;
	}

	ll sol = 0;
	for (int bit=0; bit<62; bit++) {
		ll w = 1ll << bit;
		ll ima = 0;
		for (int i=0; i<n; i++) {
			if ((mask[i] >> bit) == 1) {
				if (__builtin_parityll(mask[i] & sol))
					ima -= val[i];
				else
					ima += val[i];
			}
		}

		if (ima > 0) {
			sol |= w;
		}
	}

	cout << sol << '\n';
}