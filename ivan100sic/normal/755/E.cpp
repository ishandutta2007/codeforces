#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k;
	cin >> n >> k;

	if (k == 1) {
		cout << -1;
		return 0;
	}

	if (k == 2) {
		if (n <= 4) {
			cout << -1;
			return 0;
		}
		cout << n-1 << '\n';
		for (int i=2; i<=n; i++) {
			cout << (i-1) << ' ' << i << '\n';
		}
		return 0;
	}

	if (k > 3) {
		cout << -1;
		return 0;
	}

	if (n <= 3) {
		cout << -1;
		return 0;
	}

	if (n == 4) {
		cout << "3\n1 2\n2 3\n3 4\n";
		return 0;
	}

	if (n >= 5) {
		int p = 1;
		int q = n / 2 + 1;

		cout << (q-1)*(n-q+1)-1 << '\n';

		for (int i=1; i<q; i++) {
			for (int j=q; j<=n; j++) {
				if (i == p && j == q) {
					continue;
				}
				cout << i << ' ' << j << '\n';
			}
		}
		return 0;
	}
}