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

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int m = 0;
	while (a+b > 0 && c+d > 0) {
		if (m == 0) {
			if (a > 0 && b > 0) {
				if (c == a-1 && d == b) {
					b--;
				} else if (c == a && d == b-1) {
					a--;
				} else {
					if (c-a < d-b) { // boze pomozi xd
						a--;
					} else {
						b--;
					}
				}
			} else if (a > 0 && b == 0) {
				if (c == a-1 && d == b) {

				} else {
					a--;
				}
			} else if (a == 0 && b > 0) {
				if (c == a && d == b-1) {

				} else {
					b--;
				}
			}
		} else {
			swap(a, c);
			swap(b, d);

			if (a > 0 && b > 0) {
				if (c == a-1 && d == b-1) {
					if (a > b) { // ovde?
						a--;
					} else {
						b--;
					}
				} else {
					a--, b--;
				}
			} else if (a > 0) {
				if (c == a-1 && d == b) {

				} else {
					a--;
				}
			} else if (b > 0) {
				if (c == a && d == b-1) {

				} else {
					b--;
				}
			}

			swap(a, c);
			swap(b, d);
		}

		m ^= 1;

		// cerr << a << ' ' << b << " :: " << c << ' ' << d << '\n';
	}

	if (a+b == 0)
		cout << "Polycarp\n";
	else
		cout << "Vasiliy\n";
}