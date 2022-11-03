#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	long long n;
	cin >> n;
	long long k = int(sqrt(2 * n)) - 1;
	while (k*(k + 1) < 2 * n) { k++; }
	k--;
	n -= ((k + 1) * k) / 2;
	cout << n;
	return 0;
}