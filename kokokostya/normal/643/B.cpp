#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (n == 4 || (k < n + 1)) { cout << -1; return 0; }
	int f = 1;
	while (f == a || f == b || f == c || f == d) { f++; }
	cout << a << ' ' << c << ' ' <<  f << ' ' << d << ' ';
	for (int i = 1; i <= n; i++) {
		if (i != a && i != b && i != c && i != d && i!=f) { cout << i << ' '; }
	}
	cout << b << '\n';
	cout << c << ' ' << a << ' ' << f << ' ' << b << ' ';
	for (int i = n; i >= 1; i--) {
		if (i != a && i != b && i != c && i != d && i!= f) { cout << i << ' '; }
	}
	cout << d;

	return 0;
}