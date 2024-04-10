#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a%b);
}

int main() {
	int a, b, n;
	cin >> a >> b >> n;
	while (1) {
		int g = gcd(a, n);
		if (g > n) {
			cout << "1\n";
			return 0;
		}
		n -= g;
		g = gcd(b, n);
		if (g > n) {
			cout << "0\n";
			return 0;
		}
		n -= g;
	}
	return 0;
}