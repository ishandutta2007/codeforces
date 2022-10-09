#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	long long l, r, x, y, k;
	cin >> l >> r >> x >> y >> k;

	for (long long a=l; a<=r; a++) {
		if (a % k == 0) {
			long long b = a / k;
			if (x <= b && b <= y) {
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
}