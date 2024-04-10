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

	int k, a, b;
	cin >> k >> a >> b;

	int x = a/k;
	int u = a%k;

	int y = b/k;
	int v = b%k;

	if (x > 0 && y > 0) {
		cout << x + y;
	} else if (y == 0 && x > 0) {
		if (u == 0) {
			cout << x;
		} else {
			cout << -1;
		}
	} else if (x == 0 && y > 0) {
		if (v == 0) {
			cout << y;
		} else {
			cout << -1;
		}
	} else {
		cout << -1;
	}

}