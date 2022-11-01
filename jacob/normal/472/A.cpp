#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	for (int x = 4; true; x += 2) {
		if ((n - x) % 3 == 0) {
			cout << x << " " << n - x << endl;
			return 0;
		}
	}
	return 1;
}