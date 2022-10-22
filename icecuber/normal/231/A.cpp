#include <iostream>
using namespace std;
int main() {
	int t, d = 0;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a+b+c >= 2) d++;
	}
	cout << d << endl;
	return 0;
}