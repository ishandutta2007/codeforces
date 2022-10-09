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

	ll a[3];
	cin >> a[0] >> a[1] >> a[2];
	ll sol = 0;
	while (1) {
		ll xtra = 0;
		sort(a, a+3);
		// stepenice
		ll moves = min(a[2]-a[1], a[1]-a[0]);
		a[2] -= 2*moves;
		a[1] -= moves;
		xtra += moves;

		sort(a, a+3);
		if (a[1] == a[2]) {
			// blokce
			moves = (a[1]-a[0])/3;
			if ((a[1] - a[0]) % 3 == 2 && a[0] > 0)
				moves++;
			a[2] -= 3*moves;
			a[1] -= 3*moves;
			xtra += 2*moves;
		} else {
			// strci
			moves = min({a[2]/4, a[1], (a[2]-a[1])/3});
			a[2] -= 4*moves;
			a[1] -= moves;
			a[0] -= moves;
			xtra += 2*moves;
		}

		sol += xtra;
		if (xtra == 0)
			break;
	}

	cout << sol + min({a[0], a[1], a[2]}) << '\n';
}