#include <iostream>
#include <algorithm>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
	
	long long a, b, c;
	cin >> a >> b >> c;
	long double d = b * b - 4 * a * c + 0.000000001;
	long double x1 = (-b + sqrt(d)) / 2 / a;
		long double x2 = (-b - sqrt(d)) / 2 / a;
		if (a < 0) { swap(x1, x2); }
		cout << setprecision(9) << x1;
	cout << '\n';
	cout << setprecision(9) << x2;

	return 0;
}