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

	long long n, k, x;

	cin >> n >> k;

	vector<long long> divs;

	for (long long i=1; i*i <= n; i++) {
		if (i*i == n) {
			divs.push_back(i);
		} else {
			if (n % i == 0) {
				divs.push_back(i);
				divs.push_back(n/i);
			}
		}
	}

	sort(divs.begin(), divs.end());

	if (k > divs.size()) {
		x = -1;
	} else {
		x = divs[k-1];
	}

	cout << x;
}