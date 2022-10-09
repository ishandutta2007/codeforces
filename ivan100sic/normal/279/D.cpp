#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[23], d[1 << 23];

void mn(int& x, int y) {
	x = min(x, max(__builtin_popcount(&x-d), y));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	memset(d, 63, sizeof d);
	d[1] = 1;
	for (int i=1; i<n; i++) {
		for (int j=0; j<i; j++) {
			for (int k=j; k<i; k++) {
				if (a[j] + a[k] == a[i]) {
					for (int mask=(1 << (i-1)); mask<(1<<i); mask++) {
						if (mask & (1 << j) && (mask & (1 << k))) {
							mn(d[mask | (1 << i)], d[mask]);
							for (int l=0; l<i; l++)
								if (mask & (1 << l))
									mn(d[(mask | (1 << i)) - (1 << l)], d[mask]);
						}
					}
				}
			}
		}
	}

	int sol = 123;
	for (int mask=(1<<(n-1)); mask<(1<<n); mask++)
		sol = min(sol, d[mask]);
	if (sol == 123)
		sol = -1;
	cout << sol << '\n';
}