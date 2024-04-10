#include <iostream>

using namespace std;

int main() {
	int k, n;
	cin >> n >> k;
	int p, c = 0, a;
	for (int i = 0; i < k; i++) {
		cin >> p;
		if (p) c++;
	}
	for (int i = k; i < n; i++) {
		cin >> a;
		c += (a >= p and a);
	}
	cout << c << endl;
	return 0;
}