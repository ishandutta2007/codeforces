#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <cmath>

using namespace std;


int main() {
	int m, n;
	cin >> m >> n;
	vector<int> ans(n);
	bool fl = false;
	for (int i = 0; i < n; i++) {
		cout << 1 << "\n";
		fflush(stdout);
		cin >> ans[i];
		if (ans[i] == 0) {
			fl = true;
			break;
		}
	}
	int ind = 0;
	int t = 0;
	if (!fl) {
		int l = 1;
		int r = m + 1;
		while (true) {
			int mid = (l + r) / 2;
			cout << mid << "\n";
			fflush(stdout);
			cin >> t;
			t *= ans[ind];
			if (t == -1) {
				r = mid;
			}
			else if (t == 1) {
				l = mid + 1;
			}
			else {
				break;
			}
			ind++;
			ind %= n;
		}
	}
	//system("pause");
	return 0;
}