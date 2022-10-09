#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q;
	cin >> q;
	while (q--) {
		int x, y = -1;
		cin >> x;
		if (x % 4 == 0) {
			y = x / 4;
		} else if (x % 4 == 1) {
			if (x >= 9) {
				y = x / 4 - 1;
			} else {
				y = -1;
			}
		} else if (x % 4 == 2) {
			if (x >= 6) {
				y = x / 4;
			} else {
				y = -1;
			}
		} else if (x % 4 == 3) {
			if (x <= 11) {
				y = -1;
			} else {
				y = x / 4 - 1;
			}
		}
		cout << y << '\n';
	}
}