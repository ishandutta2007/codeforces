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

	int n, m;
	cin >> m >> n;

	ld e = 0;
	for (int x=1; x<=m; x++) {
		ld f = pow((ld)x/m, n) - pow((ld)(x-1)/m, n);
		if (isnan(f))
			f = 0;
		e += f*x;
	}

	cout.precision(20);
	cout << fixed << e << '\n';
}