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

	int n, l;
	int a[1005];

	cin >> n >> l;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);

	double d = max(a[0], l - a[n-1]);

	for (int i=1; i<n; i++) {
		d = max(d, (a[i] - a[i-1]) / 2.0);
	}

	cout.precision(15);
	cout << fixed << d;
}