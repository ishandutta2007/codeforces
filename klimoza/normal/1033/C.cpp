#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <cmath>

using namespace std;


int n;
vector<int> a;
vector<int> win;



void check(int x) {
	bool fl = false;
	for (int i = x - a[x]; i >= 0; i -= a[x]) {
		if (a[i] < a[x]) continue;
		if (win[i] == 0) check(i);
		if (win[i] == -1) {
			fl = true;
			break;
		}
	}
	if (!fl) {
		for (int i = x + a[x]; i < n; i += a[x]) {
			if (a[i] < a[x]) continue;
			if (win[i] == 0) check(i);
			if (win[i] == -1) {
				fl = true;
				break;
			}
		}
	}
	if (fl) {
		win[x] = 1;
	}
	else {
		win[x] = -1;
	}
}



int main() {
	cin >> n;
	a.resize(n);
	win.assign(n, 0);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		if (win[i] == 0) {
			check(i);
		}
	}
	for (int i = 0; i < n; i++) {
		if (win[i] == 1) {
			cout << "A";
		}
		else {
			cout << "B";
		}
	}
	//system("pause");
	return 0;
}