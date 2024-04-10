#include <iostream>
#include <string>
using namespace std;

bool pq(int x) {
	for (int i=2; i*i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	if (n == 2) {
		cout << 1;
		return 0;
	}
	if (n == 3) {
		cout << 1;
		return 0;
	}
	if (n == 4) {
		cout << 2;
		return 0;
	}
	if (n % 2 == 0) {
		cout << 2;
		return 0;
	}
	// ako je n prost ili n-2 prost
	if (pq(n)) {
		cout << 1;
		return 0;
	}

	if (pq(n-2)) {
		cout << 2;
		return 0;
	}

	cout << 3;
}