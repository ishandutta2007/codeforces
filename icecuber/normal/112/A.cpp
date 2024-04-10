#include <iostream>

using namespace std;

int cmp(char a, char b) {
	if ((a|32) > (b|32)) return 1;
	if ((a|32) < (b|32)) return -1;
	return 0;
}

int main() {
	string a, b;
	cin >> a >> b;
	int c;
	for (int i = 0; i < a.length(); i++) {
		c = cmp(a[i], b[i]);
		if (c) break;
	}
	cout << c << endl;
	return 0;
}