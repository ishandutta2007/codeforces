#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <cmath>

using namespace std;



int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	set<int> b;
	vector<int> ans;
	for (int i = n - 1; i >= 0; i--) {
		if (b.find(a[i]) == b.end()) {
			b.insert(a[i]);
			ans.push_back(a[i]);
		}
	}
	cout << ans.size() << "\n";
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << " ";
	}
	//system("pause");
	return 0;
}