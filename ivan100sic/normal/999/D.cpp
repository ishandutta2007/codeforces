#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long a[200005];
long long c[200005];

long long povecaj[200005];

long long z[200005];
long long k[200005], k2[200005];
long long prefix[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (long long i=1; i<=n; i++)
		cin >> a[i];

	long long sol = 0;

	for (long long rep=0; rep<2; rep++) {
		fill(c, c+m+1, 0);
		fill(povecaj, povecaj+m+1, 0);
		fill(prefix, prefix+n+2, 0);

		for (long long i=1; i<=n; i++) {
			c[a[i] % m]++;
		}

		k[0] = 0;
		for (long long i=1; i<=m; i++)
			k[i] = k[i-1] + c[i-1];

		for (long long i=1; i<=n; i++) {
			long long r = a[i] % m;
			z[k[r]++] = i;
		}

		long long nm = n/m;

		for (long long i=0; i<m; i++) {
			long long d = c[i] - nm;
			if (d < 0)
				continue;
			povecaj[i] += d;
			sol += d;
			c[i] -= d;
			c[(i+1) % m] += d;
		}

		for (long long i=0; i<m; i++) {
			long long p = povecaj[i];
			prefix[k[i] - p]++;
			prefix[k[i]]--;
			k[i] -= p;
		}

		for (long long i=0; i<n; i++) {
			prefix[i+1] += prefix[i];
		}

		for (long long i=0; i<n; i++) {
			a[z[i]] += prefix[i];
		}
	}

	cout << sol << '\n';

	for (long long i=1; i<=n; i++)
		cout << a[i] << ' ';	

}