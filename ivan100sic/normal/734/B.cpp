#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int a[4];
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	long long s = 0;
	for (int i=0; i<=5000000; i++) {
		if (i <= a[0] && i <= a[1]) {
			int c256 = min(a[0]-i, min(a[2], a[3]));
			if (c256 < 0) continue;

			s = max(s, 32ll*i + 256ll*c256);

		}
	}
	cout << s;
}