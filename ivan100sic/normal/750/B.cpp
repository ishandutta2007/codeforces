#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, h = 10000;
	cin >> n;
	while (n--) {
		int x;
		string s;
		cin >> x >> s;

		if (h == 10000 || h == -10000) {
			if (s == "East" || s == "West") {
				cout << "NO";
				return 0;
			}
		}


		if (s == "North") {
			h += x;
		} else if (s == "South") {
			h -= x;
		}
		if (h > 10000 || h < -10000) {
			cout << "NO";
			return 0;
		}
	}
	if (h != 10000) {
		cout << "NO";
	} else {
		cout << "YES";
	}
}