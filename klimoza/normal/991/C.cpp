#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <cmath>

using namespace std;


int main() {
	long long int n;
	cin >> n;
	long long int l = 1;
	long long int r = n / 2 + 1;
	long long int h;
	long long int t1 = 0;
	long long int t2 = 0;
	while (r - l > 1) {
		long long int mid = (r + l) / 2;
		h = n;
		t1 = 0;
		t2 = 0;
		while (h > 0) {
			t1 += min(h, mid);
			h -= min(h, mid);
			t2 += floor(h / 10);
			h -= floor(h / 10);
		}
		if (t1 > t2) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	h = n;
	t1 = 0;
	t2 = 0;
	while (h > 0) {
		t1 += min(h, l);
		h -= min(h, l);
		t2 += floor(h / 10);
		h -= floor(h / 10);
	}
	if (t1 >= t2) {
		cout << l << "\n";
	}
	else {
		cout << r << "\n";
	}
	//system("pause");
	return 0;
}