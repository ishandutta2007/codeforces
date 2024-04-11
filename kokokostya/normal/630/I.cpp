#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;



int main() {
	long long n;
	cin >> n;
	if (n == 3) { cout << 24; }
	else {
		long long k = 2 * 3 * pow(4, n - 3) + (n - 3) * 9 * pow(4, n-4);
		k *= 4;
		cout << k;
	}
 	return 0;
}