#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	int k =  (a + b + 500 * n) % n;
	if (k == 0) { k += n; }
	cout << k;

	return 0;
}