#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;


typedef long long ll;

const ll INF = 1e18;

int main() {
	vector<int> pov(30, 1);
	for (int i = 1; i < 30; i++) {
		pov[i] = pov[i - 1] * 2;
	}
	int q;
	cout << "? 0 0" << endl;
	cin >> q;
	int a = 0;
	int b = 0;
	int t = 0;
	for (int i = 29; i >= 0; i--) {
		cout << "? " << a + pov[i] << " " << b + pov[i] << endl;
		cin >> t;
		if (q >= 0) {
			if (t >= 0) {
				cout << "? " << a << " " << b + pov[i] << endl;
				int f;
				cin >> f;
				if (f == 1) {
					a += pov[i];
					b += pov[i];
					q = t;
				}
			}
			else {
				a += pov[i];
				cout << "? " << a << " " << b << endl;
				cin >> q;
			}
		}
		else {
			if (t <= 0) {
				cout << "? " << a + pov[i] << " " << b << endl;
				int f;
				cin >> f;
				if (f == -1) {
					a += pov[i];
					b += pov[i];
					q = t;
				}
			}
			else {
				b += pov[i];
				cout << "? " << a << " " << b << endl;
				cin >> q;
			}
		}
	}
	cout << "! " << a << " " << b << endl;
	//system("pause");
	return 0;
}