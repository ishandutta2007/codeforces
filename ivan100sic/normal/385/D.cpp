#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef complex<double> cd;
const ld pi = acos(ld(-1));

int x[22], y[22], a[22];
int n, l, r;

ld d[1 << 20];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> l >> r;
	for (int i=0; i<n; i++) {
		cin >> x[i] >> y[i] >> a[i];
	}

	for (int mask=0; mask<(1<<n); mask++) {
		d[mask] = l;
	}

	for (int mask=0; mask<(1<<n); mask++) {
		for (int i=0; i<n; i++) {
			if (mask & (1 << i))
				continue;
			cd z(x[i], y[i]);
			cd q(d[mask], 0);

			cd qr = z + (q-z) * exp(cd(0, a[i] * pi / 180));
			ld reach;

			if (qr.imag() >= z.imag()) {
				reach = r;
			} else {
				cd proj = z + (qr-z) / (z-qr).imag() * cd(y[i]);
				reach = proj.real();
			}

			reach = min(reach, ld(r));
			d[mask | (1 << i)] = max(d[mask | (1 << i)], reach);
		}
	}

	cout << setprecision(20) << fixed << d[(1 << n) - 1] - l << '\n';
}