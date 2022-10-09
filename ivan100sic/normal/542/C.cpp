#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int p[205], c[205];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> p[i];
	for (int i=1; i<=n; i++) {
		int x = i;
		for (int j=0; j<n; j++)
			x = p[x];
		c[x] = 1;
	}

	ll l = 1;
	for (int i=1; i<=n; i++) {
		if (c[i]) {
			int z = 1;
			for (int k=p[i]; k!=i; k=p[k])
				z++;
			l = lcm(l, z);
		}
	}

	ll h = 0;
	for (int i=1; i<=n; i++) {
		ll x = i, z = 0;
		while (!c[x])
			x = p[x], z++;
		h = max(h, z);
	}

	ll z = l;
	while (z < h)
		z += l;
	cout << z << '\n';
}