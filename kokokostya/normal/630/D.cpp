#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	long long n;
	cin >> n;
	long long k = 3 * n *  (n + 1) + 1;
	cout << k;
	return 0;
}