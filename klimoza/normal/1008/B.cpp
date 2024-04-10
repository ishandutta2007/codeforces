#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <cmath>

using namespace std;



int main() {
	int n;
	cin >> n;
	bool fl = true;
	int t1, t2;
	int last = 1000000000;
	int r = 0;
	for (int i = 0; i < n; i++) {
		cin >> t1 >> t2;
		r = max(t1, t2);
		if (r <= last) {
			last = r;
		}
		else if (t1 + t2 - r <= last) {
			last = t1 + t2 - r;
		}
		else {
			fl = false;
			break;
		}
	}
	if (fl) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
	//system("pause");
	return 0;
}