#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
string s[255];
int x[255];
ull f[255];
int c[255][26];

ull y[505];
int z[505];

bool ok(int x) {
	return x == (x & -x);
}

ll sol;

void manacher() {
	// pripremi
	const ull glup = 999999999999999999ull;
	const ull taraba = 4433443344334433ull;
	for (int i=0; i<n; i++) {
		y[2*i] = taraba;
		y[2*i+1] = ok(x[i]) ? f[i] : glup-i;
	}
	y[2*n] = taraba;

	fill(z, z+505, 0);
	int w = 2*n+1;

	z[0] = 0;
	for (int i=1, l=0, r=0; i<w; i++) {
		if (l <= i && i <= r)
			z[i] = min({z[r-i+l], r-i, i-l});
		else
			z[i] = 0;
		while (i + z[i] + 1 < w && i - z[i] - 1 >= 0 &&
			y[i + z[i] + 1] == y[i - z[i] - 1])
		{
			z[i]++;
		}
		if (i + z[i] > r) {
			r = i + z[i];
			l = i - z[i];
		}
	}

	// cerr << "dbg:\n";
	// for (int i=0; i<w; i++)
	// 	cerr << y[i] << ' ';
	// cerr << '\n';
	// for (int i=0; i<w; i++)
	// 	cerr << z[i] << ' ';
	// cerr << '\n';

	for (int i=1; i<w-1; i++) {
		if (y[i] > glup - 1231 && y[i] <= glup)
			continue;
		if (i % 2 == 0)
			sol += z[i] >> 1;
		else
			sol += (z[i] + 1) >> 1;
	}
}

ull hsh(ull x) {
	return (x << 31) ^ ((x * 234872349423781ull) << 15) ^
		(x << 7) ^ (x * 644818172813ull << 3);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> s[i];

	for (int j=0; j<m; j++) {
		memset(x, 0, sizeof(x));
		memset(c, 0, sizeof(c));
		memset(f, 0, sizeof(f));
		for (int k=j; k<m; k++) {
			for (int i=0; i<n; i++) {
				int l = s[i][k] - 'a';
				x[i] ^= 1 << l;
				c[i][l]++;
				f[i] += hsh(c[i][l] * 26 + l);
			}
			manacher();
			// cerr << j << ' ' << k << ' ' << sol << '\n';
		}
	}

	cout << sol << '\n';
}