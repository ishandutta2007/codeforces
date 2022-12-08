#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 1e9;

typedef long long ll;


int main() {
	int t;
	cin >> t;
	int n, x, y, d;
	for (int i = 0; i < t; i++) {
		cin >> n >> x >> y >> d;
		if (abs(y - x) % d == 0) {
			cout << abs(y - x) / d << endl;
		}
		else {
			int t1 = (n - x + d - 1) / d;
			int t2 = (x - 1 + d - 1) / d;
			if (((n - y) % d) == 0) {
				t1 += (n - y) / d;
			}
			else {
				t1 = -1;
			}
			if(((y - 1) % d) == 0) {
				t2 += (y - 1) / d;
			}
			else {
				t2 = -1;
			}
			if (t1 == -1 && t2 == -1) {
				cout << "-1\n";
			}
			else if (t1 == -1 || t2 == -1) {
				cout << max(t1, t2) << endl;
			}
			else {
				cout << min(t1, t2) << endl;
			}
		}
	}
	//system("pause");
	return 0;
}