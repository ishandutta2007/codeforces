#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	long long p, q, r, a, b, c, x;

	cin >> n >> p >> q >> r;

	cin >> x;
	a = p*x;
	b = a + q*x;
	c = b + r*x;

	for (int i=1; i<n; i++) {
		long long x;
		cin >> x;
		a = max(a, p*x);
		b = max(b, a+q*x);
		c = max(c, b+r*x);
	}
	cout << c;
}