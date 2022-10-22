#include <iostream>

using namespace std;

int main() {
	int a, b, c, d, n;
	cin >> a >> b >> c >> d >> n;
	int r = 0;
	for (int i = 1; i <= n; i++) {
		if (i%a == 0 or i%b == 0 or i%c == 0 or i%d == 0) r++;
	}
	cout << r << endl;
	return 0;
}