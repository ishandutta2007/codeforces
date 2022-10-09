#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll a, b, c;
	cin >> a >> b >> c;

	cout.precision(20);

	if (a != 0) { 
		ll d = b*b - 4*a*c;

		if (d < 0) {
			cout << "0\n";
			return 0;
		} else if (d == 0) {
			cout << "1\n";
			cout << fixed << b * -0.5 / a;
		} else {
			cout << "2\n";
			double r = sqrt(d);
			if (a < 0) {
				cout << fixed << (-b + r) / (2*a) << '\n';
				cout << fixed << (-b - r) / (2*a) << '\n';
			} else {
				cout << fixed << (-b - r) / (2*a) << '\n';
				cout << fixed << (-b + r) / (2*a) << '\n';
			}
			
		}
	} else {
		if (b == 0) {
			if (c == 0) {
				cout << "-1\n";
			} else {
				cout << "0\n";
			}
		} else {
			cout << "1\n";
			cout << fixed << -c *1.0 / b;
		}
	}
}