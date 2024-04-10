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

	ld a, b, m;
	cin >> a >> b >> m;
	ld vx, vy, vz;
	cin >> vx >> vy >> vz;

	ld t = -m / vy;

	ld x = a/2 + vx * t;
	ld z = 0 + vz * t;

	x = fmod(x, 2*a);
	if (x < 0)
		x += 2*a;
	if (x >= a)
		x = 2*a-x;

	z = fmod(z, 2*b);
	if (z < 0)
		z += 2*b;
	if (z >= b)
		z = 2*b-z;

	cout.precision(20);
	cout << fixed;

	cout << x << ' ' << z;
}