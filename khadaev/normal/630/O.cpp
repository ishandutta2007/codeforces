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
	ios::sync_with_stdio(false);
	cin.tie(0);
	ld px, py, vx, vy, a, b, c, d;
	cin >> px >> py >> vx >> vy >> a >> b >> c >> d;
	ld norm = sqrt(vx * vx + vy * vy);
	vx /= norm;
	vy /= norm;
	cout << fixed << setprecision(10) <<
		px + vx * b << ' ' << 
		py + vy * b << '\n' <<

		px - vy * a / 2 << ' ' << 
		py + vx * a / 2 << '\n' <<

		px - vy * c / 2 << ' ' << 
		py + vx * c / 2 << '\n' <<

		px - vy * c / 2 - vx * d << ' ' <<
		py + vx * c / 2 - vy * d << '\n' <<

		px + vy * c / 2 - vx * d << ' ' <<
		py - vx * c / 2 - vy * d << '\n' <<

		px + vy * c / 2 << ' ' << 
		py - vx * c / 2 << '\n' <<

		px + vy * a / 2 << ' ' << 
		py - vx * a / 2 << '\n';



	return 0;
}