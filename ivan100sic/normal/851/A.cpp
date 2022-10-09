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

	int n, k, t;
	cin >> n >> k >> t;
	if (t <= k) {
		cout << t;
	} else if (t >= n) {
		cout << n + k - t;
	} else {
		cout << k;
	}
}