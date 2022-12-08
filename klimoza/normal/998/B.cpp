#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <cmath>

using namespace std;



int main() {
	int n, b;
	cin >> n >> b;
	vector<int> a(n);
	cin >> a[0];
	int balance = -1;
	if (a[0] % 2 == 0) {
		balance = 1;
	}
	vector<int> ans;
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 0) {
			balance++;
		}
		else {
			balance--;
		}
		if ((balance == 1 and a[i] % 2 == 0) or (balance == -1 and a[i] % 2 == 1)) {
			ans.push_back(abs(a[i] - a[i - 1]));
		}
	}
	sort(ans.begin(), ans.end());
	int ind = 0;
	int q = 0;
	while (b > 0 and ind < ans.size()) {
		if (ans[ind] <= b) {
			b -= ans[ind];
			q++;
		}
		else {
			break;
		}
		ind++;
	}
	cout << q << "\n";
	//system("pause");
	return 0;
}