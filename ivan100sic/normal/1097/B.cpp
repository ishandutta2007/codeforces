#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[15];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	for (int mask=0; mask<(1<<n); mask++) {
		int z = 0;
		for (int i=0; i<n; i++) {
			if (mask & (1 << i)) {
				z += a[i];
			} else {
				z -= a[i];
			}
		}
		if (z % 360 == 0) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}