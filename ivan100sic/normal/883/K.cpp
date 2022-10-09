#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005], b[200005], c[200005], d[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i] >> b[i];
		a[i] += i;
		b[i] += a[i];
	}

	c[0] = b[0];
	for (int i=1; i<n; i++) {
		int z = min(c[i-1] + 2, b[i]);
		if (z < c[i-1]) {
			d[i] = z;
		}
		c[i] = z;
	}

	int l = 1e9;
	for (int i=n-1; i>=0; i--) {
		if (d[i])
			l = min(l, d[i]);
		c[i] = min(c[i], l);
		if (c[i] < a[i]) {
			cout << "-1\n";
			return 0;
		}
	}

	ll z = 0;

	for (int i=0; i<n; i++) {
		a[i] -= i;
		b[i] -= i;
		c[i] -= i;
		z += c[i] - a[i];
	}

	cout << z << '\n';
	for (int i=0; i<n; i++)
		cout << c[i] << " \n"[i == n-1];
}