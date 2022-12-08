#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>

using namespace std;



int main() {
	set<int> a;
	int n, k;
	cin >> n >> k;
	vector<int> ans;
	int t = 0;
	for (int i = 0; i < n; i++) {
		if (ans.size() == k) break;
		cin >> t;
		if (a.find(t) == a.end()) {
			a.insert(t);
			ans.push_back(i + 1);
		}
	}
	if (ans.size() == k) {
		cout << "YES\n";
		for (int i = 0; i < k; i++) cout << ans[i] << " ";
	}
	else {
		cout << "NO\n";
	}
	//system("pause");
	return 0;
}