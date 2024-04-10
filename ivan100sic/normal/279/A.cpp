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

	int x, y;
	cin >> x >> y;

	if (x == 0 && y == 0) {
		cout << "0\n";
		return 0;
	}

	if (x == 1 && y == 0) {
		cout << "0\n";
		return 0;
	}

	if (y == 1 && x == 1) {
		cout << "1\n";
		return 0;
	}

	if (y == 1 && -1 <= x && x <= 0) {
		cout << "2\n";
		return 0;
	}

	if (x == -1 && -1 <= y && y <= 1) {
		cout << "3\n";
		return 0;
	}

	if (y == -1 && -1 <= x && x <= 2) {
		cout << "4\n";
		return 0;
	}

	int z = max(abs(x), abs(y));

	if (x == z && y == -z + 1) {
		cout << 4*z - 4 << '\n';
		return 0;
	}

	if (x == z && y != -z) {
		cout << 4*z - 3 << '\n';
		return 0;
	}

	if (y == z) {
		cout << 4*z - 2 << '\n';
		return 0;
	}

	if (x == -z) {
		cout << 4*z - 1 << '\n';
		return 0;
	}

	cout << 4*z + 0 << '\n';
}