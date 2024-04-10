#include <iostream>

using namespace std;

int main() {
	int a, b, c = 0, r = 0;
	cin >> a >> b;
	while (a) {
		a--;
		r++;
		if (r==b) {
			a++;
			r = 0;
		}
		c++;
	}
	cout << c << endl;
	return 0;
}