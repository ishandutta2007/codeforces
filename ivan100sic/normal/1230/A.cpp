#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int a[4], z=0;
	for (int i=0; i<4; i++)
		cin >> a[i], z += a[i];
	for (int mask=0; mask<16; mask++) {
		int u = 0;
		for (int i=0; i<4; i++)
			if (mask & (1 << i))
				u += a[i];
		if (2*u == z) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}