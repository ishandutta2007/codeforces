#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, r = 1e9, as, bs;
	cin >> n;

	for (int a=1; a<=n; a++) {
		int b = n / a;
		if (n % a) {
			continue;
		}
		if (a > b) {
			continue;
		}
		if (b - a < r) {
			r = b-a;
			as = a;
			bs = b;
		}
	}

	cout << as << ' ' << bs;

}