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

int k, h, mx;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> k;
	for (int i=1; i<=k; i++) {
		int x;
		cin >> x;
		mx = max(mx, x);
	}

	int sol = mx - 25;

	if (sol < 0) {
		sol = 0;
	}

	cout << sol;

}