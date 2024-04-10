#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

double a[1 << 18], z;
int n, q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	cout.precision(20);
	cout << fixed;
	for (int i=0; i<(1<<n); i++) {
		cin >> a[i];
		z += a[i];
	}
	cout << z / (1 << n) << '\n';
	for (int i=0; i<q; i++) {
		int j;
		double x;
		cin >> j >> x;
		z += x - a[j];
		a[j] = x;
		cout << z / (1 << n) << '\n';
	}
}