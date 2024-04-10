#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int x[3], y[3], xx[3], yy[3];
char c[3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<3; i++)
		cin >> x[i] >> y[i];

	int p[3] = {0, 1, 2};
	for (int _r=0; _r<6; _r++) {
		for (int smask=0; smask<8; smask++) {

			for (int i=0; i<3; i++) {
				xx[i] = x[p[i]];
				yy[i] = y[p[i]];
				c[i] = "ABC"[p[i]];
				if (smask & (1 << i))
					swap(xx[i], yy[i]);
			}

			if (yy[0] == yy[1] && yy[1] == yy[2] && yy[0] == xx[0] + xx[1] + xx[2]) {
				// stripes
				cout << yy[0] << '\n';
				for (int i=0; i<xx[0]; i++) cout << string(yy[0], c[0]) << '\n';
				for (int i=0; i<xx[1]; i++) cout << string(yy[1], c[1]) << '\n';;
				for (int i=0; i<xx[2]; i++) cout << string(yy[2], c[2]) << '\n';;

				return 0;
			}

			if (yy[0] == yy[1] + yy[2] && xx[1] == xx[2] && yy[0] == xx[0] + xx[1]) {
				// cool
				cout << yy[0] << '\n';
				for (int i=0; i<xx[0]; i++) cout << string(yy[0], c[0]) << '\n';;
				for (int i=0; i<xx[1]; i++)
					cout << string(yy[1], c[1]) << string(yy[2], c[2]) << '\n';;
				return 0;
			}
		}

		next_permutation(p, p+3);
	}

	cout << "-1\n";
}