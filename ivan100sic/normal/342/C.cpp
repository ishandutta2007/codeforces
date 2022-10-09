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

	ll r, h;
	cin >> r >> h;
	ll sol = 0;
	while (h >= 2*r) {
		h -= r;
		sol += 2;
	}

	if (h > r && (h-r)*(h-r)*4 >= r*r*3) {
		sol += 5;
	} else if (2*h >= 3*r) {
		sol += 4;
	} else if (h*h*4 >= r*r*3) {
		sol += 3;
	} else if (2*h >= r) {
		sol += 2;
	} else {
		sol += 1;
	}

	cout << sol << '\n';

}