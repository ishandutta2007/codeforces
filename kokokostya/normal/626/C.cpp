#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int l = 1; int r = 100000000;
	while (l != r) {
		int k = (l + r) / 2;
		bool is = 1;
		if (3 * m <= k && 2 * n <= k &&(k / 3 + k / 2 - k / 6 >= n + m)) { is = 0; }
			if (is) { l = k + 1; }
			else { r = k; }
	}
	cout << l;
	return 0;
}