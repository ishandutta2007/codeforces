#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int a, b;
	cin >> a >> b;
	int x = 0, y = 1;

	while (1) {
		if (x == 0) {
			a -= y;
			y++;
			if (a < 0) {
				cout << "Vladik\n";
				return 0;
			}
			x = 1;
		} else {
			b -= y;
			y++;
			x = 0;
			if (b < 0) {
				cout << "Valera\n";
				return 0;
			}
		}
	}
}