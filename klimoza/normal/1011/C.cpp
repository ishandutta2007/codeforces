#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <cmath>

using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(n);
	bool fl = false;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 1) fl = true;
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		if (b[i] == 1) fl = true;
	}
	if (fl == true) {
		cout << "-1\n";
	}
	else {
		double x = (double)m / (double)(b[0] - 1);
		double flex = m + x;
		for (int i = n - 1; i > 0; i--) {
			x = flex / (double)(a[i] - 1);
			flex += x;
			x = flex / (double)(b[i] - 1);
			flex += x;
		}
		x = flex / (double)(a[0] - 1);
		flex += x;
		flex -= m;
		printf("%.10lf\n", flex);
	}
	//system("pause");
	return 0;
}