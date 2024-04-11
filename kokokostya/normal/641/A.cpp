#include <iostream>
#include <vector>

using namespace std;

vector < int > a, col;

int main() {
	int n;
	cin >> n;
	a.resize(n);
	col.resize(n, 0);
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c == '>')
			a[i] = 1;
		else
			a[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		a[i] *= c;
	}
	int cur = 0;
	while (cur >= 0 && cur < n) {
		if (col[cur]) {
			cout << "INFINITE";
			return 0;
		}
		col[cur] = 1;
		cur += a[cur];
	}
	cout << "FINITE";
	return 0;
}