#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int h, m;
	char c;
	cin >> h >> c >> m;
	int a;
	cin >> a;
	m += a;
	h += m / 60;
	m %= 60;
	h %= 24;
	if (h < 10) { cout << 0; }
	cout << h << c;
	if (m < 10) { cout << 0; }
	cout << m;
	return 0;
}