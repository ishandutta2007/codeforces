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
	vector<int> ans;
	int last = -1;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t == 1 and last != -1) {
			ans.push_back(last);
		}
		last = t;
	}
	ans.push_back(last);
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	//system("pause");
	return 0;
}