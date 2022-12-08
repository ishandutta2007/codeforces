#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <cmath>

using namespace std;

int n, m;
vector<string> a;

bool check(int i, int j) {
	if (i >= 0 && j >= 0 && i < n - 2 && j < m - 2) {
		if (a[i][j] == a[i][j + 1] && a[i][j + 1] == a[i][j + 2] && a[i][j + 2] == a[i + 1][j] && a[i + 1][j] == a[i + 1][j + 2] && a[i + 1][j + 2] == a[i + 2][j] && a[i + 2][j] == a[i + 2][j + 1] && a[i + 2][j + 1] == a[i + 2][j + 2] && a[i + 2][j + 2] == '#') {
			return true;
		}
	}
	return false;
}




int main() {
	cin >> n >> m;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	bool fl = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '#' && !(check(i, j) || check(i, j - 1) || check(i, j - 2) || check(i - 1, j) || check(i - 1, j - 2) || check(i - 2, j) || check(i - 2, j - 1) || check(i - 2, j - 2))) {
				fl = false;
				break;
			}
		}
		if (!fl) break;
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