// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, k;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> k;

	int s = 0;
	vector<ll> ol(k, -1e18);
	ol[0] = 0;

	for (int i=0; i<=n; i++) { // da, namerno
		vector<ll> nu(k, -1e18);
		int a=0, b=0;
		if (i < n) {
			cin >> a >> b;
		}
		for (int u=0; u<k; u++) {
			int v = (s + k - u) % k;
			// [u, v] = koliko smo nasledili za vertikalne

			// ne pravimo nista
			nu[(u + a) % k] = max(nu[(u + a) % k], ol[u] + (u+a)/k + (v+b)/k);

			// pravimo jednu horizontalu u odnosu [p, q]
			for (int p=0; p<=k && p<=a; p++) {
				int q = k-p;
				if (q > b)
					continue;

				int u2 = u + a - p;
				int v2 = v + b - q;
				ll e2 = 1 + ol[u] + u2 / k + v2 / k;
				u2 %= k;
				nu[u2] = max(nu[u2], e2);
			}
		}
		s = (s + a + b) % k;
		swap(ol, nu);
	}

	cout << *max_element(begin(ol), end(ol)) << '\n';

}