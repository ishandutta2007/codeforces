#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <cmath>

using namespace std;



int main() {
	int n;
	cin >> n;
	int cnt = n;
	int deg = 1;
	int t = 0;
	if (n == 1) {
		cout << 1 << "\n";
	}
	else if (n == 2) {
		cout << 1 << " " << 2 << "\n";
	}
	else if (n == 3) {
		cout << "1 1 3\n";
	}
	else {
		while (cnt > 0) {
			t = ceil((double)cnt / 2);
			if (cnt == 3) {
				cout << deg << " " << deg << " " << 3 * deg;
				cnt = 0;
			}
			else {
				for (int i = 0; i < t; i++) {
					cout << deg << " ";
				}
				cnt -= t;
				deg *= 2;
			}
		}
		cout << "\n";
	}
	//system("pause");
	return 0;
}