#include <iostream>
using namespace std;

int main(void) {
	long long l, r;
	cin >> l >> r;
	long long u = 1;
	while (10*u <= r) u*=10;
	if (l < u)
		l = u;
	long long best = (u*10 - 1) / 2;
	if (best > r)
		best = r;
	if (best < l)
		best = l;
	cout << best * (u*10 -1 - best) << endl;
	return 0;
}