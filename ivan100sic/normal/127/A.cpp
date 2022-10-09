#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef complex<double> cd;

int n, k;
cd a[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		double x, y;
		cin >> x >> y;
		a[i] = {x, y};
	}

	double sol = 0;

	for (int i=1; i<n; i++) {
		sol += abs(a[i] - a[i-1]);
	}

	cout.precision(20);
	cout << fixed;
	cout << sol / 50 * k << '\n';
}