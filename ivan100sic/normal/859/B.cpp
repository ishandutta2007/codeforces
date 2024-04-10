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

	int n, sol = 1e9;
	cin >> n;

	for (int i=1; i<=n; i++) {
		int q = n / i;
		int r = n % i;
		if (r == 0) {
			sol = min(sol, 2*(i+q));
		} else {
			sol = min(sol, 2*(i+q) + 2);
		}
	}

	cout << sol;
}