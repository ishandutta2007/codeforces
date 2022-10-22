#include <iostream>
using namespace std;
int main() {
	int n, c = 0, m = 0;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		c += b-a;
		if (c > m) m = c;
	}
	cout << m << endl;
}