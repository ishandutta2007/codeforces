#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, b, p;
	cin >> n >> b >> p;
	cout << 2 * (n - 1) * b + n - 1 << ' ' << n * p;


	return 0;
}