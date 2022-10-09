// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll n, k;
ll a[100005];
ll d[100005];
ll z[100005];
ll prefmin[100005];
ll suffmina[100005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for (int i=1; i<=n; i++) {
		cin >> d[i];
	}
	z[n] = a[n];
	for (int i=n-1; i>=1; i--) {
		z[i] = z[i+1] + a[i];
	}

	ll sol = 0;
	if (k == 0) {
		for (int i=1; i<=n; i++) {
			sol = max(sol, z[i] - d[i]);
		}
	} else if (k >= 2) {
		for (int i=1; i<n; i++) {
			sol = max(sol, z[1] - d[i]);
		}
		sol = max(sol, a[n] - d[n]);
	} else {
		prefmin[1] = d[1];
		for (int i=2; i<=n; i++) {
			prefmin[i] = min(prefmin[i-1], d[i]);
		}

		suffmina[n-1] = a[n-1];
		for (int i=n-2; i>=1; i--) {
			suffmina[i] = min(suffmina[i+1], a[i]);
		}

		sol = max(sol, a[n] - d[n]);
		for (int i=1; i<n; i++) {
			sol = max(sol, z[1] - a[n] - d[i] + max(0ll, a[n] - d[n]));
		}

		// bas hocu da uhvatim n sa necim drugim
		for (int i=2; i<n; i++) {
			ll v = z[i] - d[i];
			// eventualno dodaj prefiks?
			v += max(0ll, z[1] - z[i] - prefmin[i-1]);
			sol = max(sol, v);
		}

		// preskoci nekog posle
		// tesko da bih se setio ovoga
		for (int i=1; i<n-1; i++) {
			sol = max(sol, z[i] - d[i] - suffmina[i+1]);
		}
	}

	cout << sol << '\n';
}