#include <iostream>
#include <algorithm>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
	long double n, t;
	cin >> n >> t;
	cout << setprecision(9) << n * pow(1.000000011, t);

	return 0;
}