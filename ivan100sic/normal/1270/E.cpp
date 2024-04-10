#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int x[1005], y[1005], c[1005], n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x[i] >> y[i];
	}

	while (1) {
		for (int i=0; i<n; i++) {
			c[i] = x[i] + y[i];
		}
		int d[2] = {0, 0};
		for (int i=0; i<n; i++)
			d[c[i]&1]++;
		if (d[0] && d[1]) {
			cout << d[0] << '\n';
			for (int i=0; i<n; i++)
				if (c[i] % 2 == 0)
					cout << i+1 << ' ';
			cout << '\n';
			return 0;
		}

		if (d[0] == 0) {
			for (int i=0; i<n; i++)
				x[i]++;
		}

		for (int i=0; i<n; i++) {
			int u = x[i];
			int v = y[i];
			x[i] = (u+v) / 2;
			y[i] = (u-v) / 2;
		}
	}
}