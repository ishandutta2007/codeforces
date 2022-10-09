// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cout << setprecision(20) << fixed;

	int t;
	cin >> t;
	while (t--) {
		double d, c, i = 1;
		cin >> d >> c;
		double b = d - c;

		b = i / b;
		c = i / c;
		d = - i / d;

		// step 1
		b += c + d;

		double cpd = c + d;
		double cpd4 = cpd * 4;
		double ctd4 = c * d * 4;

		int k;
		cin >> k;
		while (--k) {
			b = b + cpd + sqrt(b*cpd4 + ctd4);
		}

		cout << i / b << '\n';
	}
}