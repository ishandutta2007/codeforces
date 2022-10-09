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

	long long n, k;
	cin >> n >> k;
	// minimum:
	if (k == 0 || k == n) {
		cout << "0 ";
	} else {
		cout << "1 ";
	}

	// maksimum:
	if (3*k < n) {
		cout << 2*k;
	} else {
		cout << n - k;
	}
}