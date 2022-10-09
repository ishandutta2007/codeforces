#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef complex<ld> cd;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int m, n;
	cin >> m >> n;
	if (n == 3) {
		if (m == 3) {
			cout << "0 0\n3 0\n0 3\n";
		} else if (m == 4) {
			cout << "0 0\n3 0\n0 3\n1 1\n";
		} else {
			cout << "-1\n";
		}
	} else {
		cd w = exp(cd(0, 2) * cd(3.14159265358979) / cd(n));
		cd wh = exp(cd(0, 0.0001));

		ld scale = 0.999;

		cd z = 99999991;
		for (int i=0; i<n; i++) {
			cout << (int)z.real() << ' ' << (int)z.imag() << '\n';
			z *= w;
		}

		z = 99999991 * scale * wh;
		for (int i=0; i<m-n; i++) {
			cout << (int)z.real() << ' ' << (int)z.imag() << '\n';
			z *= w;
		}
	}
}