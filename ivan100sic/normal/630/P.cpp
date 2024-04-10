// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

typedef complex<ld> cd;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n, r;
	cin >> n >> r;

	const ld pi = acos(ld(-1));
	cd d = exp(cd(0, pi / n));
	cd g = -d*d;
	ld h = (d.real() * g.imag() - d.imag() * g.real()) / (g.imag() - d.imag());
	ld a = h * d.imag();
	cout << setprecision(20) << fixed << a*n*r*r << '\n';
}