#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;



int main() {
	long long n;
	cin >> n;
	long long res = (n / 10000) * 10000 + ((n / 100) % 10) * 1000 + (n % 10) * 100 + ((n / 1000) % 10) + ((n / 10) % 10) * 10;
	long long ans = res;
	for (int i = 0; i < 4; i++) {
		res *= ans;
		res %= 100000;
	}
	if (res < 10000) { cout << 0; }
	if (res < 1000) { cout << 0; }
	if (res < 100) { cout << 0; }
	if (res < 10) { cout << 0; }
	cout << res;
	return 0;
}