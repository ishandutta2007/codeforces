#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	long long int n, m, k;
	cin >> n >> m >> k;
	if (k <= n - 1) {
		cout << 1 + k << " " << 1 << "\n";
	}
	else if (k <= n + m - 2) {
		cout << n << " " << k - n + 2 << "\n";
	}
	else {
		k = k - (n - 1) - (m - 1);
		//k = 4; 2, 0
		long long int t = k / (m - 1);
		long long int h = k % (m - 1);
		if (h == 0) {
			if (t % 2 == 0)
				cout << n - t << " " << m << "\n";
			else
				cout << n - t << " " << 2 << "\n";
		}
		else {
			if (t % 2 == 0)
				cout << n - 1 - t << " " << m - (h - 1) << "\n";
			else
				cout << n - 1 - t << " " << h + 1 << "\n";
		}
	}
	
	//system("pause");
	return 0;
}