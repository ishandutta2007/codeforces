#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
using namespace std;

int gcd(int a, int b) {
	int t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;

	for (int i=1; i<=n; i++) {
		if (i % 2 == 1 && i < n) {
			cout << "I hate that ";
		} else if (i % 2 == 1 && i == n) {
			cout << "I hate it";
		} else if (i % 2 == 0 && i < n) {
			cout << "I love that ";
		} else {
			cout << "I love it";
		}
	}

}