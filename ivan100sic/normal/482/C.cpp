#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
string a[55];
ll d[1 << 20];
ld e[1 << 20];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	m = a[0].size();
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			int x = 0;
			for (int k=0; k<m; k++) {
				x |= int(a[i][k] == a[j][k]) << k;
			}
			d[x] |= 1ll << i;
			d[x] |= 1ll << j;
		}
	}

	for (int j=1; j<(1<<m); j<<=1) {
		for (int i=(1<<m)-1; i>=0; i--) {
			if (i & j) {
				d[i-j] |= d[i];
			}
		}
	}

	for (int mask=(1<<m)-2; mask>=0; mask--) {
		int c = 0;
		ld t = 0;
		int u = __builtin_popcountll(d[mask]);
		for (int i=0; i<m; i++) {
			if (mask & (1 << i))
				continue;
			int mask2 = mask | (1 << i);
			c++;
			t += e[mask2] + ld(u)/n;
		}
		e[mask] = t/c;
	}

	for (int i=0; i<m; i++)
		cerr << i << ' ' << e[1 << i] << '\n';

	cout << setprecision(20) << fixed << e[0] << '\n';
}