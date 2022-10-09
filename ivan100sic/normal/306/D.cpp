#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef complex<ld> cd;

ld a[105];
const ld pi = acos(ld(-1));
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	if (n <= 4) {
		cout << "No solution\n";
		return 0;
	}

	for (int i=2; i<n; i++)
		a[i] = 450 + i * 0.012;

	cd sum = 0;
	for (int i=2; i<n; i++)
		sum += a[i] * exp(cd(0, 2*i*pi / n));

	a[1] = -sum.imag() / sin(2*pi / n);
	a[0] = -(a[1] * exp(cd(0, 2*pi / n)) + sum).real();

	for (int i=0; i<n; i++)
		cerr << i << ' ' << a[i] << '\n';

	cd s = 0;
	cout << setprecision(14) << fixed;
	for (int i=0; i<n; i++) {
		cout << s.real() << ' ' << s.imag() << '\n';
		s += a[i] * exp(cd(0, 2*i*pi / n));
	}
}