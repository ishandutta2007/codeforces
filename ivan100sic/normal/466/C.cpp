#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll a[500005], z[500005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		z[i+1] = z[i] + a[i];
	}
	if (z[n] % 3) {
		cout << "0\n";
		return 0;
	}
	ll c = 0, d = 0;
	for (int i=1; i<n; i++) {
		if (z[i] == z[n] / 3 * 2)
			d += c;
		if (z[i] == z[n] / 3)
			c++;
	}
	cout << d << "\n";
}