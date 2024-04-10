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

	int a, b, n;
	cin >> a >> b >> n;

	while (1) {
		if (n < gcd(a, n)) {
			cout << 1;
			break;
		} else {
			n -= gcd(a, n);
		}

		if (n < gcd(b, n)) {
			cout << 0;
			break;
		} else {
			n -= gcd(b, n);
		}

	}


}