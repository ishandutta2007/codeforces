#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	bool check = 0;
	if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) { check = 1; }
	int is = 0;
	bool d = 1;
	while (d) {
		is++;
		if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) { is++; }
		n++;
		bool f = 0;
		if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) { f = 1; }
		if (is % 7 == 0 && f == check) { d = 0; }
	}
	cout << n;

	return 0;
}