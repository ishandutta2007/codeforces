#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, a, c;

int main() {
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		c += x;
	}
	cout << (c ? "HARD\n" : "EASY\n");
}