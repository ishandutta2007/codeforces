// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll n, d, m;
ll a[100005];
ll z[100005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> d >> m;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	sort(a, a+n);

	for (int i=0; i<n; i++) {
		z[i+1] = z[i] + a[i];
	}

	ll p = count_if(a, a+n, [&](int x) { return x > m; });

	ll sol = 0;
	for (ll c=1; c<=p; c++) {
		// tacno c puta cemo da uzmemo velikog
		for (ll r=0; r<=d; r++) {
			// jos koliko ubacujemo na kraj = r

			// days = koliko dana smo "pokrili"
			ll days = (c-1) * (d+1) + 1 + r;

			// moramo da pokrijemo sve velike
			if (days < p) {
				continue;
			}

			// previse pokrivamo dana?
			if (days > n) {
				break;
			}

			// koliko malih moramo da pokrijemo?
			ll ml = days - p;

			sol = max(sol, z[n-p] - z[ml] + z[n] - z[n-c]);
		}
	}

	// mozemo da uzmemo sve?
	if (p <= 1) {
		sol = max(sol, z[n]);
	}

	cout << sol << '\n';
}