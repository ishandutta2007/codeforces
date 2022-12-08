#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>

using namespace std;


int main() {
	vector<int> t(6);
	int sum = 0;
	for (int i = 0; i < 6; i++) {
		cin >> t[i];
		sum += t[i];
	}
	sort(t.begin(), t.end());
	bool fl = false;
	if (sum % 2 == 1) {
		cout << "NO\n";
		return 0;
	}
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (j == i) continue;
			for (int k = 0; k < 6; k++) {
				if (k == i || k == j) continue;
				if (t[i] + t[j] + t[k] == sum / 2) {
					fl = true;
					break;
				}
			}
			if (fl) break;
		}
		if (fl)break;
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