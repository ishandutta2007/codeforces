#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int c[64];
int n;
ll a[100005];

int d[123][123];
bool b[123][123];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	{
		int t = 0;
		for (int i=0; i<n; i++) {
			ll x;
			cin >> x;
			if (x)
				a[t++] = x;
		}
		n = t;
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<60; j++) {
			if (a[i] & (1ll << j)) {
				c[j]++;
			}
			// cerr << ((a[i] >> j) & 1);
		}
		// cerr << '\n';
	}

	for (int i=0; i<60; i++) {
		if (c[i] >= 3) {
			cout << "3\n";
			return 0;
		}
	}

	// nema ih mnogo
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++) {
			b[i][j] = (a[i] & a[j]) && (i != j);
			d[i][j] = b[i][j] ? 1 : 123123123;
		}

	// Thank you Nikola5000
	int z = 123123123;
	for (int i=0; i<n; i++) {
		for (int j=0; j<i; j++)
			for (int k=0; k<j; k++)
				if (b[i][j] && b[i][k])
					z = min(z, d[j][k] + 2);

		for (int j=0; j<n; j++)
			for (int k=0; k<n; k++)
				d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
	}

	if (z == 123123123)
		z = -1;
	cout << z << '\n';
}