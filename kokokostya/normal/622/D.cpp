#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	cout << n << ' ';
	int k = n % 2;
	for (int i = 2; i < n; i += 2) {
		cout << i - k << ' ';
	}
	cout << n << ' ';
	for (int i = n - 2; i > 0; i -= 2) {
		cout << i << ' ';
	}
	for (int i = 1; i < n; i += 2) {
		cout << i + k << ' ';
	}
	for (int i = n - 1; i > 0; i -= 2) {
		cout << i << ' ';
	}

	return 0;
}