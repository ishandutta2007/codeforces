#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	long long n;
	cin >> n;
	long long k = pow(1ll * 2, n + 1) - 2;
	cout << k;
	return 0;
}