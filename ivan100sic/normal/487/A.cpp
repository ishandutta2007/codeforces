#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int hpy, ay, dy;
int hpm, am, dm;
int h, a, d;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> hpy >> ay >> dy;
	cin >> hpm >> am >> dm;
	cin >> h >> a >> d;

	int sol = 1123123123;

	for (int j=0; j<=10000; j++) {
		for (int k=0; k<=10000; k++) {

			if (a*j + d*k > sol)
				break;

			int ly = max(0, am - (dy + k));
			int lm = max(0, (ay + j) - dm);

			if (ly == 0 && lm == 0) {
				continue;
			} else if (ly == 0) {
				sol = min(sol, a*j + d*k);
			} else if (lm == 0) {
				continue;
			} else {
				int turns = (hpm + lm - 1) / lm;
				int z = turns * ly - hpy + 1;
				z = max(z, 0);
				sol = min(sol, a*j + d*k + z*h);
			}
		}
	}

	cout << sol << '\n';
}