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

	int t;
	cin >> t;
	while (t--) {
		ll n, x, y, d;
		cin >> n >> x >> y >> d;

		ll sol = 123123123123123123ll;

		if (abs(x-y) % d == 0) {
			sol = min(sol, abs(x-y) / d);
		}

		if (abs(1-y) % d == 0) {
			sol = min(sol, abs(1-y) / d + (abs(x-1)+d-1) / d);
		}

		if (abs(n-y) % d == 0) {
			sol = min(sol, abs(n-y) / d + (abs(x-n)+d-1) / d);
		}
		
		if (sol == 123123123123123123ll)
			sol = -1;

		cout << sol << '\n';
	}
}