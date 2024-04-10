#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int m, s;
	cin >> m >> s;

	if (s == 0) {
		if (m == 1) {
			cout << "0 0";
		} else {
			cout << "-1 -1";
		}
		return 0;
	}

	if (s > 9*m) {
		// nope
		cout << "-1 -1";
		return 0;
	}

	// najmanji
	int t = s;
	for (int i=1; i<=m; i++) {
		if (i == 1) {
			int v = t-9*(m-i);
			if (v < 1) {
				cout << 1;
				t -= 1;
			} else {
				cout << v;
				t -= v;
			}
		} else {
			int v = t-9*(m-i);
			if (v < 0) {
				cout << 0;
			} else {
				cout << v;
				t -= v;
			}
		}
	}

	cout << ' ';

	// najveci
	t = s;
	for (int i=1; i<=m; i++) {
		int v = t;
		if (v <= 9) {
			cout << v;
			t -= v;
		} else {
			cout << 9;
			t -= 9;
		}
	}

}