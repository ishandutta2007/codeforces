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

	long long n, k;
	cin >> n >> k;

	if (n % 2 == 0) {
		if (k <= n / 2) {
			cout << 2*k-1;
		} else {
			cout << 2*(k - n/2);
		}
	} else {
		if (k <= n / 2 + 1) {
			cout << 2*k-1;
		} else {
			cout << 2*(k - n/2 - 1);
		}
	}

}