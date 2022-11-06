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


int main() {
	ld a, b, c;
	cin >> a >> b >> c;
	if (a < 0) {
		a *= -1;
		b *= -1;
		c *= -1;
	}
	ld d = b * b  - 4 * a * c;
	cout << fixed << setprecision(10) << (- b + sqrt(d)) / (2 * a) << '\n';
	cout << fixed << setprecision(10) << (- b - sqrt(d)) / (2 * a) << '\n';
}