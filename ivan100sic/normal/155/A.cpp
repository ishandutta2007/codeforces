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

	int n, x, c=0;
	cin >> n >> x;
	int lo = x, hi = x;
	for (int i=1; i<n; i++) {
		int y;
		cin >> y;
		if (y > hi) {
			hi = y;
			c++;
		}
		if (y < lo) {
			lo = y;
			c++;
		}
	}

	cout << c;

}