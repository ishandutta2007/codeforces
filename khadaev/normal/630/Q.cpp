#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif
const ld eps = 1e-8;

const ld X = sqrt(5 * (5 + 2 * sqrt(5)));
const ld s3 = sqrt(3) / 4, s4 = 1, s5 = X / 4;
const ld r3 = sqrt(3) / 6, r4 = 0.5, r5 = X / 10;

ld vol(ld len, const ld s, const ld r) {
	ld sq = len * len * s;
	ld rr = len * r;
	ld h = sqrt(0.75 * len * len - rr * rr);
	return h * sq / 3;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ld l3, l4, l5;
	cin >> l3 >> l4 >> l5;
	ld ans = vol(l3, s3, r3) + vol(l4, s4, r4) + vol(l5, s5, r5);
	cout << fixed << setprecision(10) << ans << '\n';
	return 0;
}