#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;



int main() {
	long long n;
	cin >> n;
	int k = 0;
	n %= 360;
	if (n < -180) { n += 360; }
	if (n > 180) { n -= 360; }
	int mn = abs(n);
	n -= 90;
	if (n < -180) { n += 360; }
	if (abs(n) < mn) { mn = abs(n); k = 1; }
	n -= 90;
	if (n < -180) { n += 360; }
	if (abs(n) < mn) { mn = abs(n); k = 2; }
	n -= 90;
	if (n < -180) { n += 360; }
	if (abs(n) < mn) {
		mn = abs(n); k = 3;
	}
	cout << k;
 	return 0;
}