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
		int x;
		cin >> x;

		if (x == 0) {
			cout << "Y 0 0\n";
			continue;
		}

		if (x == 4) {
			cout << "Y 2 2\n";
			continue;
		}

		if (x < 4) {
			cout << "N\n";
			continue;
		}

		ld d = x;

		ld a = d/2-sqrt(d*d-4*d)/2;
		ld b = d - a;

		cout.precision(20);
		cout << fixed;
		cout << "Y " << a << ' ' << b << '\n';
	}
}