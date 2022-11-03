#include <iostream>
#include <algorithm>
#include <math.h>
#include <iomanip>

using namespace std;



int main() {
	long double l1, l2, l3;
	long double const pi = 3.1415926535897932384626;
	cin >> l1 >> l2 >> l3;
	long double ans = 0;
	ans +=  sqrt(2) / 12 * l1 *l1 * l1;
	ans += sqrt(2) / 6 * l2 *l2 * l2;
	long double l = cos((72.0 / 180.0)*pi);
	long double k = 1 / (2 * (1 - l));
	ans += sqrt(1 - k) * 5 / 12 * cos(pi / 5) / sin(pi / 5) * l3 * l3 * l3;
	cout << setprecision(12) << ans;
 	return 0;
}