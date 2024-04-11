#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;



int main() {
	long long x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	long long k;
	if (((x2 - x1) % 2 + (y2 - y1) % 2) % 2 == 0) {
		k = (x2 - x1) / 2;
		k = ((y2 - y1) / 2 + 1) * (k + 1) + (y2 - y1) / 2 * k;
	}
	else {
		k = (x2 - x1) / 2;
		k = ((y2 - y1) / 2 + 1) * (k) + (y2 - y1) / 2 * (k + 1);
	}
	cout << k;
 	return 0;
}