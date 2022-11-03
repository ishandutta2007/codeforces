#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a = 0;
	int b;
	for (int i = 0; i < n; i++) {
		cin >> b;
		a = a | b;
	}
	int c = 0;
	for (int i = 0; i < n; i++) {
		cin >> b;
		c = c | b;
	}
	cout << a + c;
	return 0;
}