#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

const int INF = 1000000000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int lo = -INF;
	int hi = +INF;

	int n;
	cin >> n;
	while (n--) {
		int c, d;
		cin >> c >> d;

		if (d == 1) {
			lo = max(lo, 1900);
		} else {
			hi = min(hi, 1899);
		}

		lo += c;
		hi += c;
	}

	if (lo > hi) {
		cout << "Impossible";
	} else if (hi > INF/2) {
		cout << "Infinity";
	} else {
		cout << hi;
	}
}