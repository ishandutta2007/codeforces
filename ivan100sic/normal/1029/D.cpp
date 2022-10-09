#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[200005];
map<int, int> rem[11];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;

	ll sol = 0;

	for (int i=1; i<=n; i++) {
		cin >> a[i];

		int t = a[i];
		int c = 0;
		while (t) {
			t /= 10;
			c++;
		}

		rem[c][a[i] % k]++;

		ll tmp = a[i];
		for (int j=0; j<c; j++) {
			tmp *= 10;
			tmp %= k;
		}
		tmp += a[i];
		if (tmp % k == 0)
			sol--;
	}

	for (int i=1; i<=n; i++) {

		// brojim za sve duzine
		ll a1 = a[i];
		for (int l=1; l<=10; l++) {
			a1 *= 10;
			a1 %= k;
			ll rc = (k - a1) % k;

			sol += rem[l][rc];
		}
	}

	cout << sol;
}