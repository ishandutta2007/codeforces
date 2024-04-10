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

	int a[12], k;

	cin >> k;
	for (int i=0; i<12; i++) {
		cin >> a[i];
	}

	int sol = 13;

	for (int mask=0; mask<(1<<12); mask++) {
		int c = 0, x = 0;
		for (int i=0; i<12; i++) {
			if (mask & (1<<i)) {
				c++;
				x += a[i];
			}
		}
		if (x >= k) {
			sol = min(sol, c);
		}
	}

	if (sol == 13) sol = -1;

	cout << sol;
}