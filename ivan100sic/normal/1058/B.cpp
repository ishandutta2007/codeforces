#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, d, x, y, q, c;

int main() {
	cin >> n >> d >> q;
	while (q--) {
		cin >> x >> y;
		int ok = 1;
		if (x + y < d)
			ok = 0;
		if (x + y > 2 * n - d)
			ok = 0;
		if (x - y < -d)
			ok = 0;
		if (x - y > d)
			ok = 0;
		cout << (ok ? "YES\n" : "NO\n");
	}
	cin >> c;
}