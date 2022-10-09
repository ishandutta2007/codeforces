#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005], b[200005], c[400005], z[400005], q[200005];
basic_string<int> e[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	for (int i=1; i<n; i++)
		e[gcd(i, n)] += i;

	ll sol = 0;

	for (int g=1; g<=n; g++) {
		if (n % g)
			continue;

		fill(b, b+g, 0);
		fill(c, c+2*n, 0);
		fill(z, z+2*n, 0);
		fill(q, q+n, 0);
		for (int j=0; j<n; j++)
			b[j%g] = max(b[j%g], a[j]);
		for (int j=0; j<n; j++)
			if (a[j] == b[j%g])
				c[j] = c[j+n] = 1;

		for (int j=2*n; j>=0; j--)
			z[j] = min(n, c[j] * (z[j+1] + 1));

		for (int i=0; i<n; i++)
			q[1]++, q[z[i]+1]--;

		for (int i=1; i<=n; i++) {
			q[i] += q[i-1];
		}

		for (int j : e[g])
			sol += q[j];
	}

	cout << sol << '\n';
}