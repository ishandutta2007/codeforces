#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int f[1000005];
int d[1000005];
string s;

int p[20][1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> s;
	f[0] = -1;
	f[1] = 0;
	d[1] = 1;
	for (int i=2; i<=n; i++) {
		int z = f[i-1];
		while (z >= 0 && s[z] != s[i-1])
			z = f[z];
		f[i] = z+1;
		d[i] = d[f[i]] + 1;
	}

	for (int i=1; i<=n; i++)
		p[0][i] = f[i];

	for (int i=1; i<20; i++)
		for (int j=1; j<=n; j++)
			p[i][j] = p[i-1][p[i-1][j]];

	for (int i=1; i<=n; i++) {
		int ok = 0;
		int z = i;
		for (int j=19; j>=0; j--) {
			int y = p[j][z];
			if (i > (i-y)*(k+1ll))
				z = y;
		}
		z = f[z];
		if ((ll)k*(i-z) <= i && i <= (k+1ll)*(i-z))
			ok = 1;
		cout << ok;
	}
	cout << '\n';
}