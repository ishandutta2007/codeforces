#include <iostream>
using namespace std;

int main(void) {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	--a;
	if (a / m == (b - 1) / m) {
		cout << 1 << endl;
		return 0;
	}
	int ao = a % m;
	if (b == n) {
		b = ((n-1) / m)*m + m;
	}
	int bo = b % m;
	if (ao == 0 && bo == 0) {
		cout << 1 << endl;
		return 0;
	}
	if (ao == bo || bo == 0 || ao == 0) {
		cout << 2 << endl;
		return 0;
	}
	if ((b - 1)/m - a/m > 1) {
		cout << 3 << endl;
	} else
		cout << 2 << endl;
	return 0;
}