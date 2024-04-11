#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int f = (n % k);
	cout << n + (k - f);

	return 0;
}