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

	int n, k;
	cin >> n >> k;
	vector<int> a(n+1);
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	int c = 0;

	for (int i=1; i<=n; i++) {
		c += a[i];
		int dif = min(min(8, k), c);
		k -= dif;
		c -= dif;
		if (k == 0) {
			cout << i;
			return 0;
		}
	}

	cout << -1;
}