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

	if (n >= 0) {
		cout << n;
		return 0;
	}

	n *= -1;

	int a = n % 10;
	int b = n / 10 % 10;

	a = min(a, b);

	n = 10*(n / 100) + a;

	cout << -n;

}