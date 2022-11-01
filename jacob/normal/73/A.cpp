#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	long long x[3], k;
	cin >> x[0] >> x[1] >> x[2] >> k;
	sort(x, x+3);
	long long c[3];
	for (int i = 0; i < 3; i++) {
		c[i] = min(x[i] - 1, k / (3 - i));
		k -= c[i];
	}
	cout << (c[0] + 1) * (c[1] + 1) * (c[2] + 1);
	return 0;
}