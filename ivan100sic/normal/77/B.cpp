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

	cout.precision(20);
	cout << fixed;

	int t;
	cin >> t;
	while (t--) {
		ld a, b, sol;
		cin >> a >> b;

		if (abs(a) < 0.1 && abs(b) < 0.1) {
			sol = 1;
		} else if (abs(a) < 0.1) {
			sol = 0.5;
		} else if (abs(b) < 0.1) {
			sol = 1;
		} else if (a <= 4*b) {
			sol = 0.5 + a/b/16;
		} else {
			sol = 1 - b/a;
		}
		cout << sol << '\n';
	}
}