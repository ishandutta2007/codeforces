#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	int n = (int)a.length(), m = (int)b.length();
	vector<int> l(m), r(m);
	int j = 0;
	for (int i = 0; i < m; i++) {
		while (j != n && a[j] != b[i]) {
			j++;
		}
		if (j == n)
			l[i] = j;
		else {
			l[i] = j;
			j++;
		}
	}
	j = n - 1;
	for (int i = m - 1; i >= 0; i--) {
		while (j != -1 && a[j] != b[i]) {
			j--;
		}
		if (j == -1)
			r[i] = j;
		else {
			r[i] = j;
			j--;
		}
	}
	int lt = 0, rt = m;
	while (lt != rt) {
		int mid = (lt + rt) / 2;
		bool is = 0;
		for (int i = 0; i + mid + 1 < m; i++) {
			if (l[i] < r[i + mid + 1])
				is = 1;
		}
		if (mid == m || l[m - mid - 1] != n || r[mid] != -1)
			is = 1;
		if (is)
			rt = mid;
		else
			lt = mid + 1;
	}
	int mid = lt;
	if (mid == m) {
		cout << '-';
		return 0;
	}
	if (l[m - mid - 1] != n) {
		for (int i = 0; i < m - mid; i++) {
			cout << b[i];
		}
		return 0;
	}
	if (r[mid] != -1) {
		for (int i = mid; i < m; i++) {
			cout << b[i];
		}
		return 0;
	}
	string f = "", s = "";
	for (int i = 0; i + mid + 1 < m; i++) {
		if (l[i] < r[i + mid + 1]) {
			for (int j = 0; j <= i; j++)
				cout << b[j];
			for (int j = i + mid + 1; j < m; j++) {
				cout << b[j];
			}
			return 0;
		}
	}
	return 0;
}