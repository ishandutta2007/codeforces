#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	long long n;
	cin >> n;
		long long k = n;
		k -= n / 2 + n / 3 + n / 5 + n / 7;
		k += n / 6 + n / 10 + n / 14 + n / 15+ n / 21 + n / 35;
		k -= n / 30 + n / 42 + n / 70 + n / 105;
		k += n / 210;
		cout << k;
	return 0;
}