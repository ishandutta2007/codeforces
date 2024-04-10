// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

typedef complex<ld> cd;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	ld px, py, vx, vy, a, b, c, d;
	cin >> px >> py >> vx >> vy >> a >> b >> c >> d;

	cd p[8];
	p[0] = cd(0, b);
	p[1] = cd(-a/2, 0);
	p[2] = cd(-c/2, 0);
	p[3] = cd(-c/2, -d);
	for (int i=4; i<7; i++)
		p[i] = cd(-p[7-i].real(), p[7-i].imag());
	cout << setprecision(20) << fixed;
	for (int i=0; i<7; i++) {
		cd t = p[i] * cd(0, -1) * cd(vx, vy) / sqrt(vx*vx + vy*vy) + cd(px, py);
		cout << t.real() << ' ' << t.imag() << '\n';
	}

}